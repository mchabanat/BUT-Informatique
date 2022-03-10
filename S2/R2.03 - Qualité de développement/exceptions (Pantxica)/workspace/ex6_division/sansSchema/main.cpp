/**************************************************************************
 * PROGRAMME : Division  - version simple sans gestion de division par zéro
 * BUT : Illustrer la gestion des exceptions 
 *       Pas de schéma de récupération :
 *       Fonction division() : lève une exception s diviseur nul
 *       main() : Pas de schéma de récupération = advienne que pourra 
 * VERSION DE BASE : --
 * AUTEUR : Dagorret
 * DATE : 02/02/2022
 * REMARQUES :
 *             néant
***************************************************************************/
#include <iostream>

using namespace std;
int division(int eltHaut,int eltBas);
// si eltBas != 0, retourne le résultat de la division entière de eltHaut/eltBas
// sinon, lève l'exception string ("division par zero !")

int main()
{  int x ;        // dividende = nombre divisé
   int diviseur;  // diviseur 

   // saisie des opérandes >> x, diviseur
   cout << "Valeur pour x : ";         cin >> x;
   cout << "Valeur pour diviseur : ";  cin >> diviseur ;
   cout << x << " / " << diviseur << " = ";

   // x, diviseur >> calcul et affichage résultat division >> (écran)
   cout << division(x,diviseur)  << endl;

   // terminaison
   cout << endl  << "au revoir...." << endl;
   return 0;
}

int division(int eltHaut,int eltBas)
 {
 /* Si eltBas != 0, retourne l'entier eltBas/eltBas ; 
    Sinon lève une exception de type string avec le message "division par zero !" */

 if (eltBas == 0)
    {  throw  string ("division par zero !") ; }
  else
    {return (eltHaut/eltBas);}
}
