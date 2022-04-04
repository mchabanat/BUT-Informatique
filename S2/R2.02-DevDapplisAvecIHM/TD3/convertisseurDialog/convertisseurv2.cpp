#include "convertisseurv2.h"

convertisseurv2::convertisseurv2(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Convertisseur de températures"));
    labelConvertisseur = new QLabel("Convertisseur de températures",this);
    labelCels = new QLabel("degrés celsius",this);
    labelFgt = new QLabel("degrés Fahrenheit",this);
    labelResult = new QLabel("---.---",this);
    inputTemp = new QLineEdit(this);
    inputTemp->setMaximumWidth(75);
    eraseButton = new QPushButton("Effacer",this);
    convertButton = new QPushButton("Convertir",this);
    convertButton->setDisabled(true);
    quitButton = new QPushButton("Quitter",this);


    labelConvertisseur->setFont(QFont("Arial",14,QFont::Bold));
    labelResult->setFont(QFont("Arial",11,QFont::Normal));

    // Connexion
    //quitButton
        //Methode1
    /*QCoreApplication* appliCourante = QCoreApplication::instance();
    QObject::connect(quitButton,SIGNAL(clicked()),appliCourante,SLOT (quit()));*/

        //Methode2
    QObject::connect(quitButton,SIGNAL(clicked()),this,SLOT (close()));

    //eraseButton
    QObject::connect(eraseButton,SIGNAL(clicked()),inputTemp,SLOT (clear()));
    QObject::connect(eraseButton,SIGNAL(clicked()),this,SLOT (effacer()));

    //convertButton
    QObject::connect(inputTemp,SIGNAL(textChanged(QString)),this,SLOT(saisiVerif()));
    QObject::connect(convertButton,SIGNAL(clicked()),this,SLOT (convertir()));

    //On gère l'ordre de tabulation
    QWidget::setTabOrder(inputTemp, convertButton);
    QWidget::setTabOrder(convertButton, eraseButton);
    QWidget::setTabOrder(eraseButton, quitButton);

    // Layouts
    QVBoxLayout *vTitleLayout = new QVBoxLayout;
    QGridLayout *vGrilleTop = new QGridLayout; // partie haute de la fenetre
    QHBoxLayout *hButtonsLayout = new QHBoxLayout; // 3 boutons du bas
    QVBoxLayout *vAllLayout = new QVBoxLayout; // tous les éléments
    QHBoxLayout *hPrincipalLayout = new QHBoxLayout;


    //Réglages des layouts
    vTitleLayout->addWidget(labelConvertisseur);

    vGrilleTop->addWidget(labelCels,1,0,1,1);
    vGrilleTop->addWidget(labelFgt,1,1,1,1);
    vGrilleTop->addWidget(inputTemp,2,0,1,1);
    vGrilleTop->addWidget(labelResult,2,1,1,1);

    hButtonsLayout->addWidget(convertButton);
    hButtonsLayout->addWidget(eraseButton);
    hButtonsLayout->addStretch();
    hButtonsLayout->addWidget(quitButton);

    vAllLayout->addLayout(vTitleLayout);
    vAllLayout->addStretch(1);
    vAllLayout->addLayout(vGrilleTop);
    vAllLayout->addStretch(3);
    vAllLayout->addLayout(hButtonsLayout);

    hPrincipalLayout->addStretch(1); // Mettre un 1 dans les stretchs dit qu'ils grandiront de la meme facon
    hPrincipalLayout->addLayout(vAllLayout,0); // le 0 dit que le layout ne grandira pas en horizontal
    hPrincipalLayout->addStretch(1);

    setLayout(hPrincipalLayout);
}

void convertisseurv2::saisiVerif()
{
    if(inputTemp->text().isEmpty())
    {
        convertButton->setEnabled(false);
    }
    else
    {
        convertButton->setEnabled(true);
    }
}

void convertisseurv2::convertir()
{
    QString valSaisie = inputTemp->text();
    double val = valSaisie.toDouble();
    val = (val * 9 / 5)+32;
    QString valDansLabel = QString::number(val);
    labelResult->setText(valDansLabel);
}

void convertisseurv2::effacer()
{
    labelResult->setText("---.---");
}


convertisseurv2::~convertisseurv2()
{
}

