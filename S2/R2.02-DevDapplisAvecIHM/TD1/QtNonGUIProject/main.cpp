#include <QCoreApplication>
#include "maclasse.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MaClasse objet1(1);
    MaClasse objet2(1);

    QObject::connect(&objet1, SIGNAL(estEmis()),
                     &objet2, SLOT(recevoir()));
    objet1.emettre();

    return a.exec();
}
