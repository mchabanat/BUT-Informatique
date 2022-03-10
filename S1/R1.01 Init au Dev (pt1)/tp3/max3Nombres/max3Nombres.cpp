/*
 Programme : max3Nombres
 But :  determiner, entre 3 nombres saisis, le plus grand des 3
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
    double nb3;
    double max;
    bool egal3 = false;

    // TRAITEMENTS
    cout << "Veuillez entrer une premiere valeur --> " ;
    cin >> nb1;

    cout << "Veuillez entrer une deuxieme valeur --> " ;
    cin >> nb2;

    cout << "Veuillez entrer une troisieme valeur --> " ;
    cin >> nb3;

    //comparaison des nb
    




    //Affichage du resultat
    if (egal3 == true)
    {
        cout << "Les 3 nombres sont egaux. Il n y a pas de max.";
        
    }
    else if(egal2 == true)
    {
        cout << "2 Nombres sont egaux. Le max est donc " << max;
    }
    else 
    {
        cout << "Bonsoir Jean-Jacques, le plus grand nombre entre les 3 est " << max;
    }
    return 0;
}