#include "convertisseurtemp.h"
#include "ui_convertisseurtemp.h"

ConvertisseurTemp::ConvertisseurTemp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ConvertisseurTemp)
{
    ui->setupUi(this);

    ui->bConvert->setDisabled(true);

    QWidget::setTabOrder(ui->input, ui->bConvert);
    QWidget::setTabOrder(ui->bConvert, ui->bEffacer);
    QWidget::setTabOrder(ui->bEffacer, ui->bQuitter);

    // Connexions
    //quitButton
    QObject::connect(ui->bQuitter,SIGNAL(clicked()),this,SLOT (close()));

    //eraseButton
    QObject::connect(ui->input,SIGNAL(textChanged(QString)),this,SLOT(activerConvertir()));
    QObject::connect(ui->bEffacer,SIGNAL(clicked()),this,SLOT (effacer()));

    //convertButton
    QObject::connect(ui->bConvert,SIGNAL(clicked()),this,SLOT (convertir()));

    //Actions
    connect(ui->actionConvertir, SIGNAL(triggered()), this, SLOT(convertir()));
    connect(ui->actionEffacer, SIGNAL(triggered()), this, SLOT(effacer()));
    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionA_propos_de, SIGNAL(triggered()), this, SLOT(aProposDe()));

}

void ConvertisseurTemp::convertir()
{
    QString valSaisie = ui->input->text();
    double val = valSaisie.toDouble();
    val = (val * 9 / 5)+32;
    QString valDansLabel = QString::number(val);
    ui->lResult->setText(valDansLabel);
}

void ConvertisseurTemp::effacer()
{
    ui->input->clear();
    ui->lResult->setText("---.---");
}

void ConvertisseurTemp::activerConvertir()
{
    if(ui->input->text().isEmpty())
    {
        ui->bConvert->setEnabled(false);
    }
    else
    {
        ui->bConvert->setEnabled(true);
    }
}

void ConvertisseurTemp::aProposDe()
{
    QMessageBox *msgBox = new QMessageBox;
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->setWindowTitle("A propos de l'application");
    msgBox->setText("Matis est un énorme bg <3");
    msgBox->exec();
}

ConvertisseurTemp::~ConvertisseurTemp()
{
    delete ui;
}

