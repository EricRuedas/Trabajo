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
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_reglas
{
public:
    QPushButton *pushButton;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *reglas)
    {
        if (reglas->objectName().isEmpty())
            reglas->setObjectName(QStringLiteral("reglas"));
        reglas->resize(400, 300);
        pushButton = new QPushButton(reglas);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 230, 131, 51));
        textBrowser = new QTextBrowser(reglas);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(40, 10, 321, 211));

        retranslateUi(reglas);

        QMetaObject::connectSlotsByName(reglas);
    } // setupUi

    void retranslateUi(QDialog *reglas)
    {
        reglas->setWindowTitle(QApplication::translate("reglas", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("reglas", "\302\241ENTENDIDO!", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("reglas", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Este juego consiste en una batalla de 3vs3 con personajes que pueden ser los siguientes:</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">- Guerrero, el cu\303\241l tiene un alto ataque y defensa pero unas bajas caracter\303\255sticas de ataque y defensa m\303\241gica.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-"
                        "right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">- Mago, el cu\303\241l tiene un alt\303\255simo ataque m\303\241gico y unas bajas defensas, tanto f\303\255sica c\303\263mo m\303\241gica.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">- Cl\303\251rigo, el cu\303\241l tiene una alt\303\255sima defensa m\303\241gica y unas bajas caracter\303\255sticas f\303\255sicas. Adem\303\241s, tiene unos ataques de soporte muy buenos.</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class reglas: public Ui_reglas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGLAS_H
