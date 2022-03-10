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
double valAbsolue(float valeur);
/* BUT : Retourner la valeur absolue d'un nombre valeur*/


int main (void)
{
    // VARIABLES
    float nombre;
    

    // TRAITEMENTS
    cout << "Saisissez un nombre positif ou negatif : ";
    cin >> nombre;

    cout << "La valeur absolue de " << nombre << " est " <<  valAbsolue(nombre);


    return 0;
}


// Definition
double valAbsolue(float valeur)
{
    return (valeur < 0 ? -valeur : valeur);
}