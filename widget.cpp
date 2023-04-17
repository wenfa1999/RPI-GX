#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    ,secondCounts(0)
    ,temAxisXMin(0)
    ,temAxisXMax(5)
    ,temAxisYMin(29)
    ,temAxisYMax(30)
    ,humAxisXMin(0)
    ,humAxisXMax(5)
    ,humAxisYMin(60)
    ,humAxisYMax(61)
    ,tmpAxisXIndex(0)
    ,humAxisXIndex(0)
    ,lightState(0)
    ,hasMqttClient(false)
    ,settingsWidget(new GXSettings(this))
{
    ui->setupUi(this);

    // 初始化服务端监听端口
    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any, 12000);

    // 初始化mqtt
    mqttInit();
    // 初始化rootJson
    rootJsonInit();

    ui->label_iconMqtt->setVisible(false);
    ui->list_rfid->setSelectionMode(QAbstractItemView::NoSelection);
    ui->list_rfid->setDragEnabled(true);
    ui->list_rfid->setDragDropMode(QAbstractItemView::DragDrop);
    ui->list_rfid->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

    // 窗口属性-全屏、置顶
    this->setWindowFlag(Qt::WindowStaysOnTopHint);
//    this->setWindowFlag(Qt::FramelessWindowHint);
//    this->showFullScreen();

    // 定时器初始化
    m_process = new QProcess(this);
    m_timerUpdateTimer = new QTimer(this);
    m_timerUpdateTimer->start(1000);
    m_chartUpdateTimer = new QTimer(this);
    m_chartUpdateTimer->start(2000);
    m_updateMqttStatusTimer = new QTimer(this);

    // 模块阴影效果
    setShadowEffect(ui->widget_LED);
    setShadowEffect(ui->widget_RFID);
    setShadowEffect(ui->widget_time);
    setShadowEffect(ui->widget_weather);
    //        setShadowEffect(ui->widget);
    setShadowEffect(ui->widget_tmp);
    setShadowEffect(ui->widget_hum);
    setShadowEffect(ui->widget_settings);

    // 更新时间
    updateTime();

    // 初始化图表
    chartsInit();

    // 收到连接
    connect(tcpServer, &QTcpServer::newConnection, this, [&](){
        qDebug() << "new connection";
        clientSocket = tcpServer->nextPendingConnection();
        qDebug() << "收到来自" << clientSocket->peerAddress() << clientSocket->peerPort() << "的连接";
        /**
         * 白卡：43 7A 58 95
         * 钥匙卡：FB 59 05 4B
         * 饭卡：7A C2 0F 2F（手机NFC）
         */
        QByteArrayList accessId({"437a5895", "fb59054b"});
        connect(clientSocket, &QTcpSocket::readyRead, this, [=](){
            QByteArray data = clientSocket->readAll();
            qDebug() << "收到:" << data;
            if (data.contains("hello"))
            {
                qDebug() << "收到欢迎语";
            }
            else if (data.contains("restart")){}
            else
            {

                qDebug() << "收到卡号：" << data.toHex().left(8);

                QByteArray carId = data.toHex().left(8);
                QString itemStr = QDateTime::currentDateTime().toString("yyyy年M月d日") +
                        "  " + QDateTime::currentDateTime().toString("hh:mm:ss")+
                        "\t" + carId;
                QListWidgetItem *item = new QListWidgetItem(itemStr);
                if (accessId.contains(carId))
                {
                    qDebug() << "主人访问:" << data.toHex().left(8);
                }
                else
                {
                    qDebug() << "陌生人访问" << data.toHex().left(8);
                    QColor color(192, 72, 81);  // 玉红
                    item->setForeground(QBrush(color));
                }
                ui->list_rfid->addItem(item);
                ui->list_rfid->scrollToBottom();
                QJsonObject statusObj = rootJson["status"].toObject();
                QJsonObject arrayObject;
                arrayObject.insert("message", itemStr);
                QJsonArray rfidArray = statusObj["rfid"].toArray();
                rfidArray.append(arrayObject);
                statusObj["rfid"] = rfidArray;
                rootJson["status"] = statusObj;

            }

        });

    });
    /// GXSettings
    // 更新地点
    connect(this->settingsWidget, &GXSettings::adcodeUpdated, this, [&](QString adacode){
        qDebug() << adacode;
        this->weatherInfo.setAdacode(adacode);
        weatherInfo.getWeatherInfo();
    });
    // 回复默认
    connect(this->settingsWidget, &GXSettings::setDefault, this, [&](){
        this->weatherInfo.setAdacode(settingsWidget->getAdcode());
        weatherInfo.getWeatherInfo();
    });


    // 定时器更新时间
    connect(m_timerUpdateTimer, &QTimer::timeout, this, &Widget::updateTime);
    // 定时器更新温湿度
    connect(m_chartUpdateTimer, &QTimer::timeout, this, &Widget::updateCharts);
    // 定时器检查是否无客户端连接
    connect(m_updateMqttStatusTimer, &QTimer::timeout, this, [&](){
        if (hasMqttClient)
        {
            mqttSend();
        }
        else
        {
            m_updateMqttStatusTimer->stop();
            qDebug() << "连接停止";
        }
    });

    // 刷新按钮
    connect(ui->pushButton, &QPushButton::clicked, this, [&](){
        weatherInfo.getWeatherInfo();
        if (QMqttClient::Disconnected == m_client->state())
        {
            m_client->connectToHost();
        }
    });

    // 设置按钮
    connect(ui->button_settings, &QPushButton::clicked, this, &Widget::showSettings);

    // 收到消息
    connect(m_client, &QMqttClient::messageReceived, this, &Widget::mqttReceive);
    // 失去连接
    connect(m_client, &QMqttClient::disconnected, this, [&](){
        qDebug() << "mqtt断开连接";
        ui->label_iconMqtt->hide();
    });

    // 获取天气

    weatherInfo.getWeatherInfo();
    connect(&weatherInfo, &WeatherInfo::getWeatherFinished, this, [&](){
        ui->label_city->setText(weatherInfo.province + " / " + weatherInfo.city);
        ui->label_weather->setText("天气 : " + weatherInfo.weather);
        ui->label_temperature->setText("温度 : " + QString::number(weatherInfo.temperature)+"℃");
        ui->label_winddirection->setText("风向 : " + weatherInfo.winddirection);
        ui->label_windpower->setText("风力 : " + weatherInfo.windpower+"级");
        ui->label_humidity->setText("相对湿度 : " + QString::number(weatherInfo.humidity) + "%");
        QString updateTime = "<html><head/><body><p><span style=\" color:#5e5c64; vertical-align:sub;\">数据更新于: ";
        updateTime.append(weatherInfo.reporttime);
        updateTime+="</span></p></body></html>";
        ui->label_weatherUpdateTime->setText(updateTime);

        /// 设置图标
        /*
         * sunshine(晴)
         * lesscloud(少) 少云
         * cloudy(多) 晴间多云 多云
         * overcast(阴) 阴
         * gale(风) 有风清风强风劲风疾风大风烈风风暴狂爆风飓风热带风暴微风和风
         * fog(雾、尘)浮尘扬沙沙尘暴强沙尘暴龙卷风雾浓雾强浓雾轻雾大雾特强浓雾
         * smog(霾)霾中度霾重度霾严重霾
         * rain(雨) 阵雨雷阵雨雷阵雨并伴有冰雹小雨中雨大雨暴雨大暴雨特大暴雨强阵雨雷阵极端降雨毛毛雨/细雨雨小雨-中雨中雨-大雨大雨-暴雨暴雨-大暴雨大暴雨-特大暴
         * rainsnow(雨&雪)雨雪天气雨夹雪阵雨夹雪
         * snowice(冻雨)
         * snow(雪) 雪
         * hot(热)
         * cold(冷)
         * unknown(未知)平静
         */
        QString iconName;
        if (weatherInfo.weather.contains("晴")) iconName="sunshine";
        else if (weatherInfo.weather.contains("少")) iconName="lesscloud";
        else if (weatherInfo.weather.contains("多")) iconName="cloudy";
        else if (weatherInfo.weather.contains("阴")) iconName="overcast";
        else if (weatherInfo.weather.contains("风")) iconName="gale";
        else if (weatherInfo.weather.contains("雾") || weatherInfo.weather.contains("尘") ) iconName="fog";
        else if (weatherInfo.weather.contains("霾")) iconName="smog";
        else if (weatherInfo.weather.contains("雨")) iconName="rain";
        else if (weatherInfo.weather.contains("雨") && weatherInfo.weather.contains("雪")) iconName="rainsnow";
        else if (weatherInfo.weather.contains("冻雨")) iconName="snowice";
        else if (weatherInfo.weather.contains("雪")) iconName="snow";
        else if (weatherInfo.weather.contains("热")) iconName="hot";
        else if (weatherInfo.weather.contains("冷")) iconName="cold";
        else if (weatherInfo.weather.contains("未知")) iconName="unknown";

        QString styleSheet("image: url(:/weatherIcon/imgs/weatherIcon/"+iconName+".svg)");
        ui->icon_weather->setStyleSheet(styleSheet);

        QJsonObject weatherInfoObj = rootJson["weatherInfo"].toObject();
        weatherInfoObj["local"] = weatherInfo.province + " / " + weatherInfo.city;
        weatherInfoObj["weather"] = weatherInfo.weather;
        weatherInfoObj["tmpWeather"] = weatherInfo.temperature;
        weatherInfoObj["humWeather"] = weatherInfo.humidity;
        weatherInfoObj["windDirect"] = weatherInfo.winddirection;
        weatherInfoObj["windPower"] = weatherInfo.windpower;
        weatherInfoObj["reportTime"] = weatherInfo.reporttime;
        this->rootJson["weatherInfo"] = weatherInfoObj;
    });


    // DHT11退出
    connect(m_process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            [=](int exitCode, QProcess::ExitStatus exitStatus)
    {
        Q_UNUSED(exitCode)
        Q_UNUSED(exitStatus)
        //        qDebug() << "Exit with: " << exitCode << exitStatus;
    });

    // 点灯
    connect(ui->button_light, &QPushButton::clicked, this, &Widget::turnLight);
}

