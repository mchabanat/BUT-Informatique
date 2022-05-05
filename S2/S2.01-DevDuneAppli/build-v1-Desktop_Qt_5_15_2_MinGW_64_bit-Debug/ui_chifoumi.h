/********************************************************************************
** Form generated from reading UI file 'chifoumi.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHIFOUMI_H
#define UI_CHIFOUMI_H

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

class Ui_Chifoumi
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
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
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *bbbbbbbbbbb;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *aaaaaaaaaa;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pierre;
    QPushButton *papier;
    QPushButton *ciseau;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *bNewPartie;
    QSpacerItem *horizontalSpacer_6;
    QMenuBar *menubar;
    QMenu *menu_Fichier;
    QMenu *menu_Aide;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Chifoumi)
    {
        if (Chifoumi->objectName().isEmpty())
            Chifoumi->setObjectName(QString::fromUtf8("Chifoumi"));
        Chifoumi->resize(623, 528);
        centralwidget = new QWidget(Chifoumi);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_5 = new QHBoxLayout(centralwidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
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


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        coupMachine = new QLabel(centralwidget);
        coupMachine->setObjectName(QString::fromUtf8("coupMachine"));
        coupMachine->setPixmap(QPixmap(QString::fromUtf8(":/chifoumi/images/rien_115.png")));

        gridLayout->addWidget(coupMachine, 1, 3, 1, 1);

        coupJoueur = new QLabel(centralwidget);
        coupJoueur->setObjectName(QString::fromUtf8("coupJoueur"));
        coupJoueur->setPixmap(QPixmap(QString::fromUtf8(":/chifoumi/images/rien_115.png")));

        gridLayout->addWidget(coupJoueur, 1, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 1, 4, 1, 1);

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


        gridLayout->addLayout(verticalLayout_2, 0, 3, 1, 1);

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


        gridLayout->addLayout(horizontalLayout_2, 1, 2, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        bbbbbbbbbbb = new QHBoxLayout();
        bbbbbbbbbbb->setObjectName(QString::fromUtf8("bbbbbbbbbbb"));
        bbbbbbbbbbb->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        bbbbbbbbbbb->addItem(horizontalSpacer_5);

        aaaaaaaaaa = new QVBoxLayout();
        aaaaaaaaaa->setSpacing(9);
        aaaaaaaaaa->setObjectName(QString::fromUtf8("aaaaaaaaaa"));
        aaaaaaaaaa->setContentsMargins(0, 0, -1, -1);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(509, 191));
        groupBox->setMaximumSize(QSize(100000, 191));
        horizontalLayout_6 = new QHBoxLayout(groupBox);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        pierre = new QPushButton(groupBox);
        pierre->setObjectName(QString::fromUtf8("pierre"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/chifoumi/images/pierre_115.png"), QSize(), QIcon::Normal, QIcon::On);
        pierre->setIcon(icon);
        pierre->setIconSize(QSize(127, 128));

        horizontalLayout_3->addWidget(pierre);

        papier = new QPushButton(groupBox);
        papier->setObjectName(QString::fromUtf8("papier"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/chifoumi/images/papier_115.png"), QSize(), QIcon::Normal, QIcon::On);
        papier->setIcon(icon1);
        papier->setIconSize(QSize(127, 128));

        horizontalLayout_3->addWidget(papier);

        ciseau = new QPushButton(groupBox);
        ciseau->setObjectName(QString::fromUtf8("ciseau"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/chifoumi/images/ciseau_115.png"), QSize(), QIcon::Normal, QIcon::On);
        ciseau->setIcon(icon2);
        ciseau->setIconSize(QSize(127, 128));

        horizontalLayout_3->addWidget(ciseau);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);


        horizontalLayout_6->addLayout(horizontalLayout_3);


        aaaaaaaaaa->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        bNewPartie = new QPushButton(centralwidget);
        bNewPartie->setObjectName(QString::fromUtf8("bNewPartie"));

        horizontalLayout->addWidget(bNewPartie);


        aaaaaaaaaa->addLayout(horizontalLayout);


        bbbbbbbbbbb->addLayout(aaaaaaaaaa);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        bbbbbbbbbbb->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(bbbbbbbbbbb);


        horizontalLayout_5->addLayout(verticalLayout_3);

        Chifoumi->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Chifoumi);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 623, 21));
        menu_Fichier = new QMenu(menubar);
        menu_Fichier->setObjectName(QString::fromUtf8("menu_Fichier"));
        menu_Aide = new QMenu(menubar);
        menu_Aide->setObjectName(QString::fromUtf8("menu_Aide"));
        Chifoumi->setMenuBar(menubar);
        statusbar = new QStatusBar(Chifoumi);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Chifoumi->setStatusBar(statusbar);

        menubar->addAction(menu_Fichier->menuAction());
        menubar->addAction(menu_Aide->menuAction());

        retranslateUi(Chifoumi);

        QMetaObject::connectSlotsByName(Chifoumi);
    } // setupUi

    void retranslateUi(QMainWindow *Chifoumi)
    {
        Chifoumi->setWindowTitle(QCoreApplication::translate("Chifoumi", "Chifoumi", nullptr));
        lJoueur->setText(QCoreApplication::translate("Chifoumi", "Vous", nullptr));
        scoreJoueur->setText(QCoreApplication::translate("Chifoumi", "0", nullptr));
        coupMachine->setText(QString());
        coupJoueur->setText(QString());
        lMachine->setText(QCoreApplication::translate("Chifoumi", "Machine", nullptr));
        scoreMachine->setText(QCoreApplication::translate("Chifoumi", "0", nullptr));
        versus->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("Chifoumi", "Choisissez une figure :", nullptr));
        pierre->setText(QString());
        papier->setText(QString());
        ciseau->setText(QString());
        bNewPartie->setText(QCoreApplication::translate("Chifoumi", "Nouvelle Partie", nullptr));
        menu_Fichier->setTitle(QCoreApplication::translate("Chifoumi", "&Fichier", nullptr));
        menu_Aide->setTitle(QCoreApplication::translate("Chifoumi", "&Aide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chifoumi: public Ui_Chifoumi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHIFOUMI_H
