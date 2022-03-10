/*
 Programme : moyenneModule
 But : determiner la moyenne d'un module grace a 10 notes saisies par l'utilisateur
 Date de dernière modification : 24/09/21
 Auteur : Chabanat M
 Remarques : pas fini (l'erreur n'est pas activée quand la note est supérieure a 20)
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    double sommeNotes = 0;
    double note;
    double moyenne = 0;
    int nbNotes;

    // TRAITEMENTS
    cout << "Entrez les notes du module. Lorsque vous avez termine, entrez '999' : " << endl;

    // saisie des notes 
    while (!(note == 999))
    {
        cin >> note;
        if (note <= 20 || note >= 0)
        {
            sommeNotes = sommeNotes + note;
            nbNotes = nbNotes + 1;
        }
        else if (note != 999 || note < 0 || note > 20)
        {
            cout << "Note non comprise entre 0 et 20. Recommencez : " << endl;
        }
    }

    // Calcul de la moyenne
    moyenne = sommeNotes / nbNotes;

    // Affichage de la moyenne
    cout << "Moyenne : " << moyenne ;
     
    return 0;
}