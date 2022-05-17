/********************************************************************************
** Form generated from reading UI file 'quest.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUEST_H
#define UI_QUEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Quest
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *nom;
    QLabel *prenom;
    QLineEdit *inputName;
    QLineEdit *inputSurname;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QRadioButton *radioAge;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Quest)
    {
        if (Quest->objectName().isEmpty())
            Quest->setObjectName(QString::fromUtf8("Quest"));
        Quest->resize(218, 152);
        verticalLayout_2 = new QVBoxLayout(Quest);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        nom = new QLabel(Quest);
        nom->setObjectName(QString::fromUtf8("nom"));

        gridLayout->addWidget(nom, 0, 0, 1, 1);

        prenom = new QLabel(Quest);
        prenom->setObjectName(QString::fromUtf8("prenom"));

        gridLayout->addWidget(prenom, 1, 0, 1, 1);

        inputName = new QLineEdit(Quest);
        inputName->setObjectName(QString::fromUtf8("inputName"));

        gridLayout->addWidget(inputName, 0, 1, 1, 1);

        inputSurname = new QLineEdit(Quest);
        inputSurname->setObjectName(QString::fromUtf8("inputSurname"));

        gridLayout->addWidget(inputSurname, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        radioAge = new QRadioButton(Quest);
        radioAge->setObjectName(QString::fromUtf8("radioAge"));

        horizontalLayout->addWidget(radioAge);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(Quest);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Quest);
        QObject::connect(buttonBox, SIGNAL(accepted()), Quest, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Quest, SLOT(reject()));

        QMetaObject::connectSlotsByName(Quest);
    } // setupUi

    void retranslateUi(QDialog *Quest)
    {
        Quest->setWindowTitle(QCoreApplication::translate("Quest", "Dialog", nullptr));
        nom->setText(QCoreApplication::translate("Quest", "Nom", nullptr));
        prenom->setText(QCoreApplication::translate("Quest", "Pr\303\251nom", nullptr));
        radioAge->setText(QCoreApplication::translate("Quest", "Avez-vous plus de 18 ans ?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Quest: public Ui_Quest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUEST_H
