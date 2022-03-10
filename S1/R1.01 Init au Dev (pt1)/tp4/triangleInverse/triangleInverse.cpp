/*
 Programme : afficherTriangleInverse
 But : demander a l'utilisateur un nombre entier de ligne puis afficher un triangle inversé composé du nombre de ligne saisi par l'utilisateur
 Date de dernière modification : 24/09/21
 Auteur : Chabanat M
 Remarques : ca fonctionne
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    int nbreDeLignes; // nombre de lignes a afficher

    int i; // compteur de la boucle
    int j; // compteur de la 2e boucle

    // TRAITEMENTS
    // saisie du nbreDeLignes
    cout << "Entrez un nombre de lignes pour afficher un triangle : ";
    cin >> nbreDeLignes;

    while (!(nbreDeLignes >= 2))
    {
        cout << "Veuillez entrer un nombre de ligne superieur ou egal a 2 : ";
        cin >> nbreDeLignes;
    }

    for (i = nbreDeLignes ; i >= 1 ; i--)
    {
        for (j = i ; j >= 1 ; j--)
        {
            cout << '*';
        }
        cout << " " << endl;
    }
    return 0;
}