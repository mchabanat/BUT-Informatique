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
void echangerCasesTab(int tab[] , unsigned int indiceCase1 , unsigned int indiceCase2);
// BUT : echanger les valeurs de 2 cases (d'indices indiceCase1 et indiceCase2) d'un tableau tab.
//       les 2 indices sont supposes valides : compris entre 0 et (nbCases-1)


int main (void)
{
    // VARIABLES
    const unsigned int NB_CASES = 5;
    unsigned int indice1;
    unsigned int indice2;
    int tableau[NB_CASES] = {50,40,80,12,10};

    // TRAITEMENTS
    // Saisie des 2 valeurs
    cout << "Saisir l indice de la premiere case a echanger : ";
    cin >> indice1;

    cout << "Saisir l indice de la deuxieme case a echange : ";
    cin >> indice2;

    // Appel de la procedure
    echangerCasesTab(tableau,indice1,indice2);

    // Affichage du resultat de l'échange
    cout << "Premiere case apres echange : " << tableau[indice1] << endl;
    cout << "Deuxieme case apres echange : " << tableau[indice2] << endl;

    return 0;
}



// Definition
void echangerCasesTab(int tab[] , unsigned int indiceCase1 , unsigned int indiceCase2)
{
    int copieIndice2;

    copieIndice2 = tab[indiceCase2];
    tab[indiceCase2] = tab[indiceCase1];
    tab[indiceCase1] = copieIndice2;
}