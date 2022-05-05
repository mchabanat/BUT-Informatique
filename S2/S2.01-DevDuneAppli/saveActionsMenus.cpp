// Déclararion
void aProposDe();

// Dans le cpp

//Menus
connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
connect(ui->actionA_propos_de, SIGNAL(triggered()), this, SLOT(aProposDe()));


void Chifoumi::aProposDe()
{
    QMessageBox *msgBox = new QMessageBox;
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->setWindowTitle("A propos de l'application");
    msgBox->setText("Tom, Angel, Matis -> gros bgs");
    msgBox->exec();
}