#include "testselectbdd.h"
#include "ui_testselectbdd.h"

testSelectBDD::testSelectBDD(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::testSelectBDD)
    , db(new Database())
{
    ui->setupUi(this);
    db->openDataBase();

    QSqlQuery maRqt;
    maRqt.exec("SELECT Article.Reference,Article.Descriptif,Article.PrixHT,Categorie.Libelle FROM Article JOIN Categorie ON Article.CodeCategorie=Categorie.CodeCategorie GROUP BY Article.Reference");

    for(int i = 0; maRqt.next(); i++){
        qDebug() << maRqt.value(0) << maRqt.value(1) << maRqt.value(2) << Qt::endl;
    }

}

testSelectBDD::~testSelectBDD()
{
    delete ui;
}

