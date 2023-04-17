/********************************************************************************
** Form generated from reading UI file 'gxsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GXSETTINGS_H
#define UI_GXSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_4;
    QLabel *label_2;
    QGroupBox *groupBox;
    QLabel *label_6;
    QPushButton *button_updateLocal;
    QLabel *label_currentLocal;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_default;
    QPushButton *button_cancel;
    QPushButton *button_confirm;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(768, 400);
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(Form);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_4 = new QVBoxLayout(widget_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_5);


        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_5 = new QGroupBox(widget_3);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout = new QGridLayout(groupBox_5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit = new QLineEdit(groupBox_5);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label = new QLabel(groupBox_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox_5);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox_5);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 0, 3, 1, 1);

        lineEdit_4 = new QLineEdit(groupBox_5);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 1, 3, 1, 1);

        label_2 = new QLabel(groupBox_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);


        verticalLayout_3->addWidget(groupBox_5);

        groupBox = new QGroupBox(widget_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 70, 67, 17));
        button_updateLocal = new QPushButton(groupBox);
        button_updateLocal->setObjectName(QString::fromUtf8("button_updateLocal"));
        button_updateLocal->setGeometry(QRect(370, 60, 89, 25));
        label_currentLocal = new QLabel(groupBox);
        label_currentLocal->setObjectName(QString::fromUtf8("label_currentLocal"));
        label_currentLocal->setGeometry(QRect(140, 70, 67, 17));

        verticalLayout_3->addWidget(groupBox);


        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        button_default = new QPushButton(widget_4);
        button_default->setObjectName(QString::fromUtf8("button_default"));

        horizontalLayout->addWidget(button_default);

        button_cancel = new QPushButton(widget_4);
        button_cancel->setObjectName(QString::fromUtf8("button_cancel"));

        horizontalLayout->addWidget(button_cancel);

        button_confirm = new QPushButton(widget_4);
        button_confirm->setObjectName(QString::fromUtf8("button_confirm"));

        horizontalLayout->addWidget(button_confirm);


        verticalLayout_2->addWidget(widget_4);

        verticalLayout_2->setStretch(1, 4);

        verticalLayout->addWidget(widget);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label_5->setText(QCoreApplication::translate("Form", "\350\256\276\347\275\256", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("Form", "Mqtt", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("Form", "Mqtt\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "\350\264\246\345\217\267\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("Form", "\345\234\260\345\235\200\357\274\232", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("Form", "\345\217\257\351\200\211", nullptr));
        label_4->setText(QCoreApplication::translate("Form", " \345\257\206\347\240\201\357\274\232", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("Form", "Mqtt\347\253\257\345\217\243\345\217\267(1883)", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("Form", "\345\217\257\351\200\211", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "\347\253\257\345\217\243\357\274\232", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Form", "\346\234\254\345\234\260\350\256\276\347\275\256", nullptr));
        label_6->setText(QCoreApplication::translate("Form", "\345\275\223\345\211\215\345\234\260\345\235\200\357\274\232", nullptr));
        button_updateLocal->setText(QCoreApplication::translate("Form", "\346\233\264\346\226\260\345\234\260\345\235\200", nullptr));
        label_currentLocal->setText(QString());
        button_default->setText(QCoreApplication::translate("Form", "\346\201\242\345\244\215\351\273\230\350\256\244\350\256\276\347\275\256", nullptr));
        button_cancel->setText(QCoreApplication::translate("Form", "\345\217\226\346\266\210", nullptr));
        button_confirm->setText(QCoreApplication::translate("Form", "\347\241\256\345\256\232 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GXSETTINGS_H
