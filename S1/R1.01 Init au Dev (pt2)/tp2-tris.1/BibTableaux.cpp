/**  CORPS MODULE BibTableaux
     ------------------------ */

/* Inclusions
   ---------- */
#include "BibTableaux.h"

/* Types - Variables - Constantes propres au corps
*/

/* Déclarations des sous-programmes utilisés dans ce corps 
*/

/* Corps des sous-programmes déclarés dans l'interface fractions.h
*/
// Observateurs
/*
bool estTrieCroissant(const int tab[], unsigned short int lgTab)
{
    return true; // POUR COMPILER
}

bool estTrieDecroissant(const int tab[], unsigned short int lgTab)
{
    return true; // POUR COMPILER
}
*/
// Accesseurs

// Opérateurs binaires

// Opérateurs de comparaison

// Autres primitives

// Primitives d'Entrée / Sortie
void afficher(const int tab[],
              unsigned short int lgTab)
{
    if (lgTab > 0)
    {
        cout << "{";
        for (unsigned short int i = 0; i < lgTab - 1; i++)
        {
            cout << tab[i] << ", ";
        };
        cout << tab[lgTab - 1] << "} " << endl;
    }
    else
    {
        cout << "tableau vide " << endl;
    }
}

// Recherches
void recherchePremiereOccDichoEntier(const int tab[],
                                     unsigned int lgTab,
                                     int val,
                                     unsigned int &pos,
                                     unsigned int &nbTour,
                                     bool &trouve)
{
    // VARIABLES
    unsigned int borneInf;
    unsigned int borneSup;
    unsigned int milieu;

    // INITIALISATION
    borneInf = 0;
    borneSup = lgTab - 1;
    trouve = false;
    nbTour = 1;

    // RECHERCHE
    while (borneInf <= borneSup)
    {
        // On verifie si la valeur est plus grande / petite que les valeurs du tableau
        // pour éviter de faire tourner le programme en boucle infini
        if (val > tab[borneInf] || val < tab[borneSup])
        {
            break;
        }

        milieu = (borneInf + borneSup) / 2;

        if (tab[milieu] == val)
        {
            nbTour++;

            trouve = true;
            pos = milieu;
            break;
        }
        else if (tab[milieu] < val)
        {
            borneSup = milieu - 1;
        }
        else
        {
            borneInf = milieu + 1;
        }

        nbTour++;
    }
}

void recherchePremiereOccDichoPersonne(const Personne tab[],
                                       unsigned int lgTab,
                                       Personne personneRecherchee,
                                       unsigned int &pos,
                                       bool &trouve)
{
    // VARIABLES
    unsigned int borneInf;
    unsigned int borneSup;
    unsigned int milieu;

    // INITIALISATION
    borneInf = 0;
    borneSup = lgTab - 1;
    trouve = false;

    // RECHERCHE
    while (borneInf <= borneSup)
    {
        // On verifie si la valeur est plus grande / petite que les valeurs du tableau
        // pour éviter de faire tourner le programme en boucle infini
        if (personneRecherchee.nom > tab[borneInf].nom || personneRecherchee.nom < tab[borneSup].nom)
        {
            break;
        }

        milieu = (borneInf + borneSup) / 2;

        if (tab[milieu].nom == personneRecherchee.nom)
        {
            trouve = true;
            pos = milieu;
            break;
        }
        else if (tab[milieu].nom < personneRecherchee.nom)
        {
            borneSup = milieu - 1;
        }
        else
        {
            borneInf = milieu + 1;
        }
    }
}

void determinerPremierDernier(const int tab[],
                              unsigned int lgTab,
                              int val,
                              unsigned int &posPremier,
                              unsigned int &posDernier,
                              bool &trouve)

{
}
/* Corps des sous-programmes déclarés dans ce corps
*/
