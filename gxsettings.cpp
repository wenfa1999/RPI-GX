#include "gxsettings.h"
#include "ui_gxsettings.h"

#include <QDebug>

GXSettings::GXSettings(QWidget *parent)
    : QWidget{parent}
    , ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog| Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

    connect(ui->button_default, &QPushButton::clicked, this, [&](){
        url = ("https://restapi.amap.com/v3/ip?key=ff30e395d99db14fa5c4de3bfe2156a5");
        request.setUrl(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        reply = manager.get(request);

        connect(reply, &QNetworkReply::finished, this, [&](){
            QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
            QJsonObject object = document.object();
            qDebug() << object;
            this->adcode = object["adcode"].toString();
            qDebug() << "adcode:" << adcode;
        });
    });
}

QString GXSettings::getAdcode() const
{
    return adcode;
}

void GXSettings::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mousePressEvent";
}

void GXSettings::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "mouseReleaseEvent";
}

void GXSettings::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "mouseMoveEvent";
}
