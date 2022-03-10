/*
 Programme : echangeNombres
 But :  echanger la valeur entre 2 variables
 Date de dernière modification : 10/09/2021
 Auteur : Chabanat M
 Remarques : 
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    double nb1; //premier nombre a echanger 
    double nb2; //deuxieme nombre a echanger 
    double copieNb1; //copie de nb1 
    
    
    // TRAITEMENTS
    // demande à l'utilisateur des 2 nombres 
    cout << "Veuillez entrer la valeur du premier nombre a echanger :";
    cin >> nb1;

    cout << "Veuillez entrer la valeur du deuxieme nombre a echanger :";
    cin >> nb2;


    //echange des nombres
    copieNb1 = nb1;
    nb1 = nb2;
    nb2 = copieNb1;

    // affichage du resultat
    cout << "voici les 2 nombres apres l echange : " << endl;
    cout << "nb1 = " << nb1 << endl;
    cout << "nb2 = " << nb2 << endl;

    return 0;
}