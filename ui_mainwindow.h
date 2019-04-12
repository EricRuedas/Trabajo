/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_3;
    QPushButton *BeginButton;
    QPushButton *SkipButton;
    QLabel *label;
    QLabel *label_2;
    QPushButton *RulesButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 314);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 70, 331, 31));
        BeginButton = new QPushButton(centralWidget);
        BeginButton->setObjectName(QStringLiteral("BeginButton"));
        BeginButton->setGeometry(QRect(40, 130, 121, 81));
        BeginButton->setStyleSheet(QLatin1String("background-color: rgb(89, 239, 255);\n"
""));
        SkipButton = new QPushButton(centralWidget);
        SkipButton->setObjectName(QStringLiteral("SkipButton"));
        SkipButton->setGeometry(QRect(240, 130, 121, 81));
        SkipButton->setStyleSheet(QStringLiteral("background-color: rgb(255, 85, 0);"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 10, 311, 21));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 50, 291, 16));
        RulesButton = new QPushButton(centralWidget);
        RulesButton->setObjectName(QStringLiteral("RulesButton"));
        RulesButton->setGeometry(QRect(120, 222, 141, 31));
        RulesButton->setStyleSheet(QStringLiteral("background-color: rgb(170, 85, 127);"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "PD: NO TIENE NOMBRE EL JUEGO.", Q_NULLPTR));
        BeginButton->setText(QApplication::translate("MainWindow", "ELEGIR PERSONAJES", Q_NULLPTR));
        SkipButton->setText(QApplication::translate("MainWindow", "SALIR DEL JUEGO", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "BIENVENIDO AL MEJOR JUEGO DEL MUNDO.", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "DISFR\303\232TALO SI QUIERES....", Q_NULLPTR));
        RulesButton->setText(QApplication::translate("MainWindow", "REGLAS DEL JUEGO", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
