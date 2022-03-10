/*
 Programme : signeNombre
 But :  Determiner le signe d'un chiffre saisi par l'utilisateur au préalable
 Date de dernière modification : 15/09/21
 Auteur : Chabanat M
 Remarques : ca fonctionne
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    double nb; //nombre dont on va determiner le signe
    string signe; //signe du nombre
    
    // TRAITEMENTS
    cout << "Veuillez entrer un nombre dont on va determiner le signe :";
    cin >> nb;

    //recherche du signe
    if (nb < 0)
    {
        signe = "Negatif";
    }
    else if (nb > 0)
    {
        signe = "Positif";
    }
    else 
    {
        signe = "Nul";
    }

    //affichage du signe du nb 
    cout << "Le nombre " << nb << " est " << signe << ".";

    return 0;
}