#ifndef WEATHERINFO_H
#define WEATHERINFO_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QUrl>
#include <QUrlQuery>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>

class WeatherInfo:public QObject
{
    Q_OBJECT
public:
    WeatherInfo();

    void getWeatherInfo();

    // 返回参数
    bool status;    // 返回状态-1:成功，0:失败
    size_t count;   // 返回结果总数目
    QString info;   // 返回的状态信息
    int infocode;    // 返回状态说明,10000表示正确
    QString province;   // 省份名
    QString city;   // 城市名
    int adcode;  // 区域编码
    QString weather;    // 天气现象
    int temperature;    // 实时气温，摄氏度
    QString winddirection;  // 风向
    QString windpower;  // 风力级别
    int humidity;   // 空气湿度
    QString reporttime; //数据发布时间

signals:
    void getWeatherFinished();

private:

    QNetworkAccessManager manager;
    QUrl url;
    QNetworkRequest request;
    QNetworkReply *reply;

    QJsonDocument jsonDocument;



    // 解析收到的Json数据
    void analysisJson();
};

#endif // WEATHERINFO_H
