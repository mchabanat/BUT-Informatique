#include <QCoreApplication>
#include "maclasse.h"

void etape1();
void etape2();
void etape3();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    etape3();

    return a.exec();
}

void etape1()
{
    MaClasse objet1(1);
    MaClasse objet2(2);

    QObject::connect(&objet1,SIGNAL(estEmis(int)),&objet2,SLOT (recevoir(int)));

    objet1.emettre();
}

void etape2()
{
    MaClasse objet1(1);
    MaClasse objet2(2);
    MaClasse objet3(3);
    MaClasse objet4(4);

    QObject::connect(&objet1,SIGNAL(estEmis(int)),&objet2,SLOT (recevoir(int)));
    objet1.emettre();
    QObject::disconnect(&objet1,SIGNAL(estEmis(int)),&objet2,SLOT (recevoir(int)));

    QObject::connect(&objet1,SIGNAL(estEmis(int)),&objet3,SLOT (recevoir(int)));
    QObject::connect(&objet1,SIGNAL(estEmis(int)),&objet4,SLOT (recevoir(int)));
    objet1.emettre();
}

void etape3()
{
    MaClasse objet1(1);
    MaClasse objet2(2);

    objet1.estEmis(objet1.getNumero());

    objet1.quit();
}
