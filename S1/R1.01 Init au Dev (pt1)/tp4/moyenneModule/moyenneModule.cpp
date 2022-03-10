/*
 Programme : moyenneModule
 But : determiner la moyenne d'un module grace a 10 notes saisies par l'utilisateur
 Date de dernière modification : 23/09/21
 Auteur : Chabanat M
 Remarques : ca fonctionne
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    double sommeNotes = 0;
    double note;
    double moyenne;

    int i;

    // TRAITEMENTS
    cout << "Entrez les 10 notes du module : " << endl;

    // saisie des notes 
    for (i=1 ; i <= 10 ; i++)
    {
        cin >> note;

        sommeNotes = sommeNotes + note;
    }

    // Calcul de la moyenne
    moyenne = sommeNotes / 10;

    // Affichage de la moyenne
    cout << "Moyenne : " << moyenne ;
     
    return 0;
}