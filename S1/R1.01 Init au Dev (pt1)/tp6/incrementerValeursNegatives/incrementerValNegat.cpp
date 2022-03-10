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
    int tab[NB_CASES] = {-12,25,85,-63,47,-58,123,456,-987,111111};
    unsigned int i;

    // TRAITEMENTS
    // Affichage du tableau avant traitement
    cout << "Tableau avant traitement : " << endl;
    for (i = 0 ; i <= NB_CASES-1 ; i++)
    {
        cout << tab[i];
        cout << " ; ";
    }
    cout << " " << endl;
    cout << " " << endl;
    // Incrementation des valeurs negatives
    for (i = 0 ; i <= NB_CASES-1 ; i++)
    {
        if (tab[i] < 0)
        {
            tab[i] = tab[i]+1;
        }
    }

    // Affichage du tableau après traitement
    cout << "Tableau apres traitement : " << endl;
    for (i = 0 ; i <= NB_CASES-1 ; i++)
    {
        cout << tab[i];
        cout << " ; ";
    }

    return 0;
}