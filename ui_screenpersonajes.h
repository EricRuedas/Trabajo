/********************************************************************************
** Form generated from reading UI file 'screenpersonajes.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENPERSONAJES_H
#define UI_SCREENPERSONAJES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_screenpersonajes
{
public:
    QComboBox *seleccion1;
    QComboBox *seleccion2;
    QComboBox *seleccion3;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *seleccion4;
    QComboBox *seleccion5;
    QComboBox *seleccion6;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *startcombatbutton;
    QPushButton *volvermenubutton;

    void setupUi(QDialog *screenpersonajes)
    {
        if (screenpersonajes->objectName().isEmpty())
            screenpersonajes->setObjectName(QStringLiteral("screenpersonajes"));
        screenpersonajes->resize(638, 437);
        seleccion1 = new QComboBox(screenpersonajes);
        seleccion1->setObjectName(QStringLiteral("seleccion1"));
        seleccion1->setGeometry(QRect(30, 110, 181, 61));
        seleccion2 = new QComboBox(screenpersonajes);
        seleccion2->setObjectName(QStringLiteral("seleccion2"));
        seleccion2->setGeometry(QRect(30, 220, 181, 61));
        seleccion3 = new QComboBox(screenpersonajes);
        seleccion3->setObjectName(QStringLiteral("seleccion3"));
        seleccion3->setGeometry(QRect(30, 340, 181, 61));
        label_1 = new QLabel(screenpersonajes);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setGeometry(QRect(50, 10, 131, 31));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(true);
        font.setUnderline(true);
        font.setWeight(75);
        label_1->setFont(font);
        label_2 = new QLabel(screenpersonajes);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 80, 151, 21));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_3 = new QLabel(screenpersonajes);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 190, 171, 21));
        label_3->setFont(font1);
        label_4 = new QLabel(screenpersonajes);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 310, 151, 21));
        label_4->setFont(font1);
        seleccion4 = new QComboBox(screenpersonajes);
        seleccion4->setObjectName(QStringLiteral("seleccion4"));
        seleccion4->setGeometry(QRect(410, 110, 181, 61));
        seleccion5 = new QComboBox(screenpersonajes);
        seleccion5->setObjectName(QStringLiteral("seleccion5"));
        seleccion5->setGeometry(QRect(410, 220, 181, 61));
        seleccion6 = new QComboBox(screenpersonajes);
        seleccion6->setObjectName(QStringLiteral("seleccion6"));
        seleccion6->setGeometry(QRect(410, 340, 181, 61));
        label_5 = new QLabel(screenpersonajes);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(450, 10, 131, 31));
        label_5->setFont(font);
        label_6 = new QLabel(screenpersonajes);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(420, 80, 151, 21));
        label_6->setFont(font1);
        label_7 = new QLabel(screenpersonajes);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(420, 310, 151, 21));
        label_7->setFont(font1);
        label_8 = new QLabel(screenpersonajes);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(420, 190, 171, 21));
        label_8->setFont(font1);
        startcombatbutton = new QPushButton(screenpersonajes);
        startcombatbutton->setObjectName(QStringLiteral("startcombatbutton"));
        startcombatbutton->setGeometry(QRect(250, 150, 121, 61));
        startcombatbutton->setStyleSheet(QLatin1String("QPushButton {\n"
"  background-color: rgb(255, 50, 50);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF3822, stop: 1 #FF5720);\n"
"}"));
        volvermenubutton = new QPushButton(screenpersonajes);
        volvermenubutton->setObjectName(QStringLiteral("volvermenubutton"));
        volvermenubutton->setGeometry(QRect(240, 280, 141, 51));
        QFont font2;
        font2.setPointSize(7);
        volvermenubutton->setFont(font2);
        volvermenubutton->setStyleSheet(QLatin1String("QPushButton {\n"
"  background-color: rgb(0, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #007832, stop: 1 #009739);\n"
"}"));

        retranslateUi(screenpersonajes);

        QMetaObject::connectSlotsByName(screenpersonajes);
    } // setupUi

    void retranslateUi(QDialog *screenpersonajes)
    {
        screenpersonajes->setWindowTitle(QApplication::translate("screenpersonajes", "Dialog", Q_NULLPTR));
        label_1->setText(QApplication::translate("screenpersonajes", "JUGADOR 1", Q_NULLPTR));
        label_2->setText(QApplication::translate("screenpersonajes", "PRIMER PERSONAJE", Q_NULLPTR));
        label_3->setText(QApplication::translate("screenpersonajes", "SEGUNDO PERSONAJE", Q_NULLPTR));
        label_4->setText(QApplication::translate("screenpersonajes", "TERCER PERSONAJE", Q_NULLPTR));
        label_5->setText(QApplication::translate("screenpersonajes", "JUGADOR 2", Q_NULLPTR));
        label_6->setText(QApplication::translate("screenpersonajes", "PRIMER PERSONAJE", Q_NULLPTR));
        label_7->setText(QApplication::translate("screenpersonajes", "TERCER PERSONAJE", Q_NULLPTR));
        label_8->setText(QApplication::translate("screenpersonajes", "SEGUNDO PERSONAJE", Q_NULLPTR));
        startcombatbutton->setText(QApplication::translate("screenpersonajes", "EMPEZAR COMBATE", Q_NULLPTR));
        volvermenubutton->setText(QApplication::translate("screenpersonajes", "VOLVER A MEN\303\232 PRINCIPAL", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class screenpersonajes: public Ui_screenpersonajes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENPERSONAJES_H
