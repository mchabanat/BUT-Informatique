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
void compterValeurPositives(const int tab[],unsigned int nbCases,unsigned int& nbValPositives);
// BUT : compter le nb de valeurs positives (nbValPositives) d'un tableau tab de nbCases cases



int main (void)
{
    // VARIABLES
    const unsigned int NB_CASES = 10;
    int tableau[NB_CASES] = {-10,5,-59,-95,12,423,78,-65,-40,10}; // 5 positives
    unsigned int nbPositifs;

    // TRAITEMENTS
    // Appel de la procedure
    compterValeurPositives(tableau,NB_CASES,nbPositifs);

    // Affichage du resultat de l'échange
    cout << "LE nombre de valeurs positives est de : " << nbPositifs;

    return 0;
}



// Definition
void compterValeurPositives(const int tab[],unsigned int nbCases,unsigned int& nbValPositives)
{
    nbValPositives = 0;

    for (unsigned int i = 0 ; i <= nbCases-1 ; i++)
    {
        if (tab[i] >= 0)
        {
            nbValPositives++;
        }
    }
}