#ifndef GXSETTINGS_H
#define GXSETTINGS_H

#include <QWidget>
#include <QPushButton>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QGraphicsDropShadowEffect>


QT_BEGIN_NAMESPACE
namespace Ui { class Form; }
QT_END_NAMESPACE

class GXSettings : public QWidget
{
    Q_OBJECT
public:
    explicit GXSettings(QWidget *parent = nullptr);

    QString getAdcode() const;
    void addRfidDone();
    void removeRfidDone(void);

signals:
    void adcodeUpdated(QString adcode);
    void setDefault(void);

    void addRfid();
    void removeRfid();
private:
    Ui::Form *ui;

    QNetworkAccessManager manager;
    QUrl url;
    QNetworkRequest request;
    QNetworkReply *reply;

    QString adcode;
    QString tmpAdcode;
    QString local;
    QString tmpLocal;
    bool ifSetDefault;


};

#endif // GXSETTINGS_H
