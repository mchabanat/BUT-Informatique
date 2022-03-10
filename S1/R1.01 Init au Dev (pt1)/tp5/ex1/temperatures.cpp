/*
 Programme : temperatures
 But : l'utilisateur saisi 12 temperatures que l'on place dans un tableau
 Date de dernière modification : 07/10/21
 Auteur : Chabanat M
 Remarques : ca fonctionne
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    const unsigned short int NB_CASES = 12; // nombre de cases dans le tableau
    float tabTemp[NB_CASES]; // tableau où on viendra placer les temperatures saisies
    float temp; // une temperature 

    unsigned int i; // compteur de la boucle

    // TRAITEMENTS
    for (i = 0 ; i <= NB_CASES -1 ; i++)
    {
        // Saisie d'une temperature
        cout << "Saisie une valeur chakal : ";
        cin >> temp;

        // Placement de la temperature dans le tab
        tabTemp[i] = temp;
    }



    return 0;
}