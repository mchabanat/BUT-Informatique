/*
 Programme : tourRoue
 But :  determiner le nombre de roue qu une roue de velo va faire sur une certaine distance
 Date de dernière modification : 10/09/2021
 Auteur : Chabanat M
 Remarques : 
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    const double pi = 3.14;
    double rayonRoueCm; // valeur du rayon de la roue en centimetres
    double rayonRoueKm; // valeur du rayon de la roue en kilomètres
    double distanceKm; // distance a parcourir 
    double perimetreKm; // permietre d une roue de velo
    double nbTours; //nombre de tours d une roue de velo sur une distance donnee

    // TRAITEMENTS
    // saisie des données
    cout << "Entrez la distance a parcourir (en kilometres) : ";
    cin >> distanceKm;

    cout << "Entrez le rayon des roues du velo (en centimetres) : ";
    cin >> rayonRoueCm;

    //calcul du nombre de tours de la roue
    rayonRoueKm = rayonRoueCm / 100000 ;

    perimetreKm = 2 * pi * rayonRoueKm;

    nbTours = distanceKm / perimetreKm;

    //affichage du resultat
    cout << "Sur une distance de " << distanceKm << "km, une roue de velo doit faire " << nbTours << " tours." << endl;

    return 0;
}
