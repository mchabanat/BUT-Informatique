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
bool estUneNote(float nombre);
/* BUT : Retourne si la valeur nombre est comprise entre 0 et 20 et est donc une note */


int main (void)
{
    // VARIABLES
    float valeur;
    bool note;
    // TRAITEMENTS
    cout << "Saisissez un nombre dont on va determiner si c est une note ou pas : ";
    cin >> valeur;

    note = estUneNote(valeur);

    if (note == true)
    {
        cout << "Le nombre " << valeur << " est bien une note ";
    }
    else 
    {
        cout << "Le nombre " << valeur << " n est pas une note ";
    }
    


    return 0;
}


// Definition
bool estUneNote(float nombre)
{
    if (nombre >= 0 && nombre <= 20)
    {
        return true;
    }
    else
    {
        return false;
    }
}