Widget::~Widget()
{
    delete ui;
}

/**
 * @brief 更新时间
 */
void Widget::updateTime()
{
    // 计算过去了多少个周期(1s一个周期)，3600即为1小时，刷新一次天气
    if (++secondCounts == 3600)
    {
        weatherInfo.getWeatherInfo();
        secondCounts = 0;
    }

    ui->label_date->setText(QDateTime::currentDateTime().toString("yyyy年M月d日\ndddd"));
    QString time = QDateTime::currentDateTime().toString("hh:mm:ss\n");
    // 2-6 半夜 6-11-上午 11-14中午 14-18-下午 18-22-晚上 22-2夜间

    int hour = QDateTime::currentDateTime().time().hour();
    if (hour >2 && hour <= 6) ui->label_greetings->setText(time+"半夜好");
    else if (hour >6 && hour <= 11) ui->label_greetings->setText(time+"上午好");
    else if (hour >11 && hour <= 14) ui->label_greetings->setText(time+"中午好");
    else if (hour >14 && hour <= 18) ui->label_greetings->setText(time+"下午好");
    else if (hour >18 && hour <= 22) ui->label_greetings->setText(time+"晚上好");
    else if (hour >22 && hour <= 24) ui->label_greetings->setText(time+"夜间好");
    else if (hour >=0 && hour <= 2) ui->label_greetings->setText(time+"夜间好");
}


