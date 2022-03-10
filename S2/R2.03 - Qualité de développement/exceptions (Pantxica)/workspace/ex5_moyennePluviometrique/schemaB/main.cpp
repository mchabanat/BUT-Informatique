/**************************************************************************
 * PROGRAMME : Calcul moyenne pluviométrique d'un fichier de texte 
 *             dont le contenu peut être corrompu, cad contenant des 
 *             valeurs valeurs non numériques          
 * BUT : Mise en oeuvre du schéma de récupération B :
 *             module de gestion de fichiers : lève exceptions 
 *             main() : Notification de l'erreur, dès la première erreur, 
 *                      puis arrêt en laissant le fichier dans un état
 *                      stable (= fermé)
 * VERSION DE BASE : --
 * AUTEUR : Dagorret
 * DATE : 02/02/2022
 * REMARQUES :
 *            Point de vigilance : affichage de l'exception !
***************************************************************************/

#include <iostream>
#include "stdlib.h"
#include "fichierTexte.h"
#include "sousProgrammes.h"

using namespace std;

int main()
{
    string nomSysPluvio ;     // nom système du fichier à lire
 
   /*

    //----------- TEST de calculMoyenneSimple avec 3 fichiers : 1 ok, 1 vide, 1 corrompu -----------------
    //----------------------------------------------------------------------------------------------------

    nomSysPluvio = "dec-2016";      // fichier ok
    cout << endl;
    calculMoyenneSimple(nomSysPluvio) ;
    cout << "...au revoir..." << endl;

    nomSysPluvio = "jan-2017";      // fichier vide
    cout << endl;
    calculMoyenneSimple(nomSysPluvio) ;
    cout << "...au revoir..." << endl;

    nomSysPluvio = "fev-2017";      // fichier corrompu
    cout << endl;
    calculMoyenneSimple(nomSysPluvio) ;
    cout << "...au revoir..." << endl;

    */

    
    //----------- TEST de calculMoyenneOuArretEcran avec 3 fichiers : 1 ok, 1 vide, 1 corrompu -----------------
    //---------------------------------------------------------------------------------------------------- 

    nomSysPluvio = "dec-2016";      // fichier ok
    cout << endl;
    calculMoyenneOuArretEcran(nomSysPluvio) ;
    cout << "...au revoir..." << endl;

    nomSysPluvio = "jan-2017";      // fichier vide
    cout << endl;
    calculMoyenneOuArretEcran(nomSysPluvio) ;
    cout <<  "...au revoir..." << endl;

    nomSysPluvio = "fev-2017";      // fichier corrompu
    cout << endl;
    calculMoyenneOuArretEcran(nomSysPluvio) ;
    cout <<  "...au revoir..." << endl;

   /* 

    //----------- TEST de calculMoyenneOuArretLog avec 3 fichiers : 1 ok, 1 vide, 1 corrompu -----------------
    //----------------------------------------------------------------------------------------------------

    nomSysPluvio = "dec-2016";      // fichier ok
    calculMoyenneOuArretLog(nomSysPluvio) ;
    cout << "...au revoir..." << endl;

    nomSysPluvio = "jan-2017";      // fichier vide
    calculMoyenneOuArretLog(nomSysPluvio) ;
    cout << "...au revoir..." << endl;

    nomSysPluvio = "fev-2017";      // fichier corrompu
    calculMoyenneOuArretLog(nomSysPluvio) ;
    cout << "...au revoir..." << endl;

    */

    return 0;
}
