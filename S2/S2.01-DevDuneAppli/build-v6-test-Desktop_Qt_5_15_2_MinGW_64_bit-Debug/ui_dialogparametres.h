/********************************************************************************
** Form generated from reading UI file 'dialogparametres.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPARAMETRES_H
#define UI_DIALOGPARAMETRES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogParametres
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTitre;
    QGridLayout *gridLayout;
    QLabel *labelPtsMax;
    QSpinBox *inputPtsMax;
    QLabel *labelTitreTemps;
    QLineEdit *inputPseudo;
    QLabel *labelPseudo;
    QLabel *labelTempsMax;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *slider;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QPushButton *bConfirmer;

    void setupUi(QDialog *DialogParametres)
    {
        if (DialogParametres->objectName().isEmpty())
            DialogParametres->setObjectName(QString::fromUtf8("DialogParametres"));
        DialogParametres->resize(280, 211);
        DialogParametres->setMinimumSize(QSize(280, 211));
        DialogParametres->setMaximumSize(QSize(280, 211));
        verticalLayout = new QVBoxLayout(DialogParametres);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelTitre = new QLabel(DialogParametres);
        labelTitre->setObjectName(QString::fromUtf8("labelTitre"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        labelTitre->setFont(font);
        labelTitre->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelTitre);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelPtsMax = new QLabel(DialogParametres);
        labelPtsMax->setObjectName(QString::fromUtf8("labelPtsMax"));
        labelPtsMax->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelPtsMax, 1, 0, 1, 1);

        inputPtsMax = new QSpinBox(DialogParametres);
        inputPtsMax->setObjectName(QString::fromUtf8("inputPtsMax"));
        inputPtsMax->setMinimum(1);
        inputPtsMax->setMaximum(50);
        inputPtsMax->setValue(5);

        gridLayout->addWidget(inputPtsMax, 1, 1, 1, 1);

        labelTitreTemps = new QLabel(DialogParametres);
        labelTitreTemps->setObjectName(QString::fromUtf8("labelTitreTemps"));
        labelTitreTemps->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelTitreTemps, 2, 0, 1, 1);

        inputPseudo = new QLineEdit(DialogParametres);
        inputPseudo->setObjectName(QString::fromUtf8("inputPseudo"));

        gridLayout->addWidget(inputPseudo, 0, 1, 1, 1);

        labelPseudo = new QLabel(DialogParametres);
        labelPseudo->setObjectName(QString::fromUtf8("labelPseudo"));
        labelPseudo->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelPseudo, 0, 0, 1, 1);

        labelTempsMax = new QLabel(DialogParametres);
        labelTempsMax->setObjectName(QString::fromUtf8("labelTempsMax"));

        gridLayout->addWidget(labelTempsMax, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(DialogParametres);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        slider = new QSlider(DialogParametres);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setMinimum(5);
        slider->setSingleStep(5);
        slider->setValue(10);
        slider->setOrientation(Qt::Horizontal);
        slider->setTickInterval(0);

        horizontalLayout->addWidget(slider);

        label_2 = new QLabel(DialogParametres);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        bConfirmer = new QPushButton(DialogParametres);
        bConfirmer->setObjectName(QString::fromUtf8("bConfirmer"));

        verticalLayout->addWidget(bConfirmer);


        retranslateUi(DialogParametres);

        QMetaObject::connectSlotsByName(DialogParametres);
    } // setupUi

    void retranslateUi(QDialog *DialogParametres)
    {
        DialogParametres->setWindowTitle(QCoreApplication::translate("DialogParametres", "Dialog", nullptr));
        labelTitre->setText(QCoreApplication::translate("DialogParametres", "Param\303\250tres", nullptr));
        labelPtsMax->setText(QCoreApplication::translate("DialogParametres", "Nb max de points", nullptr));
        labelTitreTemps->setText(QCoreApplication::translate("DialogParametres", "Temps maximum (sec)", nullptr));
        labelPseudo->setText(QCoreApplication::translate("DialogParametres", "Pseudo", nullptr));
        labelTempsMax->setText(QCoreApplication::translate("DialogParametres", "10", nullptr));
        label->setText(QCoreApplication::translate("DialogParametres", "5", nullptr));
        label_2->setText(QCoreApplication::translate("DialogParametres", "120", nullptr));
        bConfirmer->setText(QCoreApplication::translate("DialogParametres", "Confirmer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogParametres: public Ui_DialogParametres {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPARAMETRES_H