/**
 * @brief Widget::chartsInit 图表初始化
 */
void Widget::chartsInit()
{
    // 坐标
    axisXTmp = new QValueAxis();
    axisYTmp = new QValueAxis();
    axisXTmp->setMin(temAxisXMin);
    axisXTmp->setMax(temAxisXMax);
    axisYTmp->setMin(temAxisYMin);
    axisYTmp->setMax(temAxisYMax);
    axisXTmp->setTickCount(6);
    //    axisXTmp->setLabelFormat("%d");

    axisXHum = new QValueAxis();
    axisYHum = new QValueAxis();
    axisXHum->setMin(humAxisXMin);
    axisXHum->setMax(humAxisXMax);
    axisYHum->setMin(humAxisYMin);
    axisYHum->setMax(humAxisYMax);
    axisXHum->setTickCount(6);
    //    axisXHum->setLabelFormat("%d");
    // 曲线
    seriesTmp = new QSplineSeries();
    seriesTmp->setName("温度");
    //    seriesTmp->setPointLabelsVisible(true);
    //    seriesTmp->setPointsVisible(true);

    seriesHum = new QSplineSeries();
    seriesHum->setName("湿度");
    //    seriesHum->setPointLabelsVisible(true);
    //    seriesHum->setPointsVisible(true);
    /// 图表
    // 温度
    chartForTmp = new QChart();
    chartForTmp->addAxis(axisXTmp, Qt::AlignBottom);
    chartForTmp->addAxis(axisYTmp, Qt::AlignLeft);
    chartForTmp->setTheme(QChart::ChartThemeQt);
    chartForTmp->setAnimationOptions(QChart::SeriesAnimations);
    chartForTmp->setTitle("温度变化曲线");
    chartForTmp->addSeries(seriesTmp);
    chartForTmp->legend()->hide();
    // 湿度
    chartForHum = new QChart();
    chartForHum->addAxis(axisXHum, Qt::AlignBottom);
    chartForHum->addAxis(axisYHum, Qt::AlignLeft);
    chartForHum->setTheme(QChart::ChartThemeLight);
    chartForHum->setAnimationOptions(QChart::SeriesAnimations);
    chartForHum->setTitle("相对湿度变化曲线");
    chartForHum->addSeries(seriesHum);
    chartForHum->legend()->hide();
    // Widget
    ui->widget_chartsTmp->setChart(chartForTmp);
    ui->widget_chartsTmp->setRenderHint(QPainter::Antialiasing);
    ui->widget_chartsHmp->setChart(chartForHum);
    ui->widget_chartsHmp->setRenderHint(QPainter::Antialiasing);
    /// 添加坐标轴
    // 温度
    seriesTmp->attachAxis(axisXTmp);
    seriesTmp->attachAxis(axisYTmp);
    // 湿度
    seriesHum->attachAxis(axisXHum);
    seriesHum->attachAxis(axisYHum);
}

