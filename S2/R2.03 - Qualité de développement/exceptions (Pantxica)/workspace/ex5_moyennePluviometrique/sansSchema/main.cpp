/**************************************************************************
 * PROGRAMME : Calcul moyenne pluviométrique d'un fichier de texte 
 *             dont le contenu peut être corrompu, cad contenant des 
 *             valeurs valeurs non numériques          
 * BUT : Pas de Schéma de récupération : 
 *         module de gestion de fichiers : lève exceptions
 *         main() : ne gère pas les exceptions levées = advienne que pourra
 * VERSION DE BASE : --
 * AUTEUR : Dagorret
 * DATE : 02/02/2022
 * REMARQUES :  
 *            Afin que l'on voit/constate quelles sont les exceptions levées,
 *            DANS le module ***fichierTexte.cpp***,
 *            chaque instruction throw exception est précédée
 *            de l'instruction cerr << exception
***************************************************************************/
#include <iostream>
#include "stdlib.h"
#include "fichierTexte.h"
#include "sousProgrammes.h"

using namespace std;

int main()
{
    string nomSysPluvio ;     // nom système du fichier à lire
 
    //----------- TEST de calculMoyenneSimple avec 3 fichiers : 1 ok, 1 vide, 1 corrompu -----------------
    //----------------------------------------------------------------------------------------------------

    nomSysPluvio = "dec-2016";              // fichier OK
    cout << endl;
    calculMoyenneSimple(nomSysPluvio) ;
    cout << "...au revoir..." << endl;

    nomSysPluvio = "jan-2017";              // fichier vide
    cout << endl;
    calculMoyenneSimple(nomSysPluvio) ;
    cout << "...au revoir..." << endl;

    nomSysPluvio = "fev-2017";              // fichier corrompu
    cout << endl;
    calculMoyenneSimple(nomSysPluvio) ;
    cout << "...au revoir..." << endl;

    return 0;
}
