/*
 Programme : 
 But : 
 Date de dernière modification : 
 Auteur : Chabanat M
 Remarques : ca fonctionne 
*/

#include <iostream>
using namespace std;



// Declaration
void calculerPrixReduit(double prixInit , unsigned int reduction , double& prixReduit);
// BUT : calculer un prix après réduction (prixReduit) grace au pourcentage de réduction (reduction) et un prix initial (prixInitial)


int main (void)
{
    // VARIABLES
    double prixInitial;
    unsigned int reduc;
    double prixFinal;

    // TRAITEMENTS
    cout << "Entrez un prix de depart : ";
    cin >> prixInitial;

    cout << "Entrez un pourcentage de reduction : ";
    cin >> reduc;

    // Appel de la procedure
    calculerPrixReduit(prixInitial , reduc , prixFinal);

    // Affichage du prix final
    cout << "Le prix apres reduction est egal a : " << prixFinal << " euros.";

    return 0;
}



// Definition
void calculerPrixReduit(double prixInit , unsigned int reduction , double& prixReduit)
{
    prixReduit = prixInit - ((prixInit * reduction)/100);
}