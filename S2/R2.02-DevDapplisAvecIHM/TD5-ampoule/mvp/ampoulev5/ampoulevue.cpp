#include "ampoulevue.h"
#include "ui_ampoulevue.h"

AmpouleVue::AmpouleVue(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AmpouleVue)
{
    ui->setupUi(this);
}

AmpouleVue::~AmpouleVue()
{
    delete ui;
}

void AmpouleVue::nvlleConnexion(QObject *c)
{
    //pour se connecter avec la presentation
    QObject::connect(ui->bLumiere, SIGNAL(pressed()), c, SLOT(demandeChangerEtat()));
    QObject::connect(ui->bLumiere, SIGNAL(released()), c, SLOT(demandeChangerEtat()));
}

void AmpouleVue::supprConnexion(QObject *c)
{
    //pour se déconnecter de c
    QObject::disconnect(ui->bLumiere, SIGNAL(pressed()), c, SLOT(demandeChangerEtat()));
    QObject::disconnect(ui->bLumiere, SIGNAL(released()), c, SLOT(demandeChangerEtat()));
}

void AmpouleVue::majInterface(Modele::UnEtat e)
{
    switch (e) {
        case Modele::allume :
            ui->labelEtat->setText("allumé !");
            ui->bLumiere->setText("Relachez pour Eteindre");
            ui->labelEtat->setStyleSheet("QLabel { background-color: yellow; color: black; }");//fond jaune, texte noir
            break;
        case Modele::eteint :
            ui->labelEtat->setText("éteint !");
            ui->bLumiere->setText("Appuyez pour Allumer");
            ui->labelEtat->setStyleSheet("QLabel { background-color: black; color: white; }");//fond noir, texte blanc
            break;
        default: break;
    }
}

