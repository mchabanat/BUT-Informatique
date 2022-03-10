/*
 Programme : divisionEntière
 But : division un entier positif ou nul par un entier positif en donnant le quotient et le reste (seulement avec des additions et soustractions)
 Date de dernière modification : 30/09/21
 Auteur : Chabanat M
 Remarques : ca ne fonctionne pas
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    int nb1;
    int nb2;
    int quotient = 0;
    int compteur = 0;
    int reste = 0;
    

    // TRAITEMENTS    
    // Saisie du premier nombre
    cout << "Nombre 1 (positif ou egal a 0) : ";
    cin >> nb1;

    // Saisie du deuxieme nombre
    cout << "Nombre 2(strictement positif) : ";
    cin >> nb2;

    // Calcul de la division
    while (true)
    {
        nb1 = nb1 - nb2;

        if (nb1 <= 0)
        {
            if (nb1 == 0)
            {
                reste = 0;
            }
            else if (nb1 < 0)
            {
                reste = 0 - nb1;
            }

            quotient = compteur;
            break;
        }
        compteur++;
    }

    // Affichage du quotient et du reste 
    cout << "Quotient = " << quotient << endl;
    cout << "Reste = " << reste << endl;
     
    return 0;
}