/**
 * @brief Widget::updateCharts 更新温湿度图表
 */
void Widget::updateCharts()
{
    QFile file("/home/gwf/dht11.txt");
    file.open(QIODevice::ReadOnly);
    if (!file.isOpen())
    {
        qDebug() << "Open failed!";
        return ;
    }
    // 从文件获取数据
    QByteArray fileData = file.readAll().simplified();
    file.close();
    auto list = fileData.split(' ');
    // 温度
    seriesTmp->append(tmpAxisXIndex++, list.at(1).toDouble());
    ui->label_currentTmp->setText("当前室内温度: "+list.at(1)+"℃");
    // 湿度
    seriesHum->append(humAxisXIndex++, list.at(0).toDouble());
    ui->label_currentHum->setText("当前室内相对湿度: " + list.at(0) + "%");
    // x轴缩放
    if (tmpAxisXIndex > temAxisXMax)
    {
        temAxisXMax = tmpAxisXIndex+4;
    }
    if (humAxisXIndex > humAxisXMax)
    {
        humAxisXMax = humAxisXIndex+4;
    }
    /// y轴缩放
    // 温度
    if (temAxisYMin > list.at(1).toDouble()-1)
    {
        temAxisYMin = (int)list.at(1).toDouble() - 1;
    }

    if(temAxisYMax < list.at(1).toDouble()+1)
    {
        temAxisYMax = (int)list.at(1).toDouble() + 1;
    }
    // 湿度
    if (humAxisYMin > list.at(0).toDouble()-1)
    {
        humAxisYMin = (int)list.at(0).toDouble() - 1;
    }

    if(humAxisYMax < list.at(0).toDouble()+1)
    {
        humAxisYMax = (int)list.at(0).toDouble() + 1;
    }

    if(tmpAxisXIndex > 200)
    {
        seriesTmp->clear();
        seriesHum->clear();

        temAxisXMin=0;
        temAxisXMax=5;
        temAxisYMin=29;
        temAxisYMax=30;
        humAxisXMin=0;
        humAxisXMax=5;
        humAxisYMin=60;
        humAxisYMax=61;
        tmpAxisXIndex=0;
        humAxisXIndex=0;
    }

    axisXTmp->setMin(temAxisXMin);
    axisXTmp->setMax(temAxisXMax);
    axisYTmp->setMin(temAxisYMin);
    axisYTmp->setMax(temAxisYMax);

    axisXHum->setMin(humAxisXMin);
    axisXHum->setMax(humAxisXMax);
    axisYHum->setMin(humAxisYMin);
    axisYHum->setMax(humAxisYMax);

    chartForTmp->update();
    chartForTmp->update();

    QJsonObject statusObj = rootJson["status"].toObject();
    statusObj["tmp"] = list.at(1).toDouble();
    statusObj["hum"] = list.at(0).toDouble();
    this->rootJson["status"] = statusObj;
}

