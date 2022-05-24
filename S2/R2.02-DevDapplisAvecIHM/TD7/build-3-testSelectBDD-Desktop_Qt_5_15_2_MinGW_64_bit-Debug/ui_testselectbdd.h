/********************************************************************************
** Form generated from reading UI file 'testselectbdd.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTSELECTBDD_H
#define UI_TESTSELECTBDD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestSelectBDD
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TestSelectBDD)
    {
        if (TestSelectBDD->objectName().isEmpty())
            TestSelectBDD->setObjectName(QString::fromUtf8("TestSelectBDD"));
        TestSelectBDD->resize(800, 600);
        centralwidget = new QWidget(TestSelectBDD);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        TestSelectBDD->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestSelectBDD);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        TestSelectBDD->setMenuBar(menubar);
        statusbar = new QStatusBar(TestSelectBDD);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TestSelectBDD->setStatusBar(statusbar);

        retranslateUi(TestSelectBDD);

        QMetaObject::connectSlotsByName(TestSelectBDD);
    } // setupUi

    void retranslateUi(QMainWindow *TestSelectBDD)
    {
        TestSelectBDD->setWindowTitle(QCoreApplication::translate("TestSelectBDD", "TestSelectBDD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestSelectBDD: public Ui_TestSelectBDD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTSELECTBDD_H
