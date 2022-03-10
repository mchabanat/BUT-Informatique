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
void afficherPrixReduit(double prixInit , unsigned int reduction);
// BUT : afficher un prix (prixInit) apres reduction grace au paramètre reduction


int main (void)
{
    // VARIABLES
    double prixInitial;
    unsigned int reduc;

    // TRAITEMENTS
    // Saisie de valeurs de prix et du pourcentage reduc
    cout << "Entrez un prix de depart : ";
    cin >> prixInitial;

    cout << "Entrez un pourcentage de reduction : ";
    cin >> reduc;
    // Appel de la procedure
    afficherPrixReduit(prixInitial,reduc);

    return 0;
}



// Definition
void afficherPrixReduit(double prixInit , unsigned int reduction)
{
    prixInit = prixInit - ((prixInit * reduction)/100);
    cout << "Prix Reduit = " << prixInit;
}