/**
 * @brief Widget::setShadowEffect 给Widget添加阴影
 * @param widget 添加阴影的对象
 */
void Widget::setShadowEffect(QWidget *widget)
{

    QGraphicsDropShadowEffect * effect = new QGraphicsDropShadowEffect(ui->widget_LED);
    effect->setOffset(5, 5);//设置阴影距离
    effect->setColor(QColor(0,0,0,90));//设置阴影颜色
    effect->setBlurRadius(7);//设置阴影圆角
    widget->setStyleSheet(".QWidget{background-color:#FFFFFF;border-radius:6px;}");
    widget->setGraphicsEffect(effect);

}

/**
 * @brief Widget::turnLight
 * @param state 开灯:1,关灯:2.切换状态:3
 */
void Widget::turnLight(int state)
{
    QStringList args;
    if (1 == state) { lightState = 0; }
    else if (2 == state) { lightState =  1; }
    if (lightState == 0)
    {
        lightState = 1;
        args << "write" << "1" << "1";
        ui->button_light->setStyleSheet("image: url(:/imgs/imgs/lights_on.svg);\
                                        border:none;");
    }
    else
    {
        lightState = 0;
        args << "write" << "1" << "0";
        ui->button_light->setStyleSheet("image: url(:/imgs/imgs/lights_off.svg);\
                                        border:none;");
    }
    m_process->start("gpio", args);
    m_process->waitForFinished();
    m_process->close();

    QJsonObject statusObj = rootJson["status"].toObject();
    statusObj["LED"] = lightState == 1 ? "on" : "off";
    this->rootJson["status"] = statusObj;

    mqttSend();
}

/**
 * @brief Widget::mqttInit mqtt客户端初始化
 */
void Widget::mqttInit()
{
    m_client = new QMqttClient(this);
//    m_client->setHostname("1.117.198.232");
    m_client->setHostname("mqtt.gwf.icu");
    m_client->setPort(1883);
    m_client->setClientId("rpi");
    m_client->connectToHost();

    connect(m_client, &QMqttClient::connected, this, [&](){
        qDebug() << "连接MQTT服务器成功";
        m_client->subscribe(QString("GX/miniProgram"));
        m_client->subscribe(QString("GX/windows"));
        m_client->subscribe(QString("GX/linux"));
        ui->label_iconMqtt->setVisible(true);
    });

    connect(m_client, &QMqttClient::disconnected, this, [&](){
        qDebug() << "MQTT连接已断开";
        ui->label_iconMqtt->setVisible(false);
    });
}

