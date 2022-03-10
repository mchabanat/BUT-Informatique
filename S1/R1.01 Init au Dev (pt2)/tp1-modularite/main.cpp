/*
 Programme : test du module Fractions
 But :  Tester la conformité de chaque fonctionnalité du module Fractions
        par rapport aux jeux d'essais prévus
 Date de dernière modification : xxxx
 Auteur : xxx
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - td n°2
*/

#include "Fractions.h"

void testerAfficher();
// BUT : tester le sous programme afficher() du module Fractions

void testerSaisir();
// BUT : tester le sous programme saisir() du module Fractions

void testerAdditionner();
// BUT : tester le sous programme additionner() du module Fractions

void testerReduire();
// BUT : tester le sous programme reduire() du module Fractions

void testerEstEgal();
// BUT : tester le sous programme estEgal() du module Fractions

int main()
{
    Fraction maFraction = FRACTIONNULLE;
    afficher(maFraction);
    testerAdditionner();

    return 0;
}

// Corps des sous programmes de main()
void testerAfficher()
{
    afficher({1, 3});
    cout << endl;
    afficher({-1, 3});
    cout << endl;
    afficher({0, 1});
    cout << endl;
    afficher(FRACTIONNULLE);
    cout << endl;
    afficher({1, 1});
    cout << endl;
}

void testerSaisir()
{
    Fraction bonsoir;

    bonsoir = saisir();
}

void testerAdditionner()
{
    afficher(additionner({5, 4}, {10, 5}));
    afficher(additionner({25, 20}, {40, 20}));
}

void testerReduire()
{
    Fraction fracResultat;

    fracResultat = reduire({9, 3});
    afficher(fracResultat);
    cout << endl;

    fracResultat = reduire({-27, 3});
    afficher(fracResultat);
    cout << endl;
}

void testerEstEgal()
{
    Fraction fracA = {27, 9};
    Fraction fracB = {9, 3};

    bool egalite = false;
    egalite = estEgal(fracA, fracB);

    if (egalite)
    {
        cout << "Les 2 fractions sont egales" << endl;
    }
    else
    {
        cout << "Les 2 fractions ne sont pas egales" << endl;
    }
}