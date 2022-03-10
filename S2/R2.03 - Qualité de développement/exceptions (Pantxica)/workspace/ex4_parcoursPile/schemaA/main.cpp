/**************************************************************************
 * PROGRAMME : Pacours complet de pile - sans gestion d'exceptions
 * BUT : Parcoours complet de pile pour affichage                                       les exceptions
 * VERSION DE BASE : --
 * AUTEUR : Dagorret
 * DATE : 02/02/2022
 * REMARQUES : Il n'y a pas de schéma de récupération
 *             MAIS LE PARCOURS EST ROBUSTE.
 *             En effet, il y utilisation des OBSEVATEURS pour tester
 *             les pré-conditions et NE PAS faire lever les exceptions.
 *             
***************************************************************************/
#include <iostream>
using namespace std;
#include "pile.h"

int main()
{
    //Déclaration et initialisation de la pile
    UnePile maPile;
    initialiser(maPile);

    // Déclaration et peulement d'un tableau 
    const unsigned int TAILLE = 6;
    int monTab [TAILLE] = {0, 1, 2, 3, 4, 5};

    // maPile, monTab >> remplir pile >> maPile
    for (unsigned int i = 0 ; i < TAILLE; i++)
    {
        empiler(maPile, monTab[i]);
    }

    // Affichage du contenu de la pile
    while (true)
    {
        try
        {
            cout << sommet(maPile); 
        }
        catch(string)
        {
            break;
        }
        
        cout << "... ";
        depiler(maPile);
        
    }

    cout << endl << "au revoir..." << endl;
   
    return 0;
}