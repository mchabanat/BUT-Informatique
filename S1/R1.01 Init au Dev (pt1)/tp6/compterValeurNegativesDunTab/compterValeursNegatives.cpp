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
    int tab[NB_CASES] = {-12,25,85,-63,47,-58,123,456,-987,111111}; // 4 valeurs negtives
    unsigned int i;
    unsigned int nbValNeg = 0;

    // TRAITEMENTS
    // Affichage du tableau
    cout << "Tableau : " << endl;
    for (i = 0 ; i <= NB_CASES-1 ; i++)
    {
        cout << tab[i];
        cout << " ; ";
    }
    cout << " " << endl;
    cout << " " << endl;

    // Recherche du nb de valeur negatives
    for (i = 0 ; i <= NB_CASES-1 ; i++)
    {
        if (tab[i] < 0)
        {
            nbValNeg++;
        }
    }

    // Affichage du nbValNeg
    cout << "Nombre de valeurs negatives : " << nbValNeg;

    return 0;
}