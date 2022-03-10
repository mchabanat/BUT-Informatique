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
double moyenneValeursTab(const double tab[], unsigned int nbCases);
/* BUT : Calculer la moyenne de toutes les valeurs du tableau tab de nbCases cases */


int main (void)
{
    // VARIABLES
    double moyValTab; // Moyenne du tableau tableau
    const unsigned int NB_CASES = 5;
    double tableau[NB_CASES] = {6,8,10,12,14};
    
    // TRAITEMENTS
    moyValTab = moyenneValeursTab(tableau,NB_CASES);

    cout << "La moyenne des valeurs du tableau est de " << moyValTab;


    return 0;
}


// Definition
double moyenneValeursTab(const double tab[], unsigned int nbCases)
{
    double somme = 0;
    double moyenne;
    unsigned int i;

    for(i=0 ; i <= nbCases -1 ; i++)
    {
        somme = somme + tab[i];
    } 

    moyenne = somme / nbCases;

    return moyenne;
}