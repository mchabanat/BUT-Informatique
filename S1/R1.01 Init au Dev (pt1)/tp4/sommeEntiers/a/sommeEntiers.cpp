/*
 Programme : sommeEntiers
 But : afficher la somme de tous les entiers entre 1 et la borne de fin saisie par l'utilisateur
 Date de dernière modification : 23/09/21
 Auteur : Chabanat M
 Remarques : ca fonctionne
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    int borneSup; // borne de fin 
    int somme = 0; // somme a afficher

    int i; // compteur de la boucle

    // TRAITEMENTS
    // saisir la borne
    cout << "Saisir la borne de fin svp : " << endl;
    cin >> borneSup;

    // cumuler les valeurs entre 1 et la borne de fin
    for (i=1 ; i <= borneSup ; i++)
    {
        somme = somme + i;
    }

    cout << "Somme : " << somme;
    return 0;
}