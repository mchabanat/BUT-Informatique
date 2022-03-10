/**  CORPS MODULE Personne
     ------------------------ */

/* Inclusions
   ---------- */
#include "Personne.h"

/* Types - Variables - Constantes propres au corps
*/

/* Déclarations des sous-programmes utilisés dans ce corps 
*/

/* Corps des sous-programmes déclarés dans l'interface fractions.h
*/
// Observateurs

// Accesseurs

// Opérateurs binaires

// Opérateurs de comparaison

// Autres primitives

// Primitives d'Entrée / Sortie
void afficher(const Personne &personne)
{
   cout << "  {" << personne.nom << ", " << personne.prenom << ", { ";
   cout << personne.adresse.numRue << ", ";
   cout << personne.adresse.nomRue << ", ";
   cout << personne.adresse.codePostal << ", ";
   cout << personne.adresse.nomVille << " }";
   cout << "}";
}

/* Corps des sous-programmes déclarés dans ce corps
*/