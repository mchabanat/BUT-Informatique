/*
 Programme : groupeTp
 But :  trouver le groupe de TD d une personne grace au groupe de TP de la personne
 Date de dernière modification : 16/09/21
 Auteur : Chabanat M
 Remarques : ca fonctionne
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    unsigned short int groupeTd;
    unsigned short int groupeTp;
    bool erreur = false;

    // TRAITEMENTS
    //saisie du groupe TP
    cout << "Entrez votre groupe de TP --> ";
    cin >> groupeTp;

    //on recherche le groupe du TD grace au groupe de TP
    if (groupeTp < 1 || groupeTp > 5)
    {
        erreur = true;
    }
    else
    {
        switch (groupeTp)
        {
        case 1 :
        case 2 :
            groupeTd = 1;
            break;
        
        case 3 :
        case 4 :
            groupeTd = 2;
            break;
        
        case 5 :
            groupeTd = 3;
            break;
        }
    }

    //affichage du groupeTd
    if (erreur == false)
    {
        cout << "Vous etes dans le groupe TD numero " << groupeTd;
    }
    else 
    {
        cout << "Veuillez entrer un groupe de TP compris entre 1 et 5.";
    }

    return 0;
}