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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testSelectBDD
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *titre;
    QTableWidget *tableau;
    QSpacerItem *verticalSpacer;
    QPushButton *bQuitter;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *testSelectBDD)
    {
        if (testSelectBDD->objectName().isEmpty())
            testSelectBDD->setObjectName(QString::fromUtf8("testSelectBDD"));
        testSelectBDD->resize(422, 374);
        centralwidget = new QWidget(testSelectBDD);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titre = new QLabel(centralwidget);
        titre->setObjectName(QString::fromUtf8("titre"));
        QFont font;
        font.setPointSize(20);
        titre->setFont(font);
        titre->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titre);

        tableau = new QTableWidget(centralwidget);
        if (tableau->columnCount() < 4)
            tableau->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableau->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableau->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableau->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableau->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableau->setObjectName(QString::fromUtf8("tableau"));

        verticalLayout->addWidget(tableau);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        bQuitter = new QPushButton(centralwidget);
        bQuitter->setObjectName(QString::fromUtf8("bQuitter"));

        verticalLayout->addWidget(bQuitter);


        verticalLayout_2->addLayout(verticalLayout);

        testSelectBDD->setCentralWidget(centralwidget);
        menubar = new QMenuBar(testSelectBDD);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 422, 21));
        testSelectBDD->setMenuBar(menubar);
        statusbar = new QStatusBar(testSelectBDD);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        testSelectBDD->setStatusBar(statusbar);

        retranslateUi(testSelectBDD);

        QMetaObject::connectSlotsByName(testSelectBDD);
    } // setupUi

    void retranslateUi(QMainWindow *testSelectBDD)
    {
        testSelectBDD->setWindowTitle(QCoreApplication::translate("testSelectBDD", "testSelectBDD", nullptr));
        titre->setText(QCoreApplication::translate("testSelectBDD", "Interface Utilisateur", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableau->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("testSelectBDD", "Reference Article", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableau->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("testSelectBDD", "Libell\303\251 Article", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableau->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("testSelectBDD", "Prix unitaire HT", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableau->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("testSelectBDD", "Libell\303\251 Cat\303\251gorie", nullptr));
        bQuitter->setText(QCoreApplication::translate("testSelectBDD", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class testSelectBDD: public Ui_testSelectBDD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTSELECTBDD_H
