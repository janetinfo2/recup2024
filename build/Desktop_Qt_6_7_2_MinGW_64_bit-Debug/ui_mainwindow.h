/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *rbis;
    QLabel *label;
    QPushButton *btn_fx;
    QLineEdit *x1;
    QLabel *label_4;
    QPushButton *biseccion;
    QPushButton *btn_integralfx;
    QLineEdit *rnew;
    QLabel *label_3;
    QLabel *label_5;
    QCustomPlot *graphic;
    QLineEdit *fx;
    QLabel *label_6;
    QLineEdit *x2;
    QPushButton *newton;
    QLabel *label_2;
    QLabel *label_7;
    QPushButton *archivo;
    QLabel *label_8;
    QLineEdit *dx;
    QLabel *label_9;
    QLineEdit *raiz;
    QLabel *label_10;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        rbis = new QLineEdit(centralwidget);
        rbis->setObjectName("rbis");
        rbis->setGeometry(QRect(340, 420, 101, 24));
        rbis->setReadOnly(true);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 490, 21, 16));
        btn_fx = new QPushButton(centralwidget);
        btn_fx->setObjectName("btn_fx");
        btn_fx->setGeometry(QRect(160, 490, 61, 24));
        x1 = new QLineEdit(centralwidget);
        x1->setObjectName("x1");
        x1->setGeometry(QRect(40, 430, 41, 24));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(120, 410, 16, 16));
        biseccion = new QPushButton(centralwidget);
        biseccion->setObjectName("biseccion");
        biseccion->setGeometry(QRect(450, 420, 80, 24));
        btn_integralfx = new QPushButton(centralwidget);
        btn_integralfx->setObjectName("btn_integralfx");
        btn_integralfx->setGeometry(QRect(40, 520, 101, 24));
        rnew = new QLineEdit(centralwidget);
        rnew->setObjectName("rnew");
        rnew->setGeometry(QRect(340, 520, 101, 24));
        rnew->setReadOnly(true);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 410, 16, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(270, 420, 61, 20));
        graphic = new QCustomPlot(centralwidget);
        graphic->setObjectName("graphic");
        graphic->setGeometry(QRect(30, 9, 741, 371));
        fx = new QLineEdit(centralwidget);
        fx->setObjectName("fx");
        fx->setGeometry(QRect(40, 490, 113, 24));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(270, 520, 61, 20));
        x2 = new QLineEdit(centralwidget);
        x2->setObjectName("x2");
        x2->setGeometry(QRect(110, 430, 41, 24));
        newton = new QPushButton(centralwidget);
        newton->setObjectName("newton");
        newton->setGeometry(QRect(450, 520, 80, 24));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(330, 390, 131, 20));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(310, 460, 181, 20));
        archivo = new QPushButton(centralwidget);
        archivo->setObjectName("archivo");
        archivo->setGeometry(QRect(590, 420, 151, 24));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 390, 201, 16));
        dx = new QLineEdit(centralwidget);
        dx->setObjectName("dx");
        dx->setGeometry(QRect(40, 460, 41, 24));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 460, 16, 16));
        raiz = new QLineEdit(centralwidget);
        raiz->setObjectName("raiz");
        raiz->setGeometry(QRect(390, 490, 141, 24));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(270, 490, 121, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "f(x)", nullptr));
        btn_fx->setText(QCoreApplication::translate("MainWindow", "plot f(x)", nullptr));
        x1->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "x2", nullptr));
        biseccion->setText(QCoreApplication::translate("MainWindow", "Ver raices f(x)", nullptr));
        btn_integralfx->setText(QCoreApplication::translate("MainWindow", "plot integral f(x)", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "x1", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Raices f(x)", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Raices f(x)", nullptr));
        newton->setText(QCoreApplication::translate("MainWindow", "Ver raices f(x)", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "RAICES POR BISECCION", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "RAICES POR NEWTON RAPSON ", nullptr));
        archivo->setText(QCoreApplication::translate("MainWindow", "Guardar datos en archivo", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "INGRESE INTERVALO PARA GRAFICAR", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "dx", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Ingrese Raiz Estimada", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
