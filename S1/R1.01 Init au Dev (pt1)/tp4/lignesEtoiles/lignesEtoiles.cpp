/*
 Programme : lignesEtoiles
 But : Afficher une ligne avec des etoiles un certain nombre de fois. Ce nombre de fois sera defini par l'utilisateur qui saisira la valeur
 Date de dernière modification : 23/09/21
 Auteur : Chabanat M
 Remarques : ca fonctionne
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    int nbLigne; // représente le nombre de ligne que l'utilisateur veut afficher
    int i; // compteur de la boucle for

    // TRAITEMENTS
    do
    {
        cout << "Entrez le nombre de ligne a afficher : ";
        cin >> nbLigne;
    }
    while (nbLigne < 0);

    if (nbLigne > 0)
    {
        for (i=1 ; i <= nbLigne ; i++)
        {
            cout << "*****" << endl;
        }
    }
    
    return 0;
}