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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
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
    QPushButton *bDemarrer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelNomSaisi;
    QLabel *valeurNomSaisi;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelPrenom;
    QLabel *valeurPrenomSaisi;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelMajorite;
    QLabel *valeurMajoriteSaisie;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelNbEnfant;
    QLabel *valeurNbEnfantSaisie;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(371, 244);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        bDemarrer = new QPushButton(centralwidget);
        bDemarrer->setObjectName(QString::fromUtf8("bDemarrer"));

        verticalLayout_2->addWidget(bDemarrer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelNomSaisi = new QLabel(centralwidget);
        labelNomSaisi->setObjectName(QString::fromUtf8("labelNomSaisi"));

        horizontalLayout->addWidget(labelNomSaisi);

        valeurNomSaisi = new QLabel(centralwidget);
        valeurNomSaisi->setObjectName(QString::fromUtf8("valeurNomSaisi"));

        horizontalLayout->addWidget(valeurNomSaisi);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelPrenom = new QLabel(centralwidget);
        labelPrenom->setObjectName(QString::fromUtf8("labelPrenom"));

        horizontalLayout_2->addWidget(labelPrenom);

        valeurPrenomSaisi = new QLabel(centralwidget);
        valeurPrenomSaisi->setObjectName(QString::fromUtf8("valeurPrenomSaisi"));

        horizontalLayout_2->addWidget(valeurPrenomSaisi);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelMajorite = new QLabel(centralwidget);
        labelMajorite->setObjectName(QString::fromUtf8("labelMajorite"));

        horizontalLayout_3->addWidget(labelMajorite);

        valeurMajoriteSaisie = new QLabel(centralwidget);
        valeurMajoriteSaisie->setObjectName(QString::fromUtf8("valeurMajoriteSaisie"));

        horizontalLayout_3->addWidget(valeurMajoriteSaisie);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelNbEnfant = new QLabel(centralwidget);
        labelNbEnfant->setObjectName(QString::fromUtf8("labelNbEnfant"));

        horizontalLayout_4->addWidget(labelNbEnfant);

        valeurNbEnfantSaisie = new QLabel(centralwidget);
        valeurNbEnfantSaisie->setObjectName(QString::fromUtf8("valeurNbEnfantSaisie"));

        horizontalLayout_4->addWidget(valeurNbEnfantSaisie);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 371, 21));
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
        bDemarrer->setText(QCoreApplication::translate("MainWindow", "D\303\251marrer Questionnaire", nullptr));
        labelNomSaisi->setText(QCoreApplication::translate("MainWindow", "Nom saisi : ", nullptr));
        valeurNomSaisi->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        labelPrenom->setText(QCoreApplication::translate("MainWindow", "Prenom saisi : ", nullptr));
        valeurPrenomSaisi->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        labelMajorite->setText(QCoreApplication::translate("MainWindow", "Majorit\303\251 : ", nullptr));
        valeurMajoriteSaisie->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        labelNbEnfant->setText(QCoreApplication::translate("MainWindow", "Nbre d'enfants : ", nullptr));
        valeurNbEnfantSaisie->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
