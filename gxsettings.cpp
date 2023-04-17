#include "gxsettings.h"
#include "ui_gxsettings.h"

#include <QDebug>

GXSettings::GXSettings(QWidget *parent)
    : QWidget{parent}
    , ui(new Ui::Form)
    , adcode("440113")
    , tmpAdcode(adcode)
    , local("广东 / 番禺区")
    , tmpLocal(local)
    , ifSetDefault(false)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog| Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground); // 设置透明背景

    connect(ui->button_updateLocal, &QPushButton::clicked, this, [&](){
        url = ("https://restapi.amap.com/v3/ip?key=ff30e395d99db14fa5c4de3bfe2156a5");
        request.setUrl(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        reply = manager.get(request);

        connect(reply, &QNetworkReply::finished, this, [&](){
            QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
            QJsonObject object = document.object();
//            qDebug() << object;
            this->tmpAdcode = object["adcode"].toString();
//            qDebug() << "adcode:" << adcode;
            tmpLocal = object["province"].toString() + " / " + object["city"].toString();
            ui->label_currentLocal->setText(tmpLocal);
        });

        ui->button_default->setEnabled(true);
    });

    connect(ui->button_default, &QPushButton::clicked, this, [&](){
        ui->button_default->setEnabled(false);
        ui->label_currentLocal->setText("广东 / 番禺区");
        this->tmpAdcode = "440113";
        ifSetDefault = true;
    });

    connect(ui->button_cancel, &QPushButton::clicked, this, [&](){
        this->tmpAdcode = this->adcode;
        this->tmpLocal = this->local;
        qDebug () << "local:" << local;
        ui->label_currentLocal->setText(local);
\
        ui->button_default->setEnabled(true);
        ifSetDefault = false;
        this->hide();
    });
    connect(ui->button_confirm, &QPushButton::clicked, this, [&](){
        this->adcode = this->tmpAdcode;
        this->local = this->tmpLocal;
        ui->label_currentLocal->setText(local);
        if (ifSetDefault) emit setDefault();
        emit adcodeUpdated(this->adcode);

        ui->button_default->setEnabled(true);
        ifSetDefault = false;
        this->hide();
    });
}

QString GXSettings::getAdcode() const
{
    return adcode;
}
