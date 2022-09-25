/**
 * @file main.cpp
 * @brief RAPPELS - h�ritage
La classe Individu est sp�cialis�e dans la sous-classe Etudiant, qui :
- ajoute l'attribut 'formation' et ses accesseurs
- sp�cialise la m�thode usuelle 'toString()',
- et se r�f�re au constructeur 'Etudiant'
 * @author Lopist�guy
 * @version 0.1
 * @date jj/mm/aaa
 *
 * note: Les destructeurs sont diff�renci�s et font savoir leur diff�rence
 */

#include <iostream>
#include <Individu.h>
#include <Etudiant.h>

using namespace std;

int main()
{
    Individu ind1 ("Pierre", "Dupont");
    Etudiant etud1 ("Jean", "Martin", "DUT2");

    cout << ind1.toString() << endl;  // affiche nom et pr�nom
    cout << etud1.toString() << endl; // affiche en plus la formation

    return 0;
}
