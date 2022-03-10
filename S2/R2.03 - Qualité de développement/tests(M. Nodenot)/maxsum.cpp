#include <iostream>
using namespace std;

// Ma fonction
unsigned int maxsumMoi(int value, int maxint);

// Fonction du prof
unsigned int maxsum(int value, int maxint);



int main(void)
{
    int val;
    int tonNombre;
    int somme;

    cout << "Saisissez value : ";
    cin >> val;

    cout << "Saisissez maxint : ";
    cin >> tonNombre;

    try
    {
        somme = maxsum(val, tonNombre);
    }
    catch (string s)
    {
        cerr << " SOUSPROG(), traite-exception STRING : " << s << endl;
    }

    cout << "Le resultat est : " << maxsum(val, tonNombre) << endl;


    return 0;
}


// Ma fonction
unsigned int maxsumMoi(int value, int maxint)
{
    unsigned int i;
    unsigned int sum = 0;

    if (value < 0)
    {
        value = -value;
    }

    if (maxint < 0)
    {
        throw string("maxint negatif");
    }
    else
    {
        for (i = 0; i < static_cast<unsigned int>(value) + 1; i++)
        {
            sum = sum + i;
        }

        if (sum > static_cast<unsigned int>(maxint))
        {
            throw string("somme invalide");
        }
        else
        {
            return sum;
        }
    }
}

// Fonction du prof
unsigned int maxsum(int value, int maxint) {
    unsigned int result=0;
    for (int i=0; i <= abs(value); i++)
        result=result+i;
     if (result > maxint)
         result=-1;
     if (result== -1)
         throw string("Exception");
     return result;
}