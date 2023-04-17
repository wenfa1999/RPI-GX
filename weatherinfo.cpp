#include "weatherinfo.h"

WeatherInfo::WeatherInfo()
{
    url = "https://restapi.amap.com/v3/weather/weatherInfo?key=cae79ec076b4f851b0937ded621b1026&city=440113";
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    reply = manager.get(request);
}

void WeatherInfo::getWeatherInfo()
{
    reply = manager.get(request);
    connect(reply, &QNetworkReply::finished, this, [&](){
        if (reply->error() == QNetworkReply::NoError)
        {
            QByteArray data = reply->readAll();

            jsonDocument = QJsonDocument::fromJson(data);

            //            qDebug() << jsonDocument;
            analysisJson();
            emit getWeatherFinished();
        }
        else
        {
            qDebug() << "weather reply error";
        }
    });
}

void WeatherInfo::setAdacode(QString adacode)
{
    url = "https://restapi.amap.com/v3/weather/weatherInfo?key=cae79ec076b4f851b0937ded621b1026&city=" + adacode;
    request.setUrl(url);
}


//bool status;    // 返回状态-1:成功，0:失败
//size_t count;   // 返回结果总数目
//QString info;   // 返回的状态信息
//int infocode;    // 返回状态说明,10000表示正确
//QString province;   // 省份名
//QString city;   // 城市名
//int adcode;  // 区域编码
//QString weather;    // 天气现象
//int temperature;    // 实时气温，摄氏度
//QString winddirection;  // 风向
//QString windpower;  // 风力级别
//int humidity;   // 空气湿度
//QString reporttime; //数据发布时间

// 解析收到的Json数据
void WeatherInfo::analysisJson()
{
    QJsonObject object = jsonDocument.object();

    if (object.contains("count"))
    { // count
        this->count = object["count"].toString().toInt();
    }
    if (object.contains("info"))
    { // info
        this->info = object["info"].toString();
    }
    if (object.contains("infocode"))
    { // infocode
        this->infocode = object["infoCode"].toString().toInt();
    }
    if (object.contains("lives"))
    { // lives
        QJsonArray livesArray = object.take("lives").toArray();
        auto i = livesArray.at(0);
        QJsonObject livesObject = i.toObject();

        if (livesObject.contains("adcode"))
        { // 邮编
            this->adcode = livesObject["adcode"].toString().toInt();
//            qDebug() << this->adcode;
        }
        if (livesObject.contains("city"))
        { // 城市
            this->city = livesObject["city"].toString();
//            qDebug() << this->city;
        }
        if (livesObject.contains("humidity"))
        { // 湿度
            this->humidity = livesObject["humidity"].toString().toInt();
//            qDebug() << this->humidity;
        }
        if (livesObject.contains("province"))
        { // 省份
            this->province = livesObject["province"].toString();
//            qDebug() << this->province;
        }
        if (livesObject.contains("reporttime"))
        { // 报告时间
            this->reporttime = livesObject["reporttime"].toString();
//            qDebug() << this->reporttime;
        }
        if (livesObject.contains("temperature"))
        { // 温度
            this->temperature = livesObject["temperature"].toString().toInt();
//            qDebug() << this->temperature;
        }
        if (livesObject.contains("weather"))
        { // 天气
            this->weather = livesObject["weather"].toString();
//            qDebug() << this->weather;
        }
        if (livesObject.contains("winddirection"))
        { // 风向
            this->winddirection = livesObject["winddirection"].toString();
//            qDebug() << this->winddirection;
        }
        if (livesObject.contains("windpower"))
        { // 风力
            this->windpower = livesObject["windpower"].toString();
//            qDebug() << this->windpower;
        }

    }
}
