/********************************************************************************
** Form generated from reading UI file 'convertisseurtemp.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERTISSEURTEMP_H
#define UI_CONVERTISSEURTEMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConvertisseurTemp
{
public:
    QAction *actionConvertir;
    QAction *actionEffacer;
    QAction *actionQuitter;
    QAction *actionA_propos_de;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *hPrincipalLayout;
    QVBoxLayout *vAllLayout;
    QLabel *lTitle;
    QGridLayout *gConversionLayout;
    QLabel *lFgt;
    QHBoxLayout *hBouton2;
    QSpacerItem *horizontalSpacer;
    QPushButton *bQuitter;
    QLabel *lCelsius;
    QLabel *lResult;
    QLineEdit *input;
    QHBoxLayout *hBouton1;
    QPushButton *bConvert;
    QPushButton *bEffacer;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menusBar;
    QMenu *menuFichier;
    QMenu *menuAide;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ConvertisseurTemp)
    {
        if (ConvertisseurTemp->objectName().isEmpty())
            ConvertisseurTemp->setObjectName(QString::fromUtf8("ConvertisseurTemp"));
        ConvertisseurTemp->resize(427, 183);
        actionConvertir = new QAction(ConvertisseurTemp);
        actionConvertir->setObjectName(QString::fromUtf8("actionConvertir"));
        actionEffacer = new QAction(ConvertisseurTemp);
        actionEffacer->setObjectName(QString::fromUtf8("actionEffacer"));
        actionQuitter = new QAction(ConvertisseurTemp);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionA_propos_de = new QAction(ConvertisseurTemp);
        actionA_propos_de->setObjectName(QString::fromUtf8("actionA_propos_de"));
        centralwidget = new QWidget(ConvertisseurTemp);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        hPrincipalLayout = new QHBoxLayout();
        hPrincipalLayout->setObjectName(QString::fromUtf8("hPrincipalLayout"));
        vAllLayout = new QVBoxLayout();
        vAllLayout->setObjectName(QString::fromUtf8("vAllLayout"));
        lTitle = new QLabel(centralwidget);
        lTitle->setObjectName(QString::fromUtf8("lTitle"));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        lTitle->setFont(font);

        vAllLayout->addWidget(lTitle);

        gConversionLayout = new QGridLayout();
        gConversionLayout->setObjectName(QString::fromUtf8("gConversionLayout"));
        lFgt = new QLabel(centralwidget);
        lFgt->setObjectName(QString::fromUtf8("lFgt"));

        gConversionLayout->addWidget(lFgt, 1, 1, 1, 1);

        hBouton2 = new QHBoxLayout();
        hBouton2->setObjectName(QString::fromUtf8("hBouton2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hBouton2->addItem(horizontalSpacer);

        bQuitter = new QPushButton(centralwidget);
        bQuitter->setObjectName(QString::fromUtf8("bQuitter"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bQuitter->sizePolicy().hasHeightForWidth());
        bQuitter->setSizePolicy(sizePolicy);
        bQuitter->setAutoDefault(true);

        hBouton2->addWidget(bQuitter);


        gConversionLayout->addLayout(hBouton2, 3, 1, 1, 1);

        lCelsius = new QLabel(centralwidget);
        lCelsius->setObjectName(QString::fromUtf8("lCelsius"));

        gConversionLayout->addWidget(lCelsius, 1, 0, 1, 1);

        lResult = new QLabel(centralwidget);
        lResult->setObjectName(QString::fromUtf8("lResult"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        lResult->setFont(font1);

        gConversionLayout->addWidget(lResult, 2, 1, 1, 1);

        input = new QLineEdit(centralwidget);
        input->setObjectName(QString::fromUtf8("input"));
        sizePolicy.setHeightForWidth(input->sizePolicy().hasHeightForWidth());
        input->setSizePolicy(sizePolicy);

        gConversionLayout->addWidget(input, 2, 0, 1, 1);

        hBouton1 = new QHBoxLayout();
        hBouton1->setObjectName(QString::fromUtf8("hBouton1"));
        bConvert = new QPushButton(centralwidget);
        bConvert->setObjectName(QString::fromUtf8("bConvert"));
        sizePolicy.setHeightForWidth(bConvert->sizePolicy().hasHeightForWidth());
        bConvert->setSizePolicy(sizePolicy);
        bConvert->setAutoDefault(true);

        hBouton1->addWidget(bConvert);

        bEffacer = new QPushButton(centralwidget);
        bEffacer->setObjectName(QString::fromUtf8("bEffacer"));
        sizePolicy.setHeightForWidth(bEffacer->sizePolicy().hasHeightForWidth());
        bEffacer->setSizePolicy(sizePolicy);
        bEffacer->setAutoDefault(true);

        hBouton1->addWidget(bEffacer);


        gConversionLayout->addLayout(hBouton1, 3, 0, 1, 1);


        vAllLayout->addLayout(gConversionLayout);


        hPrincipalLayout->addLayout(vAllLayout);


        horizontalLayout_3->addLayout(hPrincipalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        ConvertisseurTemp->setCentralWidget(centralwidget);
        menusBar = new QMenuBar(ConvertisseurTemp);
        menusBar->setObjectName(QString::fromUtf8("menusBar"));
        menusBar->setGeometry(QRect(0, 0, 427, 21));
        menuFichier = new QMenu(menusBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuAide = new QMenu(menusBar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        ConvertisseurTemp->setMenuBar(menusBar);
        statusbar = new QStatusBar(ConvertisseurTemp);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ConvertisseurTemp->setStatusBar(statusbar);

        menusBar->addAction(menuFichier->menuAction());
        menusBar->addAction(menuAide->menuAction());
        menuFichier->addAction(actionConvertir);
        menuFichier->addAction(actionEffacer);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menuAide->addAction(actionA_propos_de);

        retranslateUi(ConvertisseurTemp);

        QMetaObject::connectSlotsByName(ConvertisseurTemp);
    } // setupUi

    void retranslateUi(QMainWindow *ConvertisseurTemp)
    {
        ConvertisseurTemp->setWindowTitle(QCoreApplication::translate("ConvertisseurTemp", "ConvertisseurTemp", nullptr));
        actionConvertir->setText(QCoreApplication::translate("ConvertisseurTemp", "Converti&r", nullptr));
#if QT_CONFIG(shortcut)
        actionConvertir->setShortcut(QCoreApplication::translate("ConvertisseurTemp", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEffacer->setText(QCoreApplication::translate("ConvertisseurTemp", "&Effacer", nullptr));
#if QT_CONFIG(shortcut)
        actionEffacer->setShortcut(QCoreApplication::translate("ConvertisseurTemp", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuitter->setText(QCoreApplication::translate("ConvertisseurTemp", "&Quitter", nullptr));
#if QT_CONFIG(shortcut)
        actionQuitter->setShortcut(QCoreApplication::translate("ConvertisseurTemp", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionA_propos_de->setText(QCoreApplication::translate("ConvertisseurTemp", "A &propos de...", nullptr));
#if QT_CONFIG(shortcut)
        actionA_propos_de->setShortcut(QCoreApplication::translate("ConvertisseurTemp", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        lTitle->setText(QCoreApplication::translate("ConvertisseurTemp", "Convertisseur de temp\303\251ratures ", nullptr));
        lFgt->setText(QCoreApplication::translate("ConvertisseurTemp", "Degr\303\251s Fahrenheit", nullptr));
        bQuitter->setText(QCoreApplication::translate("ConvertisseurTemp", "Quitter", nullptr));
        lCelsius->setText(QCoreApplication::translate("ConvertisseurTemp", "Degr\303\251s celsius", nullptr));
        lResult->setText(QCoreApplication::translate("ConvertisseurTemp", "---.---", nullptr));
        input->setInputMask(QString());
        input->setText(QString());
        input->setPlaceholderText(QCoreApplication::translate("ConvertisseurTemp", "Entier entre 0 et 999", nullptr));
        bConvert->setText(QCoreApplication::translate("ConvertisseurTemp", "Convertir", nullptr));
        bEffacer->setText(QCoreApplication::translate("ConvertisseurTemp", "Effacer", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("ConvertisseurTemp", "&Fichier", nullptr));
        menuAide->setTitle(QCoreApplication::translate("ConvertisseurTemp", "&Aide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConvertisseurTemp: public Ui_ConvertisseurTemp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERTISSEURTEMP_H
