/*
 Programme : 5nbSuivants
 But : l'utilisateur saisi un nombre et le programme affichera les 5 nombre qui suivent
 Date de dernière modification : 23/09/21
 Auteur : Chabanat M
 Remarques : ca fonctionne
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    int nombreSaisi; 
    int i;

    // TRAITEMENTS
    cout << "Saisissez un nombre dont on va afficher les 5 nombres qui suivent : " << endl;
    cin >> nombreSaisi;

    cout << " " << endl;
    
    for (i=1 ; i <= 5 ; i++)
    {
        nombreSaisi = nombreSaisi + 1;
        cout << nombreSaisi << endl;
    }
     
    return 0;
}