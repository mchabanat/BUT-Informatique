/**  MODULE Personne
     contient la définition du type Personne
     -------------------------------------------

 Date de dernière modification : xxxx
 Auteur : xxx
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - td n°3
*/

#ifndef PERSONNE_H
#define PERSONNE_H

#include <iostream>
using namespace std;

// Type
// Définition des types du module
struct Adresse
{
     string numRue;
     string nomRue;
     unsigned short int codePostal;
     string nomVille;
};

struct Personne
{
     string nom;
     string prenom;
     Adresse adresse;
};

// Constantes

// Observateurs

// Accesseurs

// Opérateurs binaires

// Opérateurs de comparaison

// Autres primitives

// Primitives d'Entrée / Sortie
void afficher(const Personne &personne);
// Affiche sur une ligne le contenu de l'enregistrement passé en paramètre

#endif // PERSONNE_H