/*
 Programme : 
 But : 
 Date de dernière modification : 
 Auteur : Chabanat M
 Remarques : ca fonctionne
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    const unsigned int NB_CASES = 10;
    int tab[NB_CASES] = {-12,25,85,-63,47,-58,123,456,-987,1111}; 
    unsigned int i;
    double moyenne = 0;
    double somme = 0;


    // TRAITEMENTS
    cout << "Tableau : " << endl;
    for (i = 0 ; i <= NB_CASES-1 ; i++)
    {
        cout << tab[i];
        cout << " ; ";
    }
    cout << " " << endl;
    cout << " " << endl;

    for (i = 0 ; i <= NB_CASES-1 ; i++)
    {
        somme= somme + tab[i];
    }

    // Calcul moyenne
    moyenne = somme / NB_CASES;

    // Affichage moyenne
    cout << "Moyenne = " << moyenne;
    
    return 0;
}