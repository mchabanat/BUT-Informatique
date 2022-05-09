/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *boxAll;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *user;
    QLineEdit *inputUser;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passwd;
    QLineEdit *inputMdp;
    QPushButton *bConnexion;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(302, 171);
        MainWindow->setMinimumSize(QSize(302, 171));
        MainWindow->setMaximumSize(QSize(302, 171));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        boxAll = new QGroupBox(centralwidget);
        boxAll->setObjectName(QString::fromUtf8("boxAll"));
        verticalLayout = new QVBoxLayout(boxAll);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        user = new QLabel(boxAll);
        user->setObjectName(QString::fromUtf8("user"));

        horizontalLayout->addWidget(user);

        inputUser = new QLineEdit(boxAll);
        inputUser->setObjectName(QString::fromUtf8("inputUser"));

        horizontalLayout->addWidget(inputUser);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        passwd = new QLabel(boxAll);
        passwd->setObjectName(QString::fromUtf8("passwd"));

        horizontalLayout_2->addWidget(passwd);

        inputMdp = new QLineEdit(boxAll);
        inputMdp->setObjectName(QString::fromUtf8("inputMdp"));
        inputMdp->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(inputMdp);


        verticalLayout->addLayout(horizontalLayout_2);

        bConnexion = new QPushButton(boxAll);
        bConnexion->setObjectName(QString::fromUtf8("bConnexion"));

        verticalLayout->addWidget(bConnexion);


        verticalLayout_2->addWidget(boxAll);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 302, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        boxAll->setTitle(QCoreApplication::translate("MainWindow", "Connexion", nullptr));
        user->setText(QCoreApplication::translate("MainWindow", "Utilisateur :", nullptr));
        passwd->setText(QCoreApplication::translate("MainWindow", "Mot de passe :", nullptr));
        inputMdp->setText(QString());
        bConnexion->setText(QCoreApplication::translate("MainWindow", "Connexion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
