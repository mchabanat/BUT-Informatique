#include "convertisseurtemp.h"

ConvertisseurTemp::ConvertisseurTemp(QWidget *parent) : QWidget(parent)
{
    //appTitle = new QLabel ("Convertisseur de températures",this);
    labelConvertisseur = new QLabel("Convertisseur de températures",this);
    labelCels = new QLabel("degrés celsius",this);
    labelFgt = new QLabel("degrés Fahrenheit",this);
    labelResult = new QLabel("---.---",this);
    inputTemp = new QLineEdit(this);
    eraseButton = new QPushButton("Effacer",this);
    convertButton = new QPushButton("Convertir",this);
    quitButton = new QPushButton("Quitter",this);


    labelConvertisseur->setFont(QFont("Arial",14,QFont::Bold));
    labelConvertisseur->setGeometry(16,20,430,30);

    labelCels->setGeometry(116,70,101,20);
    labelFgt->setGeometry(256,70,125,20);

    inputTemp->setGeometry(116,92,91,26);

    labelResult->setFont(QFont("Arial",11,QFont::Normal));
    labelResult->setGeometry(256,93,63,20);

    eraseButton->setGeometry(16,160,93,29);
    convertButton->setGeometry(116,160,93,29);
    quitButton->setGeometry(336,160,93,29);

    // Connexion
    //quitButton
        //Methode1
    /*QCoreApplication* appliCourante = QCoreApplication::instance();
    QObject::connect(quitButton,SIGNAL(clicked()),appliCourante,SLOT (quit()));*/

        //Methode2
    QObject::connect(quitButton,SIGNAL(clicked()),this,SLOT (close()));

    //eraseButton
    QObject::connect(eraseButton,SIGNAL(clicked()),inputTemp,SLOT (clear()));

    //convertButton
    QObject::connect(convertButton,SIGNAL(clicked()),inputTemp,SLOT (copy()));
}

ConvertisseurTemp::~ConvertisseurTemp()
{
}



