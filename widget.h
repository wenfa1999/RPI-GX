#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUrl>
#include <QUrlQuery>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>
#include <QPushButton>
#include <QLabel>
#include <QProcess>
#include <QTime>
#include <QTimer>
#include <QDateTime>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QtCharts/QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QByteArray>
#include <QValueAxis>
#include <QtMqtt/QMqttClient>
#include <QTcpSocket>
#include <QTcpServer>
#include <QListWidget>
#include <QDialog>

#include "weatherinfo.h"
#include "gxsettings.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


private:
    Ui::Widget *ui;

    WeatherInfo weatherInfo;
    QProcess *m_process;
    QTimer *m_timerUpdateTimer; // 更新时间
    QTimer *m_chartUpdateTimer; // 更新温湿度图表
    size_t secondCounts;  // 计算过去了多少个周期(1s一个周期)，3600即为1小时，刷新一次天气

    double temAxisXMin;
    double temAxisXMax;
    double temAxisYMin;
    double temAxisYMax;
    double humAxisXMin;
    double humAxisXMax;
    double humAxisYMin;
    double humAxisYMax;

    size_t tmpAxisXIndex;
    size_t humAxisXIndex;

    QChart *chartForTmp;
    QChart *chartForHum;
    QSplineSeries *seriesTmp;  // 温度曲线
    QSplineSeries *seriesHum;   // 湿度曲线
    QValueAxis *axisXTmp;
    QValueAxis *axisYTmp;
    QValueAxis *axisXHum;
    QValueAxis *axisYHum;

    QByteArray procData;
    int newProcData;

    int lightState;
    //    QWidget *settingWidget = new QWidget(this);
    //    settingWidget->setParent(this);
    //    settingWidget->setWindowModality(Qt::WindowModal);
    //    settingWidget->resize(400,320);
    //    settingWidget->setWindowFlags(settingWidget->windowFlags() | Qt::Window| Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    void updateTime(void);
    void chartsInit(void);  // 初始化图表
    void updateCharts(void);    // 更新图表
    void setShadowEffect(QWidget *widget);
    void turnLight(int state=3);   // 点灯

    void mqttInit(void);
    void mqttReceive(const QByteArray &message, const QMqttTopicName &topic); // 从mqtt接收数据

    QMqttClient *m_client;
    bool hasMqttClient;
    QJsonObject rootJson;
    QTimer *m_updateMqttStatusTimer;

    void rootJsonInit(void);
    void mqttSend(void);

    QTcpServer *tcpServer;
    QTcpSocket *clientSocket;

    void showSettings(void);
    GXSettings *settingsWidget;
};
#endif // WIDGET_H
