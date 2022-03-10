/*
 Programme : saisieVerifNote2
 But :  determiner si la note saisie par l'utilisateur est bien comprise entre 0 et 20, si la note n'est pas compris entre 0 et 20 cela affiche un msg d'erreur
 Date de dernière modification : 30/09/21
 Auteur : Chabanat M
 Remarques : ca fonctionne
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    double note; // représente la note saisie par l'utilisateur
    double sommeNotes = 0; 
    int nbNotes = 0;
    double moyenne;

    // TRAITEMENTS    
    
    // Boucle
    while (true)
    {
        // Saisie de la note
        cout << "Entrez une note : " ;
        cin >> note;

        if (note < 0 || note > 20)
        {
            if (note == 999)
            {
                break;
            }
            else 
            {
                cout << "Valeur incorrecte, une note doit etre comprise entre 0 et 20." << endl;
            }
        }
        else 
        {
            sommeNotes = sommeNotes + note;
            nbNotes = nbNotes + 1;
        }
    }

    // calcul de la moyenne
    moyenne = sommeNotes / nbNotes;

    // Affichage de la moyenne 
    cout << "La moyenne des notes saisies est egale a " << moyenne ;
     
    return 0;
}