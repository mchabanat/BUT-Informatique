/*
 Programme : 
 But : 
 Date de dernière modification : 
 Auteur : Chabanat M
 Remarques : ca fonctionne a moitié
*/

#include <iostream>
#include "game-tools.h"
using namespace std;

// Creation du type UnGagnant
enum UnGagnant {lievre,tortue};

// Declaration
UnGagnant courseLievreTortue();
/* BUT : Retourner le vainqueur (lievre ou tortue) sur une course */

int main(void)
{
    // VARIABLES
    unsigned int nbCourses;       // Nombre de manches a effectuer
    unsigned int nbWinTortue = 0; // Nombre de victoires de la tortue
    unsigned int nbWinLievre = 0; // Nombre de victoires du lievre

    UnGagnant gagnant;
    unsigned int i;
    // TRAITEMENTS
    // Saisie verif
    // Saisie nbCourses
    cout << "Saisir un nombre de courses a effectuer (au moins 1) : ";
    cin >> nbCourses;

    while (nbCourses < 1)
    {
        cout << "Entrez un nombre de courses superieur ou egal a 1 : ";
        cin >> nbCourses;
    }

    // Realisation des courses
    for(i=1 ; i <= nbCourses ; i++)
    {
        gagnant = courseLievreTortue();
        if (gagnant == lievre)
        {
            nbWinLievre++;
        }
    }

    // Calcul du nombre de victoires de la tortue
    nbWinTortue = nbCourses - nbWinLievre;

    // Affichage du resultat
    cout << "Score final : " << endl;
    cout << "Lievre | " << nbWinLievre << " - " << nbWinTortue << " | Tortue"<< endl;
    cout << " " << endl;

    if(nbWinLievre > nbWinTortue)
    {
        cout << "Le jeu est à l'avantage du Lievre apres " << nbCourses << " courses.";
    }
    else if (nbWinLievre == nbWinTortue)
    {
        cout << "Il y a egalite entre les 2 sportifs de haut niveau.";
    }
    else
    {
        cout << "Le jeu est à l'avantage de la Tortue apres" << nbCourses << "courses.";
    }
}

// Definition
UnGagnant courseLievreTortue()
{
    // Initialisation des booléens
    UnGagnant winner;
    unsigned short int posTortue = 0;
    bool victoireLievre = false;
    int valeurDe; // Nombre random qui représente un lancé de dé

    // Effectuer la course
    while (true)
    {
        valeurDe = random(1,6);

        // Avancer un des coureurs
        if (valeurDe == 6)
        {
            victoireLievre = true;
        }
        else
        {
            posTortue++;
        }

        // Verif s'il y a un gagnant (et condition de sortie)
        if (victoireLievre == true)
        {
            winner = lievre;
            break;
        }

        if (posTortue == 6)
        {
            winner = tortue;
            break;
        }
    }

    // Retourner le gagnant
    return winner;
}