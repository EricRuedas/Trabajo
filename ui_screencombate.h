/********************************************************************************
** Form generated from reading UI file 'screencombate.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENCOMBATE_H
#define UI_SCREENCOMBATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ScreenCombate
{
public:
    QPushButton *fusion1;
    QLabel *mensaje1;
    QCommandLinkButton *Salir;
    QComboBox *comboBoxu1;
    QProgressBar *barrapoder1;
    QPushButton *cambiar1;
    QProgressBar *barravida1;
    QLabel *picpersonaje1;
    QPushButton *usar1;
    QComboBox *comboBoxf1;
    QProgressBar *barrapoder2;
    QLabel *picpersonaje2;
    QPushButton *fusion2;
    QComboBox *comboBoxu2;
    QComboBox *comboBoxf2;
    QProgressBar *barravida2;
    QPushButton *cambiar2;
    QPushButton *usar2;
    QComboBox *comboBoxc1;
    QComboBox *comboBoxc2;
    QLabel *picfondo;
    QProgressBar *fusionbarra;
    QProgressBar *fusionbarra2;
    QLabel *fusiontext1;
    QLabel *fusiontext2;

    void setupUi(QDialog *ScreenCombate)
    {
        if (ScreenCombate->objectName().isEmpty())
            ScreenCombate->setObjectName(QStringLiteral("ScreenCombate"));
        ScreenCombate->resize(1014, 630);
        fusion1 = new QPushButton(ScreenCombate);
        fusion1->setObjectName(QStringLiteral("fusion1"));
        fusion1->setGeometry(QRect(40, 490, 121, 41));
        mensaje1 = new QLabel(ScreenCombate);
        mensaje1->setObjectName(QStringLiteral("mensaje1"));
        mensaje1->setGeometry(QRect(340, 430, 401, 31));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        mensaje1->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Nirmala UI Semilight"));
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        mensaje1->setFont(font);
        Salir = new QCommandLinkButton(ScreenCombate);
        Salir->setObjectName(QStringLiteral("Salir"));
        Salir->setGeometry(QRect(50, 560, 71, 41));
        comboBoxu1 = new QComboBox(ScreenCombate);
        comboBoxu1->setObjectName(QStringLiteral("comboBoxu1"));
        comboBoxu1->setGeometry(QRect(320, 530, 121, 22));
        barrapoder1 = new QProgressBar(ScreenCombate);
        barrapoder1->setObjectName(QStringLiteral("barrapoder1"));
        barrapoder1->setGeometry(QRect(210, 10, 81, 23));
        barrapoder1->setMaximum(10);
        barrapoder1->setValue(5);
        cambiar1 = new QPushButton(ScreenCombate);
        cambiar1->setObjectName(QStringLiteral("cambiar1"));
        cambiar1->setGeometry(QRect(180, 490, 121, 41));
        barravida1 = new QProgressBar(ScreenCombate);
        barravida1->setObjectName(QStringLiteral("barravida1"));
        barravida1->setGeometry(QRect(40, 10, 151, 23));
        barravida1->setStyleSheet(QStringLiteral(""));
        barravida1->setMaximum(100);
        barravida1->setValue(50);
        picpersonaje1 = new QLabel(ScreenCombate);
        picpersonaje1->setObjectName(QStringLiteral("picpersonaje1"));
        picpersonaje1->setGeometry(QRect(60, 80, 331, 331));
        usar1 = new QPushButton(ScreenCombate);
        usar1->setObjectName(QStringLiteral("usar1"));
        usar1->setGeometry(QRect(320, 490, 121, 41));
        comboBoxf1 = new QComboBox(ScreenCombate);
        comboBoxf1->setObjectName(QStringLiteral("comboBoxf1"));
        comboBoxf1->setGeometry(QRect(40, 530, 121, 22));
        barrapoder2 = new QProgressBar(ScreenCombate);
        barrapoder2->setObjectName(QStringLiteral("barrapoder2"));
        barrapoder2->setGeometry(QRect(720, 10, 81, 23));
        barrapoder2->setMaximum(10);
        barrapoder2->setValue(5);
        picpersonaje2 = new QLabel(ScreenCombate);
        picpersonaje2->setObjectName(QStringLiteral("picpersonaje2"));
        picpersonaje2->setGeometry(QRect(640, 70, 301, 331));
        fusion2 = new QPushButton(ScreenCombate);
        fusion2->setObjectName(QStringLiteral("fusion2"));
        fusion2->setGeometry(QRect(840, 490, 121, 41));
        comboBoxu2 = new QComboBox(ScreenCombate);
        comboBoxu2->setObjectName(QStringLiteral("comboBoxu2"));
        comboBoxu2->setGeometry(QRect(560, 530, 121, 22));
        comboBoxf2 = new QComboBox(ScreenCombate);
        comboBoxf2->setObjectName(QStringLiteral("comboBoxf2"));
        comboBoxf2->setGeometry(QRect(840, 530, 121, 22));
        barravida2 = new QProgressBar(ScreenCombate);
        barravida2->setObjectName(QStringLiteral("barravida2"));
        barravida2->setGeometry(QRect(820, 10, 151, 23));
        barravida2->setMaximum(100);
        barravida2->setValue(50);
        cambiar2 = new QPushButton(ScreenCombate);
        cambiar2->setObjectName(QStringLiteral("cambiar2"));
        cambiar2->setGeometry(QRect(700, 490, 121, 41));
        usar2 = new QPushButton(ScreenCombate);
        usar2->setObjectName(QStringLiteral("usar2"));
        usar2->setGeometry(QRect(560, 490, 121, 41));
        comboBoxc1 = new QComboBox(ScreenCombate);
        comboBoxc1->setObjectName(QStringLiteral("comboBoxc1"));
        comboBoxc1->setGeometry(QRect(180, 530, 121, 22));
        comboBoxc2 = new QComboBox(ScreenCombate);
        comboBoxc2->setObjectName(QStringLiteral("comboBoxc2"));
        comboBoxc2->setGeometry(QRect(700, 530, 121, 22));
        picfondo = new QLabel(ScreenCombate);
        picfondo->setObjectName(QStringLiteral("picfondo"));
        picfondo->setGeometry(QRect(20, -10, 1014, 630));
        fusionbarra = new QProgressBar(ScreenCombate);
        fusionbarra->setObjectName(QStringLiteral("fusionbarra"));
        fusionbarra->setGeometry(QRect(320, 10, 91, 23));
        fusionbarra->setMaximum(3);
        fusionbarra->setValue(0);
        fusionbarra->setTextVisible(false);
        fusionbarra2 = new QProgressBar(ScreenCombate);
        fusionbarra2->setObjectName(QStringLiteral("fusionbarra2"));
        fusionbarra2->setGeometry(QRect(590, 10, 91, 23));
        fusionbarra2->setMaximum(3);
        fusionbarra2->setValue(0);
        fusionbarra2->setTextVisible(false);
        fusiontext1 = new QLabel(ScreenCombate);
        fusiontext1->setObjectName(QStringLiteral("fusiontext1"));
        fusiontext1->setGeometry(QRect(300, 40, 141, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("HoloLens MDL2 Assets"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        fusiontext1->setFont(font1);
        fusiontext2 = new QLabel(ScreenCombate);
        fusiontext2->setObjectName(QStringLiteral("fusiontext2"));
        fusiontext2->setGeometry(QRect(560, 40, 141, 21));
        fusiontext2->setFont(font1);
        picfondo->raise();
        fusion1->raise();
        mensaje1->raise();
        Salir->raise();
        comboBoxu1->raise();
        barrapoder1->raise();
        cambiar1->raise();
        barravida1->raise();
        picpersonaje1->raise();
        usar1->raise();
        comboBoxf1->raise();
        barrapoder2->raise();
        picpersonaje2->raise();
        fusion2->raise();
        comboBoxu2->raise();
        comboBoxf2->raise();
        barravida2->raise();
        cambiar2->raise();
        usar2->raise();
        comboBoxc1->raise();
        comboBoxc2->raise();
        fusionbarra->raise();
        fusionbarra2->raise();
        fusiontext1->raise();
        fusiontext2->raise();

        retranslateUi(ScreenCombate);

        QMetaObject::connectSlotsByName(ScreenCombate);
    } // setupUi

    void retranslateUi(QDialog *ScreenCombate)
    {
        ScreenCombate->setWindowTitle(QApplication::translate("ScreenCombate", "Dialog", Q_NULLPTR));
        fusion1->setText(QApplication::translate("ScreenCombate", "FUSI\303\223N", Q_NULLPTR));
        mensaje1->setText(QApplication::translate("ScreenCombate", "TextLabel", Q_NULLPTR));
        Salir->setText(QApplication::translate("ScreenCombate", "Salir", Q_NULLPTR));
        barrapoder1->setFormat(QApplication::translate("ScreenCombate", "%v/10", Q_NULLPTR));
        cambiar1->setText(QApplication::translate("ScreenCombate", "CAMBIAR", Q_NULLPTR));
        barravida1->setFormat(QApplication::translate("ScreenCombate", "%v/100", Q_NULLPTR));
        picpersonaje1->setText(QString());
        usar1->setText(QApplication::translate("ScreenCombate", "USAR", Q_NULLPTR));
        barrapoder2->setFormat(QApplication::translate("ScreenCombate", "%v/10", Q_NULLPTR));
        picpersonaje2->setText(QString());
        fusion2->setText(QApplication::translate("ScreenCombate", "FUSI\303\223N", Q_NULLPTR));
        barravida2->setFormat(QApplication::translate("ScreenCombate", "%v/100", Q_NULLPTR));
        cambiar2->setText(QApplication::translate("ScreenCombate", "CAMBIAR", Q_NULLPTR));
        usar2->setText(QApplication::translate("ScreenCombate", "USAR", Q_NULLPTR));
        picfondo->setText(QString());
        fusiontext1->setText(QString());
        fusiontext2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ScreenCombate: public Ui_ScreenCombate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENCOMBATE_H
