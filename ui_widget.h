/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget_LED;
    QVBoxLayout *verticalLayout_8;
    QPushButton *button_light;
    QLabel *label_9;
    QWidget *widget_RFID;
    QVBoxLayout *verticalLayout_9;
    QListWidget *list_rfid;
    QLabel *label_11;
    QWidget *widget_TEMHUM;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_tmp;
    QVBoxLayout *verticalLayout_5;
    QChartView *widget_chartsTmp;
    QLabel *label_currentTmp;
    QWidget *widget_hum;
    QVBoxLayout *verticalLayout_6;
    QChartView *widget_chartsHmp;
    QLabel *label_currentHum;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_time;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_date;
    QLabel *label_greetings;
    QLabel *label_iconMqtt;
    QWidget *widget_weather;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *icon_local;
    QLabel *label_city;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *icon_weather;
    QLabel *label_weather;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *icon_tem;
    QLabel *label_temperature;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *icon_hum;
    QLabel *label_humidity;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *icon_windDirect;
    QLabel *label_winddirection;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_7;
    QLabel *icon_windPower;
    QLabel *label_windpower;
    QLabel *label_weatherUpdateTime;
    QPushButton *pushButton;
    QWidget *widget_settings;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *button_settings;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1024, 600);
        Widget->setStyleSheet(QString::fromUtf8("#Widget{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(132, 250, 176, 255), stop:1 rgba(143, 211, 244, 255));\n"
"}"));
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget_6 = new QWidget(Widget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout_7 = new QVBoxLayout(widget_6);
        verticalLayout_7->setSpacing(30);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        widget_LED = new QWidget(widget_6);
        widget_LED->setObjectName(QString::fromUtf8("widget_LED"));
        verticalLayout_8 = new QVBoxLayout(widget_LED);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        button_light = new QPushButton(widget_LED);
        button_light->setObjectName(QString::fromUtf8("button_light"));
        button_light->setMinimumSize(QSize(300, 300));
        button_light->setStyleSheet(QString::fromUtf8("image: url(:/imgs/imgs/lights_off.svg);\n"
"border:none;"));

        verticalLayout_8->addWidget(button_light);

        label_9 = new QLabel(widget_LED);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_9);

        verticalLayout_8->setStretch(0, 1);

        verticalLayout_7->addWidget(widget_LED);

        widget_RFID = new QWidget(widget_6);
        widget_RFID->setObjectName(QString::fromUtf8("widget_RFID"));
        verticalLayout_9 = new QVBoxLayout(widget_RFID);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        list_rfid = new QListWidget(widget_RFID);
        list_rfid->setObjectName(QString::fromUtf8("list_rfid"));

        verticalLayout_9->addWidget(list_rfid);

        label_11 = new QLabel(widget_RFID);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_11);

        verticalLayout_9->setStretch(0, 1);

        verticalLayout_7->addWidget(widget_RFID);

        verticalLayout_7->setStretch(0, 1);
        verticalLayout_7->setStretch(1, 1);

        horizontalLayout->addWidget(widget_6);

        widget_TEMHUM = new QWidget(Widget);
        widget_TEMHUM->setObjectName(QString::fromUtf8("widget_TEMHUM"));
        verticalLayout_4 = new QVBoxLayout(widget_TEMHUM);
        verticalLayout_4->setSpacing(30);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_tmp = new QWidget(widget_TEMHUM);
        widget_tmp->setObjectName(QString::fromUtf8("widget_tmp"));
        verticalLayout_5 = new QVBoxLayout(widget_tmp);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        widget_chartsTmp = new QChartView(widget_tmp);
        widget_chartsTmp->setObjectName(QString::fromUtf8("widget_chartsTmp"));
        widget_chartsTmp->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));

        verticalLayout_5->addWidget(widget_chartsTmp);

        label_currentTmp = new QLabel(widget_tmp);
        label_currentTmp->setObjectName(QString::fromUtf8("label_currentTmp"));
        label_currentTmp->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_currentTmp);


        verticalLayout_4->addWidget(widget_tmp);

        widget_hum = new QWidget(widget_TEMHUM);
        widget_hum->setObjectName(QString::fromUtf8("widget_hum"));
        verticalLayout_6 = new QVBoxLayout(widget_hum);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        widget_chartsHmp = new QChartView(widget_hum);
        widget_chartsHmp->setObjectName(QString::fromUtf8("widget_chartsHmp"));
        widget_chartsHmp->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));

        verticalLayout_6->addWidget(widget_chartsHmp);

        label_currentHum = new QLabel(widget_hum);
        label_currentHum->setObjectName(QString::fromUtf8("label_currentHum"));
        label_currentHum->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_currentHum);


        verticalLayout_4->addWidget(widget_hum);


        horizontalLayout->addWidget(widget_TEMHUM);

        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(30);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_time = new QWidget(widget);
        widget_time->setObjectName(QString::fromUtf8("widget_time"));
        widget_time->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(widget_time);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_date = new QLabel(widget_time);
        label_date->setObjectName(QString::fromUtf8("label_date"));
        label_date->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_3->addWidget(label_date);

        label_greetings = new QLabel(widget_time);
        label_greetings->setObjectName(QString::fromUtf8("label_greetings"));
        label_greetings->setStyleSheet(QString::fromUtf8(""));
        label_greetings->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_3->addWidget(label_greetings);

        label_iconMqtt = new QLabel(widget_time);
        label_iconMqtt->setObjectName(QString::fromUtf8("label_iconMqtt"));
        label_iconMqtt->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_iconMqtt->sizePolicy().hasHeightForWidth());
        label_iconMqtt->setSizePolicy(sizePolicy);
        label_iconMqtt->setStyleSheet(QString::fromUtf8("image: url(:/imgs/imgs/logo.png);"));
        label_iconMqtt->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_iconMqtt);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 1);

        verticalLayout->addWidget(widget_time);

        widget_weather = new QWidget(widget);
        widget_weather->setObjectName(QString::fromUtf8("widget_weather"));
        widget_weather->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(widget_weather);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(9, -1, -1, -1);
        widget_2 = new QWidget(widget_weather);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        icon_local = new QLabel(widget_2);
        icon_local->setObjectName(QString::fromUtf8("icon_local"));
        icon_local->setMinimumSize(QSize(15, 15));
        icon_local->setMaximumSize(QSize(15, 30));
        icon_local->setStyleSheet(QString::fromUtf8("image: url(:/imgs/imgs/local.svg);"));

        horizontalLayout_2->addWidget(icon_local);

        label_city = new QLabel(widget_2);
        label_city->setObjectName(QString::fromUtf8("label_city"));
        label_city->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_city);

        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(widget_weather);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        icon_weather = new QLabel(widget_3);
        icon_weather->setObjectName(QString::fromUtf8("icon_weather"));
        icon_weather->setMinimumSize(QSize(15, 15));
        icon_weather->setMaximumSize(QSize(15, 30));
        icon_weather->setStyleSheet(QString::fromUtf8("image: url(:/weatherIcon/imgs/weatherIcon/unknown.svg);"));

        horizontalLayout_3->addWidget(icon_weather);

        label_weather = new QLabel(widget_3);
        label_weather->setObjectName(QString::fromUtf8("label_weather"));
        label_weather->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_weather);

        horizontalLayout_3->setStretch(1, 1);

        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(widget_weather);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        icon_tem = new QLabel(widget_4);
        icon_tem->setObjectName(QString::fromUtf8("icon_tem"));
        icon_tem->setMinimumSize(QSize(15, 15));
        icon_tem->setMaximumSize(QSize(15, 30));
        icon_tem->setStyleSheet(QString::fromUtf8("image: url(:/imgs/imgs/tmp_blue.svg);"));

        horizontalLayout_4->addWidget(icon_tem);

        label_temperature = new QLabel(widget_4);
        label_temperature->setObjectName(QString::fromUtf8("label_temperature"));
        label_temperature->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_temperature);

        horizontalLayout_4->setStretch(1, 1);

        verticalLayout_2->addWidget(widget_4);

        widget_5 = new QWidget(widget_weather);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        icon_hum = new QLabel(widget_5);
        icon_hum->setObjectName(QString::fromUtf8("icon_hum"));
        icon_hum->setMinimumSize(QSize(15, 15));
        icon_hum->setMaximumSize(QSize(15, 30));
        icon_hum->setStyleSheet(QString::fromUtf8("image: url(:/imgs/imgs/hum_blue.svg);"));

        horizontalLayout_5->addWidget(icon_hum);

        label_humidity = new QLabel(widget_5);
        label_humidity->setObjectName(QString::fromUtf8("label_humidity"));
        label_humidity->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_humidity);

        horizontalLayout_5->setStretch(1, 1);

        verticalLayout_2->addWidget(widget_5);

        widget_8 = new QWidget(widget_weather);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setMinimumSize(QSize(15, 0));
        horizontalLayout_6 = new QHBoxLayout(widget_8);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        icon_windDirect = new QLabel(widget_8);
        icon_windDirect->setObjectName(QString::fromUtf8("icon_windDirect"));
        icon_windDirect->setMinimumSize(QSize(15, 15));
        icon_windDirect->setMaximumSize(QSize(15, 30));
        icon_windDirect->setStyleSheet(QString::fromUtf8("image: url(:/imgs/imgs/windDIrect_blue.svg);"));

        horizontalLayout_6->addWidget(icon_windDirect);

        label_winddirection = new QLabel(widget_8);
        label_winddirection->setObjectName(QString::fromUtf8("label_winddirection"));
        label_winddirection->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_winddirection);

        horizontalLayout_6->setStretch(1, 1);

        verticalLayout_2->addWidget(widget_8);

        widget_9 = new QWidget(widget_weather);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_7 = new QHBoxLayout(widget_9);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        icon_windPower = new QLabel(widget_9);
        icon_windPower->setObjectName(QString::fromUtf8("icon_windPower"));
        icon_windPower->setMinimumSize(QSize(15, 15));
        icon_windPower->setMaximumSize(QSize(15, 30));
        icon_windPower->setStyleSheet(QString::fromUtf8("image: url(:/imgs/imgs/windPower_blue.svg);"));

        horizontalLayout_7->addWidget(icon_windPower);

        label_windpower = new QLabel(widget_9);
        label_windpower->setObjectName(QString::fromUtf8("label_windpower"));
        label_windpower->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_windpower);

        horizontalLayout_7->setStretch(1, 1);

        verticalLayout_2->addWidget(widget_9);

        label_weatherUpdateTime = new QLabel(widget_weather);
        label_weatherUpdateTime->setObjectName(QString::fromUtf8("label_weatherUpdateTime"));
        label_weatherUpdateTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_weatherUpdateTime);

        pushButton = new QPushButton(widget_weather);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("image: url(:/imgs/imgs/sync.svg);\n"
"border:none;"));
        pushButton->setCheckable(false);
        pushButton->setAutoDefault(false);
        pushButton->setFlat(false);

        verticalLayout_2->addWidget(pushButton);


        verticalLayout->addWidget(widget_weather);

        widget_settings = new QWidget(widget);
        widget_settings->setObjectName(QString::fromUtf8("widget_settings"));
        horizontalLayout_8 = new QHBoxLayout(widget_settings);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        button_settings = new QPushButton(widget_settings);
        button_settings->setObjectName(QString::fromUtf8("button_settings"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(button_settings->sizePolicy().hasHeightForWidth());
        button_settings->setSizePolicy(sizePolicy1);
        button_settings->setStyleSheet(QString::fromUtf8("border:none;\n"
"image: url(:/imgs/imgs/settings.svg);"));

        horizontalLayout_8->addWidget(button_settings);


        verticalLayout->addWidget(widget_settings);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 3);
        verticalLayout->setStretch(2, 1);

        horizontalLayout->addWidget(widget);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 1);

        retranslateUi(Widget);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        button_light->setText(QString());
        label_9->setText(QCoreApplication::translate("Widget", "\347\224\265\347\201\257", nullptr));
        label_11->setText(QCoreApplication::translate("Widget", "\351\227\250\347\246\201", nullptr));
        label_currentTmp->setText(QCoreApplication::translate("Widget", "\345\275\223\345\211\215\345\256\244\345\206\205\346\270\251\345\272\246: 27\342\204\203", nullptr));
        label_currentHum->setText(QCoreApplication::translate("Widget", "\345\275\223\345\211\215\345\256\244\345\206\205\347\233\270\345\257\271\346\271\277\345\272\246: 46%", nullptr));
        label_date->setText(QCoreApplication::translate("Widget", "2022\345\271\2642\346\234\21026\346\227\245\n"
"\346\230\237\346\234\237\346\227\245", nullptr));
        label_greetings->setText(QCoreApplication::translate("Widget", "12:02:30\n"
"\346\227\251\344\270\212\345\245\275", nullptr));
        label_iconMqtt->setText(QString());
        icon_local->setText(QString());
        label_city->setText(QCoreApplication::translate("Widget", "\345\271\277\344\270\234 / \347\225\252\347\246\272\345\214\272", nullptr));
        icon_weather->setText(QString());
        label_weather->setText(QCoreApplication::translate("Widget", "\345\244\251\346\260\224 : ", nullptr));
        icon_tem->setText(QString());
        label_temperature->setText(QCoreApplication::translate("Widget", "\346\270\251\345\272\246 : ", nullptr));
        icon_hum->setText(QString());
        label_humidity->setText(QCoreApplication::translate("Widget", "\347\233\270\345\257\271\346\271\277\345\272\246 : ", nullptr));
        icon_windDirect->setText(QString());
        label_winddirection->setText(QCoreApplication::translate("Widget", "\351\243\216\345\220\221 : ", nullptr));
        icon_windPower->setText(QString());
        label_windpower->setText(QCoreApplication::translate("Widget", "\351\243\216\345\212\233 : ", nullptr));
        label_weatherUpdateTime->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" color:#5e5c64; vertical-align:sub;\">\346\225\260\346\215\256\346\233\264\346\226\260\344\272\216: 2023-04-10 23:52:20</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        pushButton->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButton->setText(QString());
        button_settings->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
