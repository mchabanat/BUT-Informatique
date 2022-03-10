/**  MODULE Fractions
     permettant la manipulation de nombres RATIONNELS
     Implémentation proche d'un Type Abstrait de Données (TAD) 
     ----------------------------------------------------------------------
But :
    En tant que TAD, il met à disposition :
    - Un type Fraction, composé :
        ...d'un numérateur, entier portant le signe de la fraction
        ...d'un dénominaeur > 0

    - Une constante FRACTIONNULLE = 0/1
    - Des primitives (= sous-programmes) permettant de :
        ...faire des calculs entre fractions : addition, soustraction, multiplication, division
        ...comparer des fractions : égal, supérieur, inférieur
        ...afficher à l'écran une fraction ou saisir une fraction au clavier

    Afin de se rapprocher de l'usage mathématique, toutes les primitives de calcul mathématique :
    - attendent en paramètre donnée des fractions irréductibles
    - produisent des fractions irréductibles.
    L'utilisation du type Fraction impose par ailleurs que le numérateur soit porteur du signe de la fraction et que le dénominateur est > 0.
---------

 Date de dernière modification : xxxx
 Auteur : M. CHABANAT
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - td n°2
*/

#ifndef FRACTIONS_H
#define FRACTIONS_H

#include <iostream>
using namespace std;

struct Fraction
{
    int num;          // Numérateur de la fraction
    unsigned int den; // Dénominateur de la fraction
};

// Constantes
const Fraction FRACTIONNULLE = {0, 1}; // Constante qui définit la fraction nulle

// Observateurs

// Accesseurs
int numerateur(Fraction frac);
// Retourne le numérateur >= 0

unsigned int denominateur(Fraction frac);
// Retourne le dénominateur > 0

// Opérateurs binaires
Fraction additionner(Fraction frac1, Fraction frac2);
// Retourne la fraction irréductible frac1+frac2
// Précondition : frac1 et frac2 irréductibles
// Postcondition : frac1 + frac2 irréductible

Fraction soustraire(Fraction frac1, Fraction frac2);
// Retourne la fraction irréductible frac1-frac2
// Précondition : frac1 et frac2 irréductibles
// Postcondition : frac1 - frac2 irréductible

Fraction multiplier(Fraction frac1, Fraction frac2);
// Retourne la fraction irréductible frac1*frac2
// Précondition : frac1 et frac2 irréductibles
// Postcondition : frac1 * frac2 irréductible

Fraction diviser(Fraction frac1, Fraction frac2);
// Retourne la fraction irréductible frac1/frac2
// Précondition : frac1 et frac2 irréductibles
// Postcondition : frac1 / frac2 irréductible

// Opérateurs de comparaison
bool estEgal(Fraction frac1, Fraction frac2);
// Retourne true si les 2 frac sont égales
// Précondition : frac1 et frac2 irréductibles

bool estSuperieur(Fraction frac1, Fraction frac2);
// Retourne true si frac1 est supérieure à frac2
// Précondition : frac1 et frac2 irréductibles

bool estInferieur(Fraction frac1, Fraction frac2);
// Retourne true si frac1 est inférieure à frac2
// Précondition : frac1 et frac2 irréductibles

// Autres primitives
Fraction reduire(Fraction frac);
// Retourne la fraction irréductible
// Précondition : fraction dénominateur positif

// Primitives d'Entrée / Sortie
void afficher(Fraction frac);
// affiche à l'écran le contenu du paramètre fraction frac sous sa forme irréductible
// pré-condition : le paramètre frac est une fraction irréductible

Fraction saisir();
// Retourne une fraction irréductible à partir de 2 valeurs entières saisies au clavier
// post-condition : la fraction retournée est une fraction irréductible normalisée

#endif // FRACTIONS_H