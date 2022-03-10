/*
 Programme : soldes
 But :  calculer une reduction avec un prix de depart et un pourcentage de solde
 Date de derniere modification : 10/09/2021
 Auteur : Matis Chab
 Remarques :
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES

    double prixDepart; // prix de depart saisi par l'utilisateur
    double solde; // pourcentage de reduc qu'on veut appliquer au prixDepart
    double reduc; // reduction calculee grace a prixDepart et solde
    double prixArrivee; // Prix apres reduction

    // TRAITEMENTS

    // clavier >> saisirPrixDepart >> prixDepart
    cout << "Donnez un prix :" << endl;
    cin >> prixDepart;

    // clavier >> saisirSolde >> solde
    cout << "Donnez un pourcentage de solde :" << endl;
    cin >> solde;

    // prixDepart, solde >> calculerReduc >> reduc
    reduc = (prixDepart * solde) / 100;

    // prixDepart, reduc >> calculerPrixArrivee >> prixArrivee
    prixArrivee = prixDepart - reduc;

    // prixArrivee >> afficherPrix2 >> ecran
    cout << "le prix apres la reduction est de " << prixArrivee << " euros." << endl;


    return 0;
}
