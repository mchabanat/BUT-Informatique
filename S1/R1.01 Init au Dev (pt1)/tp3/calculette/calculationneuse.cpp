/*
 Programme : calculatrice
 But :  effectuer des operations a l'aide de 2 valeurs et d'un opérateur saisi par l'user
 Date de dernière modification : 15/09/21
 Auteur : Chabanat M
 Remarques : 
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    double val1;
    double val2;
    char oper;
    double resultat;
    bool erreur;
    
    // TRAITEMENTS
    erreur=false;

    //demande de saisi des 3 variables
    cout << "Veuillez entrer une premiere valeur :" << endl;
    cin >> val1;

    cout << "Veuillez entrer une deuxieme valeur (>0 si vous souhaitez faire une division) :" << endl;
    cin >> val2;

    cout << "Entrez l operateur de l operation a effectuer (+ ou - ou * ou /) :" << endl;
    cin >> oper;

    //Realisation de l operation
    switch (oper)
    {
    case '+':
        resultat = val1 + val2;
        break;

    case '-':
        resultat = val1 - val2;
        break;

    case '*':
        resultat = val1 * val2;
        break;

    case '/':
        if (val2 < 0 || val2 > 0)
        {
            resultat = val1 / val2;
        }
        else
        {
            cout << "La division par 0 est impossible.";
            erreur = true;
        }
        break;
    
    default:
        cout << "L operateur saisi est inconnu. Veuillez relancer le programme et entrer un des 4 operateurs";
        erreur = true;
        break;
    }

    //affichage du resultat
    if (erreur==false)
    {
        cout << "Le resultat de l' operation : " << val1 << oper << val2 << " est " << resultat;
    }
  

    return 0;
}