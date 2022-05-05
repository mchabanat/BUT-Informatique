#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->bConnexion,SIGNAL(clicked()),this,SLOT(demandeConnexion()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::demandeConnexion()
{
    QString user = ui->inputUser->text();
    QString mdp = ui->inputMdp->text();

    if ((user == "moi") && (mdp == "moi"))
    {
        QMessageBox::information(this, "Connexion", "Connexion réussie");
        maDlg= new Dialog(this);
        this-> hide();
        maDlg->exec();
        this-> show();
    }
    else
    {
        QMessageBox::information(this, "Connexion", "Connexion erronée");
    }
}
