/*
 Programme : saisieVerifNote
 But :  determiner si la note saisie par l'utilisateur est bien comprise entre 0 et 20
 Date de dernière modification : 23/09/21
 Auteur : Chabanat M
 Remarques : ca fonctionne
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    int note; // représente la note saisie par l'utilisateur

    // TRAITEMENTS
    do
    {
        cout << "Entrez une note entre 0 et 20 : " << endl;
        cin >> note;
    }
    while (note < 0 || note > 20);

    cout << "Merci !" << endl;
     
    return 0;
}