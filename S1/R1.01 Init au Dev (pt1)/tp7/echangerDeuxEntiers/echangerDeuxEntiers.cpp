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
void echangerDeuxEntiers(int& nb1 , int& nb2);
// BUT : echanger 2 valeurs comprises dans des variables entre elles (nb1 et nb2)


int main (void)
{
    // VARIABLES
    int val1;
    int val2;

    // TRAITEMENTS
    // Saisie des 2 valeurs
    cout << "Saisir un premier nombre : ";
    cin >> val1;

    cout << "Saisir un deuxieme nombre : ";
    cin >> val2;

    // Appel de la procedure
    echangerDeuxEntiers(val1,val2);

    // Affichage du resultat de l'échange
    cout << "Nombre 1 apres echange : " << val1 << endl;
    cout << "Nombre 2 apres echange : " << val2 << endl;

    return 0;
}



// Definition
void echangerDeuxEntiers(int& nb1 , int& nb2)
{
    int copieNb2;

    copieNb2 = nb2;
    nb2 = nb1;
    nb1 = copieNb2;
}