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
    int tab[NB_CASES] = {12,25,85,63,47,58,123,456,987,111111};
    unsigned int i;

    // TRAITEMENTS
    for (i = 0 ; i <= NB_CASES-1 ; i++)
    {
        cout << tab[i] << endl;
    }
    
    return 0;
}