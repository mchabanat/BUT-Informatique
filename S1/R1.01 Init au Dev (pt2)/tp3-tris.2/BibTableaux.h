/**  MODULE BibTableaux 
     regroupe des sous-programmes applicables à des tableaux
     -------------------------------------------------------
But :
    Mettre à dispositon d'un programmeur des sous-programmes applicables aux tableaux.
    Conformes aux exercices des TD n°1 et et 3 de R1.01
    
    Il peut s'agit de tableaux d'entiers ou d'enregistrements de type Personne.
    Les tableaux manipulés doivent être triés par ordre décroissant de valeur.
    Dans le cas des tableaux d'enregistrements de type Personne, ils seront triés par ordre 
    décroissant de nom.
---------

 Date de dernière modification : xxxx
 Auteur : xxx
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - td n°2
*/

#ifndef BIBTABLEAUX_H
#define BIBTABLEAUX_H

#include <iostream>
#include "Personne.h"
using namespace std;

// Primitives d'Entrée-Sortie
void afficher(const int tab[], unsigned short int lgTab);
// But : affiche à l'écran le contenu d'un tableau tab contenant lgTab > 0 éléments
//       si lgTab = 0, affiche un message indiquant que le tableau n'a pas de valeur significative (tableau 'vide')

void afficher (const Personne tab[],
               unsigned short int lgTab);
// But : affiche à l'écran le contenu d'un tableau tab contenant lgTab > 0 éléments de type Personne
//       si lgTab = 0, affiche un message indiquant que le tableau n'a pas de valeur significative (tableau 'vide')


// Observateurs
bool estTrieCroissant(const int tab[], unsigned short int lgTab);
// BUT : retourner si le tableau tab de lgTab cases est trié de facon croissante ou non

bool estTrieDecroissant(const int tab[], unsigned short int lgTab);
// BUT : retourner si le tableau tab de lgTab cases est trié de facon décroissante ou non


// Recherches
void recherchePremiereOccDichoEntier(const int tab[],
                                     unsigned int lgTab,
                                     int val,
                                     unsigned int &pos,
                                     unsigned int &nbTour,
                                     bool &trouve);
/* BUT : rechercher la valeur val dans le tableau tab d'entiers de lgTab cases grâce à 
         une recherche dichotomique de 1ere occurence et retourner la position
         de la valeur si elle est trouvée (trouve = true ou false) */
// Précondition : le tableau doit être trié (décroissant ici)

void recherchePremiereOccDichoPersonne(const Personne tab[],
                                       unsigned int lgTab,
                                       Personne personneRecherchee,
                                       unsigned int &pos,
                                       bool &trouve);
// BUT : rechercher la personne personneRecherchee dans le tableau tab de lgTab cases
//       grâce à une recherche dichotomique de 1ere occurence et retourner la position
//       de la valeur si elle est trouvée (trouve = true ou false)
// Précondition : le tableau doit être trié (décroissant par nom ici)

void determinerPremierDernier(const int tab[],
                              unsigned int lgTab,
                              int val,
                              unsigned int &posPremier,
                              unsigned int &posDernier,
                              bool &trouve);
// BUT : Rechercher la première et la dernière occurrence (posPremier et posDernier)
//       d’une valeur entière dans un tableau d’entiers seulement si cette valeur existe
// Précondition : le tableau doit être trié (décroissant par nom ici)



void triBulle(int tab[], unsigned int lgTab);
/* BUT : tri CROISSANT  des lgTab (>0) éléments de tab (avec d'éventuels doublons)
         par la méthode de tri de meme nom */

void triBulle(Personne tab[], unsigned int lgTab);
/* BUT : tri CROISSANT  des lgTab (>0) éléments de tab (avec d'éventuels doublons)
         par la méthode de tri de meme nom */

void triParInsertion(int tab[], unsigned int lgTab);
/* BUT : tri CROISSANT  des lgTab (>0) éléments de tab (avec d'éventuels doublons)
         par la méthode de tri de meme nom */




#endif // BIBTABLEAUX_H