/**
 * @brief Widget::mqttReceive 从mqtt接收数据
 * @param message 数据
 * @param topic 主题名称
 */
void Widget::mqttReceive(const QByteArray &message, const QMqttTopicName &topic)
{
    Q_UNUSED(topic)

    QJsonDocument jsonDocument = QJsonDocument::fromJson(message);

    //    qDebug() << "Reveice:" << jsonDocument;

    QString ledStatus;  // 开关灯

    QJsonObject jsonObj = jsonDocument.object();
    QString command = jsonObj["command"].toString();
    //    qDebug() << "Command: " << command;
    if ("control" == command)
    {
        ledStatus = jsonObj["LED"].toString();
        //        qDebug() << "LED:" << ledStatus;
    }
    else if ("ack" == command)
    {
        hasMqttClient = true;   // 继续向服务器发送数据
        //        qDebug() << "收到ack";
    }
    else if ("get" == command)
    {
        mqttSend();
    }

    if ("on" == ledStatus)
    {
        turnLight(1);
    }
    else if ("off" == ledStatus)
    {
        turnLight(2);
    }
}

/**
 * @brief Widget::rootJsonInit 初始化RootJson用于发送
 */
void Widget::rootJsonInit()
{
    QJsonObject statusObj;
    statusObj.insert("tmp", 31);
    statusObj.insert("hum", 68);
    statusObj.insert("LED", "off");
    statusObj.insert("rfid", QJsonArray());
    QJsonObject weatherInfoObj;
    weatherInfoObj.insert("local", "广东 / 茂名");
    weatherInfoObj.insert("weather", "雨天");
    weatherInfoObj.insert("tmpWeather", 23);
    weatherInfoObj.insert("humWeather", 46);
    weatherInfoObj.insert("windDirect", "西北");
    weatherInfoObj.insert("windPower", "4");
    weatherInfoObj.insert("reportTime", "1999-11-19 23:23:23");

    this->rootJson.insert("command", "report");
    this->rootJson.insert("status", statusObj);
    this->rootJson.insert("weatherInfo", weatherInfoObj);
}

/**
 * @brief Widget::mqttSend 通过client发送数据到mqtt服务器
 */
void Widget::mqttSend()
{
    /***********************************
        enum ClientState {
        Disconnected = 0,
        Connecting,
        Connected
    };
    ************************************/
    // 断开了就重新连接
    if (QMqttClient::Disconnected == m_client->state())
    {
        m_client->connectToHost();
    }

    //    qDebug() << "RootJson: " << rootJson;
    QJsonDocument document(rootJson);
    m_client->publish(QString("GX/rpi"), document.toJson());
    m_updateMqttStatusTimer->start(5000);
    hasMqttClient = false;
}

/**
 * @brief Widget::showSettings 打开设置弹窗
 */
void Widget::showSettings()
{
    qDebug() << "设置";
//    QWidget *settingWidget = new QWidget(this);
//    settingWidget->setParent(this);
//    settingWidget->setWindowModality(Qt::WindowModal);
//    settingWidget->resize(400,320);
//    settingWidget->setWindowFlags(settingWidget->windowFlags() | Qt::Window| Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);


//    settingWidget->show();


//    QDialog *dlg = new QDialog(this);
//    dlg->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
//    dlg->resize(400, 320);

//    dlg->exec();

//    settingsWidget->setWindowFlags( Qt::Dialog| Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
//    settingsWidget->resize(400, 320);
    settingsWidget->setWindowModality(Qt::WindowModal);
    settingsWidget->show();


}

