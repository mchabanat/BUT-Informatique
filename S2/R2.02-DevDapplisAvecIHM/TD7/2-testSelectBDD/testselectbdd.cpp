#include "testselectbdd.h"
#include "ui_testselectbdd.h"

testSelectBDD::testSelectBDD(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::testSelectBDD)
    , db(new Database())
{
    ui->setupUi(this);
    //Quitter
    connect(ui->bQuitter,SIGNAL(clicked()),this,SLOT(close()));

    db->openDataBase();

    QSqlQuery maRqt;
    maRqt.exec("SELECT Article.Reference,Article.Descriptif,Article.PrixHT,Categorie.Libelle FROM Article JOIN Categorie ON Article.CodeCategorie=Categorie.CodeCategorie GROUP BY Article.Reference");

    for(int i = 0; maRqt.next(); i++){
        ui->tableau->insertRow(i);
        ui->tableau->setItem(i,0,new QTableWidgetItem(maRqt.value(0).toString()));
        ui->tableau->setItem(i,1,new QTableWidgetItem(maRqt.value(1).toString()));
        ui->tableau->setItem(i,2,new QTableWidgetItem(maRqt.value(2).toString()));
        ui->tableau->setItem(i,3,new QTableWidgetItem(maRqt.value(3).toString()));
    }

}

testSelectBDD::~testSelectBDD()
{
    delete ui;
}

