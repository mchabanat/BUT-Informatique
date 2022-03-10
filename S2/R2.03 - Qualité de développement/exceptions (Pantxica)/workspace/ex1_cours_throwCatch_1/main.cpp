#include <iostream>
using namespace std;

int main()
{
  cout << 1 << endl;

  try
    {
      cout << 2 << endl ;
      throw 3;				        // exception de type int
      throw 'a';                    // exception de type char
      throw string("disque plein");	// exception de type string
      throw float(4.0 * 2.25);      // exception de type float
    }

  catch (string s)
    { cout << s << endl ; }
  catch (char c)
    { cout << c << endl ; }
  catch (int e)
    { cout << "err !" << e << '!' << endl ; }
  catch (float)
    { cout << "probleme avec un reel !" << endl ; }
  catch (...)
    { cout << "probleme inconnu !" << endl ; }

  cout << 4;

  cout << endl << endl << "au revoir....";
  return 0;
}
