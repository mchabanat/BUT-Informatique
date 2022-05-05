#include "convertisseurtemp.h"

ConvertisseurTemp::ConvertisseurTemp(QWidget *parent) : QWidget(parent)
{
    setWindowTitle(tr("Convertisseur de températures"));
    labelConvertisseur = new QLabel("Convertisseur de températures",this);
    labelCels = new QLabel("degrés celsius",this);
    labelFgt = new QLabel("degrés Fahrenheit",this);
    labelResult = new QLabel("---.---",this);
    inputTemp = new QLineEdit(this);
    eraseButton = new QPushButton("Effacer",this);
    convertButton = new QPushButton("Convertir",this);
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
    QObject::connect(convertButton,SIGNAL(clicked()),this,SLOT (convertir()));

    //On gère l'ordre de tabulation
    QWidget::setTabOrder(inputTemp, convertButton);
    QWidget::setTabOrder(convertButton, eraseButton);
    QWidget::setTabOrder(eraseButton, quitButton);

    // Layouts
    QGridLayout *vGrilleTop = new QGridLayout; // partie haute de la fenetre
    QHBoxLayout *hButtonsLayout = new QHBoxLayout; // 3 boutons du bas
    QVBoxLayout *vAllLayout = new QVBoxLayout; // tous les éléments
    QHBoxLayout *hPrincipalLayout = new QHBoxLayout;
    QVBoxLayout *vTitleLayout = new QVBoxLayout;


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

void ConvertisseurTemp::convertir()
{
    QString valSaisie = inputTemp->text();
    double val = valSaisie.toDouble();
    val = (val * 9 / 5)+32;
    QString valDansLabel = QString::number(val);
    labelResult->setText(valDansLabel);
}

void ConvertisseurTemp::effacer()
{
    labelResult->setText("---.---");
}

ConvertisseurTemp::~ConvertisseurTemp()
{
}





