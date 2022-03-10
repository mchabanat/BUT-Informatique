/**************************************************************************
 * PROGRAMME : Division schéma B
 * BUT : Illustrer la gestion d'exception, chéma de récupération B :
 *       Fonction division() : lève une exception s diviseur nul
 *       main() : schéma de récupération B = signalement dès la 1ere erreur, 
 *                puis quitte le programme 
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
{  
   int x ;         // dividende = nombre divisé
   int diviseur;  // diviseur

   // saisie des opérandes
       cout << "Valeur pour x : ";         cin >> x;
       cout << "Valeur pour diviseur : ";  cin >> diviseur ;
       cout << x << " / " << diviseur << " = ";
   
   // tentative de calcul et affichage du résulat de la division 
       try
       {  cout << division(x,diviseur)  << endl;
          break;
       }
       catch (string s)
       {
         cerr << "! " << s << endl;
       }

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
