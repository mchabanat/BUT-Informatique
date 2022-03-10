/*
 Programme : 
 But : 
 Date de dernière modification : 
 Auteur : Chabanat M
 Remarques : ca fonctionne
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    int i; //nombre de repetitions.
    string tableau = "chabachatte"; //déclaration du tableau qui va contenir les valeurs
    unsigned int longueurTab = tableau.size(); //longueur du tableau
    char copieValeur; //valeur utilisée pour echanger les valeurs
    int borneFin; //fin de la boucle

    // TRAITEMENTS
    // affichage tableau avant execution
    cout << "Tableau avant traitement : " << endl;
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

    longueurTab --;

    //Echange des valeurs

    for (i=0; i<borneFin; i++)
    {
        copieValeur=tableau[i];
        tableau[i]=tableau[longueurTab-i];
        tableau[longueurTab-i]=copieValeur;
    }

    //Affichage
    cout << "Tableau apres traitement : " << endl;
    cout << tableau << endl;
    
    return 0;
}