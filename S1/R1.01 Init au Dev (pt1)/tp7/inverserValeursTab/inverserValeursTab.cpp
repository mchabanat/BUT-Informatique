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
void inverserValeursTab(int tab[],unsigned int nbCases);
// BUT : inverser les valeurs d'un tableau tab de nbCases cases.



int main (void)
{
    // VARIABLES
    const unsigned int NB_CASES = 10;
    int tableau[NB_CASES] = {-10,5,-59,-95,12,423,78,-65,-40,10}; // 5 positives
    unsigned int i;

    // TRAITEMENTS
    // Affichage tableau avan modif
    cout << "Tableau avant modif : ";
    for (i = 0 ; i <= NB_CASES-1 ; i++)
    {
        cout << tableau[i] << " ; ";
    }
    cout << " " << endl;


    // Appel de la procedure
    inverserValeursTab(tableau,NB_CASES);

    // Affichage du resultat de l'échange
    
    cout << "Tableau apres modif : ";
    for (i = 0 ; i <= NB_CASES-1 ; i++)
    {
        cout << tableau[i] << " ; ";
    }
    return 0;
}


// Definition
void inverserValeursTab(int tab[],unsigned int nbCases)
{
    int borneFin;
    int copieValeur;

    if (nbCases %2 == 0)
    {
        borneFin = (nbCases/2);
    }
    else
    {
        borneFin = (nbCases-1)/2;
    }

    nbCases --;

    //Echange des valeurs

    for (int i=0; i<=borneFin; i++)
    {
        copieValeur=tab[i];
        tab[i]=tab[nbCases-i];
        tab[nbCases-i]=copieValeur;
    }
}