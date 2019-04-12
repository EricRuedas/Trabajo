/********************************************************************************
** Form generated from reading UI file 'reglas.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGLAS_H
#define UI_REGLAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reglas
{
public:
    QPushButton *pushButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTextEdit *textEdit;

    void setupUi(QDialog *reglas)
    {
        if (reglas->objectName().isEmpty())
            reglas->setObjectName(QStringLiteral("reglas"));
        reglas->resize(400, 300);
        pushButton = new QPushButton(reglas);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 230, 131, 51));
        scrollArea = new QScrollArea(reglas);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(30, 30, 331, 191));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 329, 189));
        textEdit = new QTextEdit(scrollAreaWidgetContents);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 10, 311, 171));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(reglas);

        QMetaObject::connectSlotsByName(reglas);
    } // setupUi

    void retranslateUi(QDialog *reglas)
    {
        reglas->setWindowTitle(QApplication::translate("reglas", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("reglas", "\302\241ENTENDIDO!", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("reglas", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Este juego consiste en una batalla de 3vs3 con personajes que pueden ser los siguientes:</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">- Guerrero, el cu\303\241l tiene un alto ataque y defensa pero unas bajas caracter\303\255sticas de ataque y defensa m\303\241gica.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-bl"
                        "ock-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">- Mago, el cu\303\241l tiene un alt\303\255simo ataque m\303\241gico y unas bajas defensas, tanto f\303\255sica c\303\263mo m\303\241gica.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">- Cl\303\251rigo, el cu\303\241l tiene una alt\303\255sima defensa m\303\241gica y unas bajas caracter\303\255sticas f\303\255sicas. Adem\303\241s, tiene unos ataques de soporte muy buenos.</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Los ataques normales (f\303\255sicos) tendr\303\241n en cuenta p"
                        "ara calcular el da\303\261o la defensa f\303\255sica del rival, mientras que los ataques m\303\241giso tendr\303\241n en cuenta para calcular el da\303\261o la defensa m\303\241gica del rival.</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Adem\303\241s, se pueden hacer fusiones. \303\211stas, se har\303\241n entre dos personajes (el presente en batalla + otro integrante de tu equipo que no est\303\251 debilitado). Las caracter\303\255sticas de los personajes fusionados son m\303\241s altas que por separado y tendr\303\241n como ataques los de ambos personajes fusionados m\303\241s uno extra, el cu\303\241l es muy poderoso. Dichas fusiones se podr\303\241n realizar cuando uno de los "
                        "personajes haya pasado 3 turnos seguidos en el campo (hay una barra indicadora durante el combate) y con un m\303\241ximo de 1 fusi\303\263n por equipo.</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class reglas: public Ui_reglas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGLAS_H
