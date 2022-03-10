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
    unsigned int posCourante = longueurTab-1;
    bool trouve = false;
    
    cout << tab << endl;
    // TRAITEMENTS
    while (posCourante >= 0)
    {
        if (tab[posCourante] == 'a' || tab[posCourante] == 'e'|| tab[posCourante] == 'i' || 
            tab[posCourante] == 'o' || tab[posCourante] == 'u' || tab[posCourante] == 'y')
        {
            trouve = true;
            break;
        }
        posCourante--;
    }

    // Affichage de la position de la premiere voyelle s'il y en a une
    if (trouve == true)
    {
        cout << "La premiere voyelle se trouve a la position " << posCourante;
    }
    else 
    {
        cout << "Il n y a pas de voyelle dans le mot";
    }
    
    return 0;
}