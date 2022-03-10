/**  CORPS MODULE Fractions  
     ------------------------ */

/* Inclusions
   ---------- */
#include "Fractions.h"

/* Types - Variables - Constantes propres au corps
*/

/* Déclarations des sous-programmes utilisés dans ce corps 
*/

/* Corps des sous-programmes déclarés dans l'interface fractions.h
*/
// Observateurs

// Accesseurs
int numerateur(Fraction frac)
{
     return frac.num;
}

unsigned int denominateur(Fraction frac)
{
     return frac.den;
}

// Opérateurs binaires
Fraction additionner(Fraction frac1, Fraction frac2)
{
     Fraction fracResultat;

     fracResultat.num = (frac1.num * frac2.den) + (frac2.num * frac1.den);
     fracResultat.den = frac1.den * frac2.den;

     return reduire(fracResultat);
}

Fraction soustraire(Fraction frac1, Fraction frac2)
{
     Fraction fracResultat;

     fracResultat.num = (frac1.num * frac2.den) - (frac2.num * frac1.den);
     fracResultat.den = frac1.den * frac2.den;

     return reduire(fracResultat);
}

Fraction multiplier(Fraction frac1, Fraction frac2)
{
     Fraction fracResultat;

     fracResultat.num = frac1.num * frac2.num;
     fracResultat.den = frac1.den * frac2.den;

     return reduire(fracResultat);
}

Fraction diviser(Fraction frac1, Fraction frac2)
{
     Fraction fracResultat;

     // Multiplication de frac1 par l'inverse de frac2
     fracResultat.num = frac1.num * frac2.den;
     fracResultat.den = frac1.den * frac2.num;

     return reduire(fracResultat);
}

// Opérateurs de comparaison
bool estEgal(Fraction frac1, Fraction frac2)
{
     Fraction frac1Reduite;
     Fraction frac2Reduite;

     frac1Reduite = reduire(frac1);
     frac2Reduite = reduire(frac2);

     return ((frac1Reduite.num == frac2Reduite.num) && (frac1Reduite.den == frac2Reduite.den) ? true : false);

     /* Meme methode que 
     if ((frac1Reduite.num == frac2Reduite.num) && (frac1Reduite.den == frac2Reduite.den))
     {
          return true;
     }
     else
     {
          return false;
     }
     */
}

bool estSuperieur(Fraction frac1, Fraction frac2)
{
     Fraction frac1Reduite;
     Fraction frac2Reduite;

     frac1Reduite = reduire(frac1);
     frac2Reduite = reduire(frac2);

     return ((frac1Reduite.num > frac2Reduite.num) && (frac1Reduite.den > frac2Reduite.den) ? true : false);
}

bool estInferieur(Fraction frac1, Fraction frac2)
{
     Fraction frac1Reduite;
     Fraction frac2Reduite;

     frac1Reduite = reduire(frac1);
     frac2Reduite = reduire(frac2);

     return ((frac1Reduite.num < frac2Reduite.num) && (frac1Reduite.den < frac2Reduite.den) ? true : false);
}

// Autres primitives
Fraction reduire(Fraction frac)
{
     // VARIABLES
     unsigned int i; // Compteur du for
     int num = frac.num;
     int den = frac.den;
     bool estNegatif = false;
     unsigned int valeurMaxI;

     // TRAITEMENTS
     if (num < 0)
     {
          valeurMaxI = (-num) + den;
          estNegatif = true;
          num = (-num);
     }
     else
     {
          valeurMaxI = num + den;
     }

     // Reduction
     for (i = 1; i <= valeurMaxI; i++)
     {
          if ((den % i == 0) && (num % i == 0))
          {
               num = num / i;
               den = den / i;
          }
     }

     if (estNegatif)
     {
          frac.num = (-num);
     }
     else
     {
          frac.num = num;
     }

     frac.den = den;

     return frac;
}

// Primitives d'Entrée / Sortie
void afficher(Fraction frac)
{
     cout << " " << frac.num << "/" << frac.den << " ";
}

Fraction saisir()
{
     Fraction nouvelleFrac;
     int num;
     int den;

     // Saisie du numérateur
     cout << "Numerateur : ";
     cin >> num;

     // Saisie verif du dénominateur

     while (true)
     {
          cout << "Denominateur : ";
          cin >> den;

          if (den < 1)
          {
               cout << "Recommencez ! Le denominateur doit etre strictement superieur a 0" << endl;
          }
          else
          {
               break;
          }
     }

     nouvelleFrac.num = num;
     nouvelleFrac.den = den;

     return reduire(nouvelleFrac);
}

/* Corps des sous-programmes déclarés dans ce corps
*/
