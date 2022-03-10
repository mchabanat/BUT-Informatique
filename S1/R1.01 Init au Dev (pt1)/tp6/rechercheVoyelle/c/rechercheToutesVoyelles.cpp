/*
 Programme : 
 But : 
 Date de dernière modification : 
 Auteur : Chabanat M
 Remarques : ca fonctionne pas
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    string tab = "chabachatte"; 
    unsigned int longueurTab = tab.size();
    unsigned int posCourante = 0;
    unsigned int nbVoyelle = 0;
    
    cout << tab << endl;
    cout << " " << endl;

    // TRAITEMENTS
    for (posCourante = 0 ; posCourante <= longueurTab - 1 ; posCourante++)
    {
        if (tab[posCourante] == 'a' || tab[posCourante] == 'e'|| tab[posCourante] == 'i' || 
            tab[posCourante] == 'o' || tab[posCourante] == 'u' || tab[posCourante] == 'y')
        {
            nbVoyelle++;
            cout << "Position de la " << nbVoyelle << "eme voyelle : " << posCourante << endl;
        }
    }

    // Affichage de la position de la premiere voyelle s'il y en a une
    if (nbVoyelle == 0)
    {
        cout << "Il n y a pas de voyelle dans le mot";
    }
    
    
    return 0;
}