#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::getPrenom()
{
    if (ui->inputSurname->text().isEmpty())
    {
        return "";
    }
    else
    {
        return ui->inputSurname->text();
    }
}

QString Dialog::getNom()
{
    if (ui->inputName->text().isEmpty())
    {
        return "";
    }
    else
    {
        return ui->inputName->text();
    }
}

bool Dialog::getMajorite()
{
    if (ui->radioAge->isChecked())
    {
        return true;
    }
    else
    {
        return false;
    }
}
