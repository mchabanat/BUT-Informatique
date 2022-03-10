/*
    Jeu : Pendu
    But : Réaliser une partie du jeu Le Pendu.
    Auteurs : Matis Chabanat et Arthur Le Menn (TD2 TP3)
    Date de dernière modification : 13/10/2021
    Remarques : Les 2 extensiosn proposées par Mr. Etcheverry ont été traitées.
*/

#include <iostream>
#include <cstring>
#include "game-tools.h"

using namespace std;

int main(void)
{
    //VARIABLES
    const unsigned int NB_MOTS = 10; // Représente le nombre de mots par thème

    unsigned short int numeroTheme;                                                                                                                                // Représente le numéro du thème choisi par le joueur
    int nbRandom;                                                                                                                                                  // Représente un mot aleatoirement dans le theme choisi
    string tabInformatique[NB_MOTS] = {"code", "algorithme", "reseau", "fichier", "hacker", "logiciel", "ordinateur", "internet", "programme", "microprocesseur"}; // Thème 1 : informatique
    string tabCuisine[NB_MOTS] = {"spatule", "restaurant", "casserolle", "aliment", "couteau", "epices", "cuisinier", "gateau", "fourchette", "assaisonnement"};   // Thème 2 : cuisine
    string tabAnimaux[NB_MOTS] = {"girafe", "tigre", "cachalot", "panda", "hippopotame", "renard", "goeland", "chat", "termite", "babouin"};                       // Thème 3 : animaux

    string motATrouver;                         // Représente le mot a trouver
    unsigned long long int longueurMotATrouver; // Représente le nombre de caractère du mot a trouver
    unsigned short int nbCoupsRestants = 7;     // Représente le nombre de coups qu'il reste au joueur initialisé à 7
    char lettreJouee;                           // Représente la lettre jouée a chaque tour

    string historiqueBons = " ";             // Représente l'historique de toutes les lettres bonnes dans le mot
    string historiqueMauvais = " ";          // Représente l'historique de toutes les lettres pas dans le mot
    bool dejaJoueBon;                        // Renvoie si la lettre bonne jouée a déja été saisie auparavant
    bool dejaJoueFaux;                       // Renvoie si la lettre fausse jouée a déja été saisie auparavant
    unsigned long long int tailleHistorique; // Renvoie la taille de la chaine de caractère historiqueBons et historiqueFaux

    string affichageMot;            // Affichage du mot (au début caché puis petit a petit qui se dévoile)
    unsigned short int i;           // Compteur de la boucle
    unsigned short int posCourante; // Représente le caractère etudié lors d'une recherche de première occurrence

    unsigned short int caractereEtudie; // Compteur Représentant la position du caractère étudié

    bool trouve = false;       // Nous dit si _ est dans affichageMot et donc si la partie est terminée ou non
    bool modification = false; // Nous dit si une lettre jouée est dans le mot ou non
    bool gagne = false;        // Représente si le joueur a trouvé le mot ou non

    //TRAITEMENTS
    // Affichage du début de partie
    cout << "J E U  D U  P E N D U" << endl;
    cout << " " << endl;
    cout << "Choisissez un theme : " << endl;
    cout << "1- Informatique, " << endl;
    cout << "2- Cuisine, " << endl;
    cout << "3- Animaux. " << endl;
    cout << "Votre choix : ";

    // Saisie-verif du numeroTheme
    while (true)
    {
        cin >> numeroTheme; // Saisie du numéro du thème

        // Condition de sortie
        if (numeroTheme >= 1 && numeroTheme <= 3)
        {
            break;
        }

        cout << "Numero de theme incorrect. Recommencez : ";
    }

    // Definition du mot a trouver
    nbRandom = random(0, 9); // Chiffre entre 0 et 9 aleatoire qui représentera un mot aleatoire dans un des 3 thèmes

    switch (numeroTheme)
    {
    case 1:
        motATrouver = tabInformatique[nbRandom];
        break;

    case 2:
        motATrouver = tabCuisine[nbRandom];
        break;

    case 3:
        motATrouver = tabAnimaux[nbRandom];
        break;
    }

    // On efface le contenu de l'écran
    effacer();

    // Recherche du nombre de caractères dans le mot a trouver
    longueurMotATrouver = motATrouver.size();

    // Affichage du mot caché
    for (i = 1; i <= longueurMotATrouver; i++)
    {
        affichageMot = affichageMot + "_";
    }

    // Partie en cours
    while (true)
    {
        // Après avoir fait une pause de 2 secondes, on efface l'écran
        effacer();

        cout << "J E U  D U  P E N D U" << endl;
        cout << " " << endl;

        // Avant chaque nouveau tour de boucle on remet les variables à leurs statuts initiaux
        trouve = false;
        modification = false;
        posCourante = 0;

        // On determine si il reste des caractères non découverts (Recherche de première occurrence du caractère '_' )
        while (posCourante != longueurMotATrouver)
        {
            if (affichageMot[posCourante] == '_')
            {
                trouve = true;
                break;
            }

            // Incrémentation de 1 par tour de boucle
            posCourante++;
        }

        // Condition de sortie si le joueur a gagné selon si aucun '_' n'a été trouvé
        if (trouve == false)
        {
            gagne = true;
            break;
        }

        // Affichage du mot à trouver
        cout << "Mot a trouver : " << affichageMot << endl;
        cout << " " << endl;

        // Affichage du nombre de coups restants en couleur
        if (nbCoupsRestants >= 4)
        {
            afficherTexteEnCouleur("Nombre de coups restants : ", vert, false);
            afficherNombreEnCouleur(nbCoupsRestants, vert, true);
        }
        else if (nbCoupsRestants >= 2)
        {
            afficherTexteEnCouleur("Nombre de coups restants : ", violet, false);
            afficherNombreEnCouleur(nbCoupsRestants, violet, true);
        }
        else
        {
            afficherTexteEnCouleur("Nombre de coups restants : ", rouge, false);
            afficherNombreEnCouleur(nbCoupsRestants, rouge, true);
        }

        // Saisie d'un caractère
        cout << "Proposition de lettre ? ";
        cin >> lettreJouee;

        // Recherche du caractère joué dans les 2 historiques
        // Recherche dans l'historique des bonnes lettres
        posCourante = 0;
        dejaJoueBon = false;
        tailleHistorique = historiqueBons.size();

        while (posCourante != tailleHistorique)
        {
            if (historiqueBons[posCourante] == lettreJouee)
            {
                dejaJoueBon = true;
                break;
            }
            posCourante++;
        }

        // Recherche dans l'historique des fausses lettres seulement si le caractère joué na pas été trouvé dans l'historique des bonnes lettres
        if (dejaJoueBon == false)
        {
            posCourante = 0;
            dejaJoueFaux = false;
            tailleHistorique = historiqueMauvais.size();

            while (posCourante != tailleHistorique)
            {
                if (historiqueMauvais[posCourante] == lettreJouee)
                {
                    dejaJoueFaux = true;
                    break;
                }
                posCourante++;
            }
        }

        // Recherche du caractère saisie dans le mot a trouver et modification de l'affichage (Parcours complet avec traitement conditionné)
        if (dejaJoueBon == false && dejaJoueFaux == false)
        {
            for (caractereEtudie = 0; caractereEtudie <= longueurMotATrouver - 1; caractereEtudie++)
            {
                if (lettreJouee == motATrouver[caractereEtudie])
                {
                    affichageMot[caractereEtudie] = lettreJouee;
                    modification = true;
                }
            }

            // Retourne si la lettre est bien dans le mot a trouver ou non et placement de la lettre dans son historique
            if (modification == true)
            {
                historiqueBons = historiqueBons + lettreJouee;
                cout << "Lettre presente dans le mot :) " << endl;
            }
            else
            {
                historiqueMauvais = historiqueMauvais + lettreJouee;
                cout << "Lettre NON presente dans le mot :( " << endl;
                nbCoupsRestants--;
            }
        }

        // Si la lettre a deja ete saisie, on annonce l'erreur et si elle est dans le mot ou non
        else if (dejaJoueBon == true && dejaJoueFaux == false)
        {
            cout << "Vous avez deja saisi cette lettre ! (elle est presente dans le mot) " << endl;
        }
        else if (dejaJoueFaux == true && dejaJoueBon == false)
        {
            cout << "Vous avez deja saisi cette lettre ! (elle est NON presente dans le mot) " << endl;
            nbCoupsRestants--;
        }

        // Condition de sortie ou le joueur n'a plus d'essais, on fait une pause de 2 secondes avant d'effacer le contenu de la console
        if (nbCoupsRestants == 0)
        {
            pause(2);
            break;
        }

        // Faire une pause de 2 secondes avant d'efface le contenu de la console
        pause(2);
    }

    // Fin de partie, affichage du résultat
    if (gagne == true)
    {
        afficherTexteEnCouleur("Bravo, vous gagnez cette partie !", vert, true);
        afficherTexteEnCouleur("Le mot a trouver etait : ", blanc, false);
        afficherTexteEnCouleur(motATrouver, jaune, true);
    }
    else
    {
        effacer();

        cout << "J E U  D U  P E N D U" << endl;
        cout << " " << endl;
        afficherTexteEnCouleur("Desole, vous perdez cette partie ...", rouge, true);
        afficherTexteEnCouleur("Le mot a trouver etait : ", blanc, false);
        afficherTexteEnCouleur(motATrouver, jaune, true);
    }

    return 0;
}
