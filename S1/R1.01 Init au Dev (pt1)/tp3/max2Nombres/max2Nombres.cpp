/*
 Programme : max2Nombres
 But :  determiner entre 2 nombres saisis le plus grand des 2
 Date de dernière modification : 16/09/21
 Auteur : Chabanat M
 Remarques : ca fonctionne
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    double nb1;
    double nb2;
    double max;
    bool egal = false;

    // TRAITEMENTS
    cout << "Veuillez entrer une premiere valeur --> " ;
    cin >> nb1;

    cout << "Veuillez entrer une deuxieme valeur --> " ;
    cin >> nb2;

    //comparaison des nb
    if (nb1 < nb2)
    {
        max = nb2;
    }
    else if (nb2 < nb1)
    {
        max = nb1;
    }
    else 
    {
        egal = true;
    }

    //Affichage du resultat
    if (egal == false)
    {
        cout << "Bonsoir Jean-Jacques, le plus grand nombre est " << max;
    }
    else
    {
        cout << "Les 2 nombres sont egaux. Il n y a pas de max.";
    }
    return 0;
}