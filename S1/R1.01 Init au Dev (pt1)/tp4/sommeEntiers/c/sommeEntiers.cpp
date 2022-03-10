/*
 Programme : sommeEntiers version b
 But : afficher la somme de tous les entiers entre une borne de debut et une borne de fin saisie par l'utilisateur
 Date de dernière modification : 23/09/21
 Auteur : Chabanat M
 Remarques : ca fonctionne
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    int borneInf; // borne de debut
    int borneSup; // borne de fin 
    int somme = 0; // somme a afficher

    int i; // compteur de la boucle

    // TRAITEMENTS
    // Saisir la borne de debut 

    cout << "Saisir la borne de debut svp : " << endl;
    cin >> borneInf;

    // saisir la borne de fin

    cout << "Saisir la borne de fin svp : " << endl;
    cin >> borneSup;


    if (borneInf < borneSup)
    {
        for (i = borneInf ; i <= borneSup ; i++)
        {
            somme = somme + i;
        }
    }
    

    
    // cumuler les valeurs entre 1 et la borne de fin
    

    cout << "Somme : " << somme;
    return 0;
}