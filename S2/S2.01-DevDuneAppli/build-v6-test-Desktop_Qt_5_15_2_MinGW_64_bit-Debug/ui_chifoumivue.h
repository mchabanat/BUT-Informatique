/********************************************************************************
** Form generated from reading UI file 'chifoumivue.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHIFOUMIVUE_H
#define UI_CHIFOUMIVUE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChifoumiVue
{
public:
    QAction *actionA_propos_de;
    QAction *actionQuitter;
    QAction *action_Parametrer;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *vAllChifoumi;
    QGridLayout *gridPartieHaute;
    QVBoxLayout *verticalLayout;
    QLabel *lJoueur;
    QLabel *scoreJoueur;
    QLabel *coupMachine;
    QLabel *coupJoueur;
    QSpacerItem *horizontalSpacer_10;
    QVBoxLayout *verticalLayout_2;
    QLabel *lMachine;
    QLabel *scoreMachine;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *versus;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_9;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *pointsMax;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *hPartieBasse;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *vInterfaceJoueur;
    QGroupBox *gbBoutonsCoups;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pierre;
    QPushButton *papier;
    QPushButton *ciseau;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *hBoutNewPartie;
    QSpacerItem *horizontalSpacer;
    QPushButton *bNewPartie;
    QSpacerItem *horizontalSpacer_6;
    QMenuBar *menubar;
    QMenu *menu_Fichier;
    QMenu *menu_Aide;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChifoumiVue)
    {
        if (ChifoumiVue->objectName().isEmpty())
            ChifoumiVue->setObjectName(QString::fromUtf8("ChifoumiVue"));
        ChifoumiVue->resize(625, 528);
        actionA_propos_de = new QAction(ChifoumiVue);
        actionA_propos_de->setObjectName(QString::fromUtf8("actionA_propos_de"));
        actionQuitter = new QAction(ChifoumiVue);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        action_Parametrer = new QAction(ChifoumiVue);
        action_Parametrer->setObjectName(QString::fromUtf8("action_Parametrer"));
        centralwidget = new QWidget(ChifoumiVue);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_5 = new QHBoxLayout(centralwidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        vAllChifoumi = new QVBoxLayout();
        vAllChifoumi->setObjectName(QString::fromUtf8("vAllChifoumi"));
        gridPartieHaute = new QGridLayout();
        gridPartieHaute->setObjectName(QString::fromUtf8("gridPartieHaute"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lJoueur = new QLabel(centralwidget);
        lJoueur->setObjectName(QString::fromUtf8("lJoueur"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lJoueur->sizePolicy().hasHeightForWidth());
        lJoueur->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        lJoueur->setFont(font);
        lJoueur->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lJoueur);

        scoreJoueur = new QLabel(centralwidget);
        scoreJoueur->setObjectName(QString::fromUtf8("scoreJoueur"));
        QFont font1;
        font1.setPointSize(12);
        scoreJoueur->setFont(font1);
        scoreJoueur->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(scoreJoueur);


        gridPartieHaute->addLayout(verticalLayout, 0, 1, 1, 1);

        coupMachine = new QLabel(centralwidget);
        coupMachine->setObjectName(QString::fromUtf8("coupMachine"));
        coupMachine->setPixmap(QPixmap(QString::fromUtf8(":/chifoumi/images/rien_115.png")));

        gridPartieHaute->addWidget(coupMachine, 1, 3, 1, 1);

        coupJoueur = new QLabel(centralwidget);
        coupJoueur->setObjectName(QString::fromUtf8("coupJoueur"));
        coupJoueur->setPixmap(QPixmap(QString::fromUtf8(":/chifoumi/images/rien_115.png")));

        gridPartieHaute->addWidget(coupJoueur, 1, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridPartieHaute->addItem(horizontalSpacer_10, 1, 4, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lMachine = new QLabel(centralwidget);
        lMachine->setObjectName(QString::fromUtf8("lMachine"));
        sizePolicy.setHeightForWidth(lMachine->sizePolicy().hasHeightForWidth());
        lMachine->setSizePolicy(sizePolicy);
        lMachine->setFont(font);
        lMachine->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lMachine);

        scoreMachine = new QLabel(centralwidget);
        scoreMachine->setObjectName(QString::fromUtf8("scoreMachine"));
        scoreMachine->setFont(font1);
        scoreMachine->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(scoreMachine);


        gridPartieHaute->addLayout(verticalLayout_2, 0, 3, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        versus = new QLabel(centralwidget);
        versus->setObjectName(QString::fromUtf8("versus"));
        versus->setPixmap(QPixmap(QString::fromUtf8(":/chifoumi/images/versus_70.png")));
        versus->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(versus);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        gridPartieHaute->addLayout(horizontalLayout_2, 1, 2, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridPartieHaute->addItem(horizontalSpacer_9, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setWeight(50);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        pointsMax = new QLabel(centralwidget);
        pointsMax->setObjectName(QString::fromUtf8("pointsMax"));
        QFont font3;
        font3.setPointSize(14);
        pointsMax->setFont(font3);
        pointsMax->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(pointsMax, 1, 0, 1, 1);


        gridPartieHaute->addLayout(gridLayout_2, 0, 2, 1, 1);


        vAllChifoumi->addLayout(gridPartieHaute);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vAllChifoumi->addItem(verticalSpacer);

        hPartieBasse = new QHBoxLayout();
        hPartieBasse->setObjectName(QString::fromUtf8("hPartieBasse"));
        hPartieBasse->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hPartieBasse->addItem(horizontalSpacer_5);

        vInterfaceJoueur = new QVBoxLayout();
        vInterfaceJoueur->setSpacing(9);
        vInterfaceJoueur->setObjectName(QString::fromUtf8("vInterfaceJoueur"));
        vInterfaceJoueur->setContentsMargins(0, 0, -1, -1);
        gbBoutonsCoups = new QGroupBox(centralwidget);
        gbBoutonsCoups->setObjectName(QString::fromUtf8("gbBoutonsCoups"));
        gbBoutonsCoups->setMinimumSize(QSize(509, 191));
        gbBoutonsCoups->setMaximumSize(QSize(100000, 191));
        horizontalLayout_6 = new QHBoxLayout(gbBoutonsCoups);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        pierre = new QPushButton(gbBoutonsCoups);
        pierre->setObjectName(QString::fromUtf8("pierre"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/chifoumi/images/pierre_115.png"), QSize(), QIcon::Normal, QIcon::On);
        pierre->setIcon(icon);
        pierre->setIconSize(QSize(127, 128));

        horizontalLayout_3->addWidget(pierre);

        papier = new QPushButton(gbBoutonsCoups);
        papier->setObjectName(QString::fromUtf8("papier"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/chifoumi/images/papier_115.png"), QSize(), QIcon::Normal, QIcon::On);
        papier->setIcon(icon1);
        papier->setIconSize(QSize(127, 128));

        horizontalLayout_3->addWidget(papier);

        ciseau = new QPushButton(gbBoutonsCoups);
        ciseau->setObjectName(QString::fromUtf8("ciseau"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/chifoumi/images/ciseau_115.png"), QSize(), QIcon::Normal, QIcon::On);
        ciseau->setIcon(icon2);
        ciseau->setIconSize(QSize(127, 128));

        horizontalLayout_3->addWidget(ciseau);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);


        horizontalLayout_6->addLayout(horizontalLayout_3);


        vInterfaceJoueur->addWidget(gbBoutonsCoups);

        hBoutNewPartie = new QHBoxLayout();
        hBoutNewPartie->setObjectName(QString::fromUtf8("hBoutNewPartie"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hBoutNewPartie->addItem(horizontalSpacer);

        bNewPartie = new QPushButton(centralwidget);
        bNewPartie->setObjectName(QString::fromUtf8("bNewPartie"));

        hBoutNewPartie->addWidget(bNewPartie);


        vInterfaceJoueur->addLayout(hBoutNewPartie);


        hPartieBasse->addLayout(vInterfaceJoueur);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hPartieBasse->addItem(horizontalSpacer_6);


        vAllChifoumi->addLayout(hPartieBasse);


        horizontalLayout_5->addLayout(vAllChifoumi);

        ChifoumiVue->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChifoumiVue);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 625, 21));
        menu_Fichier = new QMenu(menubar);
        menu_Fichier->setObjectName(QString::fromUtf8("menu_Fichier"));
        menu_Aide = new QMenu(menubar);
        menu_Aide->setObjectName(QString::fromUtf8("menu_Aide"));
        ChifoumiVue->setMenuBar(menubar);
        statusbar = new QStatusBar(ChifoumiVue);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ChifoumiVue->setStatusBar(statusbar);

        menubar->addAction(menu_Fichier->menuAction());
        menubar->addAction(menu_Aide->menuAction());
        menu_Fichier->addAction(action_Parametrer);
        menu_Fichier->addAction(actionQuitter);
        menu_Aide->addAction(actionA_propos_de);

        retranslateUi(ChifoumiVue);

        QMetaObject::connectSlotsByName(ChifoumiVue);
    } // setupUi

    void retranslateUi(QMainWindow *ChifoumiVue)
    {
        ChifoumiVue->setWindowTitle(QCoreApplication::translate("ChifoumiVue", "Chifoumi", nullptr));
        actionA_propos_de->setText(QCoreApplication::translate("ChifoumiVue", "&A propos de ...", nullptr));
#if QT_CONFIG(shortcut)
        actionA_propos_de->setShortcut(QCoreApplication::translate("ChifoumiVue", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuitter->setText(QCoreApplication::translate("ChifoumiVue", "&Quitter", nullptr));
#if QT_CONFIG(shortcut)
        actionQuitter->setShortcut(QCoreApplication::translate("ChifoumiVue", "Alt+F3", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Parametrer->setText(QCoreApplication::translate("ChifoumiVue", "&Param\303\251trer", nullptr));
#if QT_CONFIG(shortcut)
        action_Parametrer->setShortcut(QCoreApplication::translate("ChifoumiVue", "Alt+P", nullptr));
#endif // QT_CONFIG(shortcut)
        lJoueur->setText(QCoreApplication::translate("ChifoumiVue", "Vous", nullptr));
        scoreJoueur->setText(QCoreApplication::translate("ChifoumiVue", "0", nullptr));
        coupMachine->setText(QString());
        coupJoueur->setText(QString());
        lMachine->setText(QCoreApplication::translate("ChifoumiVue", "Machine", nullptr));
        scoreMachine->setText(QCoreApplication::translate("ChifoumiVue", "0", nullptr));
        versus->setText(QString());
        label->setText(QCoreApplication::translate("ChifoumiVue", "Gagnant \303\240", nullptr));
        pointsMax->setText(QCoreApplication::translate("ChifoumiVue", "5", nullptr));
        gbBoutonsCoups->setTitle(QCoreApplication::translate("ChifoumiVue", "Choisissez une figure :", nullptr));
        pierre->setText(QString());
        papier->setText(QString());
        ciseau->setText(QString());
        bNewPartie->setText(QCoreApplication::translate("ChifoumiVue", "Jouer", nullptr));
        menu_Fichier->setTitle(QCoreApplication::translate("ChifoumiVue", "&Fichier", nullptr));
        menu_Aide->setTitle(QCoreApplication::translate("ChifoumiVue", "&Aide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChifoumiVue: public Ui_ChifoumiVue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHIFOUMIVUE_H
