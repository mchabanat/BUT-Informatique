#include <iostream>
#include <string>
using namespace std;

int main()
{
  int val; // valeur à saisir et à analyser
  cout << "entrer une valeur entre 0 et 3 : " ;
  cin >> val;

  try
    {
      if ((val < 0) || (val > 3) )
       {throw string("valeur non valide"); }
    }

  catch (string s)
    { cout << s << endl ; }
    
    // les "..." prennent tout ce qui n'a pas été pris par le précédent catch (cela ressemble au default dans un switch)
  catch (...)
    { cout << "probleme inconnu !" << endl ; }

  cout << endl << "au revoir...." << endl;
  return 0;
}
