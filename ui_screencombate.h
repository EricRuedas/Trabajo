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
    QLabel *mensaje2;
    QComboBox *comboBoxu2;
    QComboBox *comboBoxf2;
    QProgressBar *barravida2;
    QPushButton *cambiar2;
    QPushButton *usar2;

    void setupUi(QDialog *ScreenCombate)
    {
        if (ScreenCombate->objectName().isEmpty())
            ScreenCombate->setObjectName(QStringLiteral("ScreenCombate"));
        ScreenCombate->resize(1014, 630);
        fusion1 = new QPushButton(ScreenCombate);
        fusion1->setObjectName(QStringLiteral("fusion1"));
        fusion1->setGeometry(QRect(40, 420, 121, 41));
        mensaje1 = new QLabel(ScreenCombate);
        mensaje1->setObjectName(QStringLiteral("mensaje1"));
        mensaje1->setGeometry(QRect(40, 490, 401, 31));
        Salir = new QCommandLinkButton(ScreenCombate);
        Salir->setObjectName(QStringLiteral("Salir"));
        Salir->setGeometry(QRect(30, 530, 71, 41));
        comboBoxu1 = new QComboBox(ScreenCombate);
        comboBoxu1->setObjectName(QStringLiteral("comboBoxu1"));
        comboBoxu1->setGeometry(QRect(320, 460, 121, 22));
        barrapoder1 = new QProgressBar(ScreenCombate);
        barrapoder1->setObjectName(QStringLiteral("barrapoder1"));
        barrapoder1->setGeometry(QRect(210, 10, 81, 23));
        barrapoder1->setMaximum(10);
        barrapoder1->setValue(5);
        cambiar1 = new QPushButton(ScreenCombate);
        cambiar1->setObjectName(QStringLiteral("cambiar1"));
        cambiar1->setGeometry(QRect(180, 420, 121, 41));
        barravida1 = new QProgressBar(ScreenCombate);
        barravida1->setObjectName(QStringLiteral("barravida1"));
        barravida1->setGeometry(QRect(40, 10, 151, 23));
        barravida1->setStyleSheet(QStringLiteral(""));
        barravida1->setMaximum(100);
        barravida1->setValue(50);
        picpersonaje1 = new QLabel(ScreenCombate);
        picpersonaje1->setObjectName(QStringLiteral("picpersonaje1"));
        picpersonaje1->setGeometry(QRect(60, 80, 241, 331));
        usar1 = new QPushButton(ScreenCombate);
        usar1->setObjectName(QStringLiteral("usar1"));
        usar1->setGeometry(QRect(320, 420, 121, 41));
        comboBoxf1 = new QComboBox(ScreenCombate);
        comboBoxf1->setObjectName(QStringLiteral("comboBoxf1"));
        comboBoxf1->setGeometry(QRect(40, 460, 121, 22));
        barrapoder2 = new QProgressBar(ScreenCombate);
        barrapoder2->setObjectName(QStringLiteral("barrapoder2"));
        barrapoder2->setGeometry(QRect(720, 10, 81, 23));
        barrapoder2->setMaximum(10);
        barrapoder2->setValue(5);
        picpersonaje2 = new QLabel(ScreenCombate);
        picpersonaje2->setObjectName(QStringLiteral("picpersonaje2"));
        picpersonaje2->setGeometry(QRect(700, 70, 241, 331));
        fusion2 = new QPushButton(ScreenCombate);
        fusion2->setObjectName(QStringLiteral("fusion2"));
        fusion2->setGeometry(QRect(840, 420, 121, 41));
        mensaje2 = new QLabel(ScreenCombate);
        mensaje2->setObjectName(QStringLiteral("mensaje2"));
        mensaje2->setGeometry(QRect(560, 490, 401, 31));
        comboBoxu2 = new QComboBox(ScreenCombate);
        comboBoxu2->setObjectName(QStringLiteral("comboBoxu2"));
        comboBoxu2->setGeometry(QRect(560, 460, 121, 22));
        comboBoxf2 = new QComboBox(ScreenCombate);
        comboBoxf2->setObjectName(QStringLiteral("comboBoxf2"));
        comboBoxf2->setGeometry(QRect(840, 460, 121, 22));
        barravida2 = new QProgressBar(ScreenCombate);
        barravida2->setObjectName(QStringLiteral("barravida2"));
        barravida2->setGeometry(QRect(820, 10, 151, 23));
        barravida2->setMaximum(100);
        barravida2->setValue(50);
        cambiar2 = new QPushButton(ScreenCombate);
        cambiar2->setObjectName(QStringLiteral("cambiar2"));
        cambiar2->setGeometry(QRect(700, 420, 121, 41));
        usar2 = new QPushButton(ScreenCombate);
        usar2->setObjectName(QStringLiteral("usar2"));
        usar2->setGeometry(QRect(560, 420, 121, 41));

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
        mensaje2->setText(QApplication::translate("ScreenCombate", "TextLabel", Q_NULLPTR));
        barravida2->setFormat(QApplication::translate("ScreenCombate", "%v/100", Q_NULLPTR));
        cambiar2->setText(QApplication::translate("ScreenCombate", "CAMBIAR", Q_NULLPTR));
        usar2->setText(QApplication::translate("ScreenCombate", "USAR", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ScreenCombate: public Ui_ScreenCombate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENCOMBATE_H
