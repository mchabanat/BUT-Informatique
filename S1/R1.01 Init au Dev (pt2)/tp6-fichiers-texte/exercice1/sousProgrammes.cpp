#include "sousProgrammes.h"
#include <iostream>
#include "pile.h"
using namespace std;

void afficherFichierTexte(string nomSysFic)
{
    // Initialisation
    UnFichierTexte fic;
    string ligneCourante;
    bool fdf = false; // Indicateur de fin de fichier

    // Préparation du fichier
    associer(fic, nomSysFic);
    ouvrir(fic, consultation);

    // Parcours séquentiel complet pour l'affichage
    while (true)
    {
        // Tentative de lecture
        lireLigne(fic, ligneCourante, fdf);

        if (fdf)
        {
            break;
        }

        // Affichage de la ligne courante
        cout << ligneCourante << endl;
    }

    // Fermeture du fichier
    fermer(fic);
}

void afficherInverseFichierTexte(string nomSysFic)
{
    // Initialisation
    UnFichierTexte fic;
    UnePile pile;
    string ligneCourante;
    string elementDepile;
    bool fdf = false; // Indicateur de fin de fichier

    // Préparation du fichier
    associer(fic, nomSysFic);
    ouvrir(fic, consultation);

    // Parcours séquentiel complet pour l'affichage à l'envers
    while (true)
    {
        // Tentative de lecture
        lireLigne(fic, ligneCourante, fdf);

        if (fdf)
        {
            break;
        }

        // On met chaque ligne dans une pile pour pouvoir ensuite afficher à l'envers
        empiler(pile, ligneCourante);
    }

    // Fermeture du fichier
    fermer(fic);

    // Afficher à l'envers
    while (!estVide(pile))
    {
        depiler(pile, elementDepile);
        cout << elementDepile << endl;
    }
}

void etendreFichierTexte(string nomSysFicSource, string nomSysFicCible)
{
    // Initialisation
    UnFichierTexte ficSource;
    UnFichierTexte ficCible;
    string ligneCourante;
    bool fdf = false; // Indicateur de fin de fichier

    // Préparation du fichier
    associer(ficSource, nomSysFicSource);
    associer(ficCible, nomSysFicCible);
    ouvrir(ficSource, consultation);
    ouvrir(ficCible, extension);

    // Parcours séquentiel complet pour l'affichage
    while (true)
    {
        // Tentative de lecture
        lireLigne(ficSource, ligneCourante, fdf);

        if (fdf)
        {
            break;
        }

        // Ecriture de la ligne dans le 2e fichier
        ecrireLigne(ficCible, ligneCourante);
    }

    // Fermeture du fichier
    fermer(ficSource);
    fermer(ficCible);
}

void viderFichierTexte(string nomSysFic)
{
    //VARIABLES
    UnFichierTexte f;
    string ligneCourante;

    //INITIALISATIONS
    associer(f, nomSysFic);

    //TRAITEMENT
    supprimer(f);
    ouvrir(f, creation);
    fermer(f);
}