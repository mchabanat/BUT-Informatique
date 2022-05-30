#include "convertisseurtemp.h"
#include "ui_convertisseurtemp.h"

#include <QRegExp>
#include <QRegExpValidator>
#include <QValidator>
#include <QMessageBox>

convertisseurTemp::convertisseurTemp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::convertisseurTemp)
{
    ui->setupUi(this);

    QRegExp charAutorises("[-,+]{0,1}[0-9]{0,3}");
    QRegExpValidator *validateur = new QRegExpValidator(charAutorises, this);

    ui->degresInput->setValidator(validateur);

    QObject::connect(ui->boutonEffacer, SIGNAL(clicked()), this, SLOT(remiseAZero()));
    QObject::connect(ui->boutonConvertir, SIGNAL(clicked()), this, SLOT(convertir()));
    QObject::connect(ui->boutonQuitter, SIGNAL(clicked()), this, SLOT(close()));

    QObject::connect(ui->sliderValeur, SIGNAL(valueChanged(int)), this, SLOT(sliderrrMoved(int)));
    QObject::connect(ui->degresInput, SIGNAL(textChanged(const QString &)), this, SLOT(degresCchanged(const QString &)));

    QObject::connect(ui->actionAPropos, SIGNAL(triggered()), this, SLOT(aProposDe()));
    QObject::connect(ui->actionConvertir, SIGNAL(triggered()), this, SLOT(convertir()));
}


float convertisseurTemp::convertirToFar(float cels) {
    return cels * 1.8 + 32;
}

void convertisseurTemp::remiseAZero() {
    ui->degresFlabel->setText("32");
    ui->degresInput->clear();
}

void convertisseurTemp::convertir() {
    bool estBienConverti = true;


    float celsius = ui->degresInput->text().toFloat(& estBienConverti);

    if (estBienConverti) {

        float farhenheit = convertirToFar(celsius);
        QString farhenConv;
        farhenConv.QString::setNum(farhenheit);
        ui->degresFlabel->setText(farhenConv);
    }

}


void convertisseurTemp::aProposDe() {
    QMessageBox *messageBox;
    messageBox = new QMessageBox(this);

    messageBox->setWindowTitle("Erreur de conversion.");
    messageBox->setText("ouui");
    messageBox->setDefaultButton(QMessageBox::Ok);

    messageBox->exec();

}

void convertisseurTemp::sliderrrMoved(int valeur) {
    QString sliderValue;
    sliderValue.QString::setNum(valeur);
    ui->degresInput->setText(sliderValue);
}

void convertisseurTemp::degresCchanged(const QString & valeur) {
    ui->sliderValeur->setValue(valeur.toInt());
    convertir();
}

convertisseurTemp::~convertisseurTemp() {
}
