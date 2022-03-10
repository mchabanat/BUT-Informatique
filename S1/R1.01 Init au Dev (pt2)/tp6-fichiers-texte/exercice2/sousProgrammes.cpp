#include <iostream>
#include "sousProgrammes.h"
using namespace std;

void produireMoyenne (string nomSysFic)
{
    // Initialisation
    UnFichierTexte fic;
    float motEnCours;
    bool fdf;
    
    unsigned int nbVal = 0;
    float somme = 0;
    float moyenne;
    

    // Préparation
    associer(fic, nomSysFic);
    ouvrir(fic, consultation);

    // Parcours sequentiel complet pour calcul
    while(true)
    {
        // Tenter de lire le mot
        lireMot(fic,motEnCours,fdf);

        // Condition d'arrêt
        if(fdf)
        {
            break;
        }

        // Réaliser la somme de toutes les valeurs
        somme = somme + motEnCours;
        nbVal++;
    }

    // Fermeture du fichier
    fermer(fic);

    // Calculer la moyenne 
    moyenne = somme / static_cast<float>(nbVal);

    // Affichage de la moyenne si le fichier contient au moins une note
    if (nbVal == 0)
    {
        cout << "Fichier vide !" << endl;
    }
    else
    {
        cout << "Moyenne pluviometrique = " << moyenne << endl;
    }
}
