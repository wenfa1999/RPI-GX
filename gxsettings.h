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


QT_BEGIN_NAMESPACE
namespace Ui { class Form; }
QT_END_NAMESPACE

class GXSettings : public QWidget
{
    Q_OBJECT
public:
    explicit GXSettings(QWidget *parent = nullptr);

    QString getAdcode() const;

signals:

private:
    Ui::Form *ui;

    QNetworkAccessManager manager;
    QUrl url;
    QNetworkRequest request;
    QNetworkReply *reply;

    QString adcode;

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
};

#endif // GXSETTINGS_H
