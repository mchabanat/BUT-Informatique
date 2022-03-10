/**************************************************************************
 * PROGRAMME : Propagation exception le long d'unne hiérarchie d'appels 
 * BUT : Codage de l'illustration n°1 du cours
 * VERSION DE BASE : --
 * AUTEUR : Dagorret
 * DATE : 02/02/2022
 * REMARQUES :
 *             néant
***************************************************************************/

#include <iostream>
using namespace std;

/** DECLARATIONS DES sous-programmes
 *----------------------------------**/
 void sousProg();
 // but : saisie des opérandes et appelle la division

 int division(int eltHaut,int eltBas);
 // Calcule et retourne eltHaut/eltBas
 // pré-condition : eltBas  /= 0

/** PROGRAMME PRINCIPAL MAIN
 *--------------------------**/

int main()
{
	cout << "MAIN() : avant appel sousProg() " << endl;
	sousProg();
	
	cout << "MAIN() : apres appel sousProg()" << endl;
   return 0;
}


/** DEFINITIONS DES sous-programmes
 *--------------------------------- **/
void sousProg()
{
   cout << "   DEBUT_SOUPSROG() :" << endl;
   int x ;        // dividende
   int diviseur; 
   
   // saisie des opérandes >> diviseur
   cout << "   Valeur pour x : ";           cin >> x;
   cout << "   Valeur pour diviseur : ";    cin >> diviseur;
	
   // x, diviseur >> calcul et affichage division >> (écran)
   cout << "   " << x << " / " << diviseur << " = " ;
   cout << "   " <<  division(x, diviseur) << endl;

   cout << "   FIN_SOUSPROG()" << endl;
   
}


 int division(int eltHaut,int eltBas)
{
   if (eltBas == 0)
   { throw string ("calcul impossible, division par zero");}
	else
	{return (eltHaut / eltBas) ;	}
}

