#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cacherLabels();
    connect(ui->bDemarrer,SIGNAL(clicked()),this,SLOT(lancerQuestionnaire()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cacherLabels()
{
    ui->labelNomSaisi->setHidden(true);
    ui->labelPrenom->setHidden(true);
    ui->labelMajorite->setHidden(true);
    ui->labelNbEnfant->setHidden(true);

    ui->valeurNomSaisi->setHidden(true);
    ui->valeurPrenomSaisi->setHidden(true);
    ui->valeurMajoriteSaisie->setHidden(true);
    ui->valeurNbEnfantSaisie->setHidden(true);
}

void MainWindow::lancerQuestionnaire()
{
    Dialog * monQuest= new Dialog(this);
    monQuest->exec();

    bool nomPrenomOk = false;
    bool estMajeur = false;

    // Saisie nom, prenom
    if (monQuest->getNom() != "" && monQuest->getPrenom() != "")
    {
        nomPrenomOk=true;
    }

    if (monQuest->getMajorite())
    {
        estMajeur=true;
    }

    // Quand il n'est pas majeur
    if (nomPrenomOk)
    {
        ui->labelNomSaisi->setVisible(true);
        ui->valeurNomSaisi->setText(monQuest->getNom());
        ui->valeurNomSaisi->setVisible(true);

        ui->labelPrenom->setVisible(true);
        ui->valeurPrenomSaisi->setText(monQuest->getPrenom());
        ui->valeurPrenomSaisi->setVisible(true);

        ui->labelMajorite->setVisible(true);

        if (!estMajeur)
        {
            ui->valeurMajoriteSaisie->setText("Mineur(e)");
        }
        else
        {
            ui->valeurMajoriteSaisie->setText("Majeur(e)");
            // Saisie nb gosses
            bool ok;
            int nbGosses = QInputDialog::getInt(this,
                                                tr("Nombre de gosses"),
                                                tr("Combien de gosses avez-vous ?"),
                                                0,0,10,1,&ok);
            ui->labelNbEnfant->setVisible(true);
            ui->valeurNbEnfantSaisie->setText(QString::number(nbGosses));
            ui->valeurNbEnfantSaisie->setVisible(true);
        }

        ui->valeurMajoriteSaisie->setVisible(true);


    }
}

