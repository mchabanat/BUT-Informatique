#include <iostream>
#include <sstream>
#include "sousProgrammes.h"
#include "fichierTexte.h"

using namespace std;

void calculMoyenneSimple (string nomSysPluvio)
{
    //cout << "calculMoyenneSimple, non encore developpe" << endl;

    UnFichierTexte ficPluvio;      // nom logique du fichier
    int hauteur;              // hauteur pluviom�trique courante, lue dans le fichier
    unsigned int somme ;      // somme des hauteurs pluviom�triques
    float moyenne;            // moyenne des hauteurs pluviom�triques
    unsigned int nbre ;       // nbre de valeurs compt�es au cours du parcours
    bool fdf ;                // indicateur de r�ussite/�chec de lecture
                              //  car fin de fichier atteinte

    // association noms logique-syst�me
    associer(ficPluvio, nomSysPluvio);
    // initialisations
    nbre = 0;
    somme = 0;

    // tentative d'ouverture du fichier
    ouvrir(ficPluvio, consultation);

    // Parcours séquentiel pour calcul somme et nb
    // interruptible dès la premiere erreur de lecture rencontrée
    for (;;)
    {
        // tentative de lecture
        lireMot(ficPluvio, hauteur, fdf);

        if (fdf)
        {
            break;
        }

        // Cumul somme & incr nb si une valeur (correcte) a �t� lue
        nbre ++;
        somme = somme + hauteur;
    }

    // fermeture du fichier
    fermer(ficPluvio);

    if (nbre > 0)
        // somme, nbre >> calcul moyenne >> moyenne
    {
        moyenne = float(somme) / float(nbre);
    }

    // Terminer = Affichage des resultats calculés

    // moyenne, nbre >> affichage ecran >> (ecran)
    cout << "Le fichier comporte " << nbre << " releves." << endl;
    if (nbre > 0)
    {
        cout << "la moyenne des hauteurs pluviometriques sur les " << nbre <<
             " jours = " << moyenne << endl;
    }
    else
    {
        cout << "fichier vide : pas de moyenne a calculer. " << endl;
    }
}

void calculMoyenneOuArretEcran (string nomSysPluvio)
{
    //cout << "calculMoyenneOuArretEcran, non encore developpe" << endl;
}


void calculMoyenneOuArretLog (string nomSysPluvio)
{
      //cout << "calculMoyenneOuArretLog, non encore developpe" << endl;
}

