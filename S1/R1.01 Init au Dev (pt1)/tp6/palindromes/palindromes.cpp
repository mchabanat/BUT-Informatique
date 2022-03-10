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
    int i; //nombre de repetitions
    string tableau = "laval"; //déclaration du tableau qui va contenir les valeurs
    unsigned int longueurTab = tableau.size(); //longueur du tableau
    int borneFin; //fin de la boucle
    bool mauvais = false;

    // TRAITEMENTS
    cout << tableau << endl;
    cout << " " << endl;
    // initialisation
    if (longueurTab %2 == 0)
    {
        borneFin = (longueurTab/2);
    }
    else
    {
        borneFin = (longueurTab-1)/2;
    }

    //Comparaison des caractères
    for (i=0; i<borneFin; i++)
    {
        if (tableau[i] != tableau[longueurTab - i])
        {
            mauvais = true;
        }
    }

    //affichage
    if (mauvais == false)
    {
        cout << "Le mot " << tableau << " est un palindrome.";
    }
    else 
    {
        cout << "Le mot " << tableau << " n est pas un palindrome.";
    }

    return 0;
}