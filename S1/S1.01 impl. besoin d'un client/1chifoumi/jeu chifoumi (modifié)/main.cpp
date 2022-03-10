/*
    Jeu : Chifoumi
    But : Faire jouer une personne contre la machine au jeu du Pierre / Feuille / Ciseau
    Auteurs : Matis Chabanat et Arthur Le Menn (TD2 TP3)
    Date de dernière modification : 21/09/2021
    Remarques : Nous avons changé les couleurs de l'affichage lors de la partie grâce à Game-tools de P. Etcheverry.
*/


#include <iostream>
#include <cstdlib> //pour le tirage obligatoire
#include <ctime> //pour le tirage obligatoire
#include "game-tools.h"

using namespace std;



//Sous programme utilisé pour effectuer les coups aleatoires de la machine
int randomMinMax(int min, int max);


int main(void)
{
    //VARIABLES

    int scoreJoueur; // Variable représentant le nombre de points du joueur
    int scoreMachine; // Variable représentant le nombre de points de la machine

    char coupJoueur; // Coup joué par le joueur
    char coupMachine; // Coup joué par la machine
    char gagnantManche; // Gagnant de la manche en cours

    string affichageCoup; // Variable qui servira pour afficher les coups joués par le joueur et la machine
  
    int nbRandom; //indice representant le coup random de la machine


    //TRAITEMENTS

    //affichageRegles >> écran
    afficherTexteEnCouleur("Bienvenue dans le jeu du Chifoumi !", bleu, true);
    cout << " " << endl;
    afficherTexteEnCouleur("Les regles sont simples : choisi un coup entre la pierre, la feuille ou le ciseau", bleuClair, true);
    afficherTexteEnCouleur("La pierre gagne contre le ciseau, qui gagne contre la feuille qui gagne contre la pierre", bleuClair, true);
    cout << " " << endl;
    afficherTexteEnCouleur("La partie ne s'arrete jamais : appuye sur 'Q' a la fin de la manche pour arreter la partie.", bleuClair, true);

    // Initialisation
    // coupJoueur, coupMachine >> mettreScoreAZero >> coupJoueur, coupMachine
    scoreJoueur = 0;
    scoreMachine = 0;

    // Jouer la partie
    while (true)
    {
        // affichageNouvelleManche >> écran
        afficherTexteEnCouleur("Nouvelle Manche !", bleuClair, true);
        afficherTexteEnCouleur("Chifoumi !", bleuClair, true);
        cout << " " << endl;
        afficherTexteEnCouleur("Veuillez saisir le coup que vous souhaitez jouer : ", bleuClair, true);

        // clavier >> saisieCoupJoueur >> coupJoueur
        afficherTexteEnCouleur("(P)ierre ? (F)euille ? ou (C)iseau ? ou (Q) pour arreter la partie ? --> ", bleuClair, false);
        cin >> coupJoueur;
        
        if(coupJoueur == 'P' || coupJoueur == 'F' || coupJoueur == 'C' || coupJoueur == 'Q')
        {
            // Condition de sortie de la boucle
            if(coupJoueur == 'Q')
            {
                break;
            }

            
            // randomMinMax(1,4) >> initialisationCoupMachine >> nbRandom
            srand(time(NULL));
            nbRandom = randomMinMax(1,4); //la valeur generee appartient a l intervalle [1;4[
            

            // nbRandom >> affecterCoupMachine >> coupMachine
            switch (nbRandom)
            {
            case 1:
                coupMachine = 'P';
                break;

            case 2:
                coupMachine = 'F';
                break;

            case 3:
                coupMachine = 'C';
                break;
            }
            
            // coupJoueur, coupMachine >> determinerGagnantManche >> gagnantManche
            switch (coupJoueur)
            {
            case 'P':
                switch (coupMachine)
                {
                case 'P':
                    gagnantManche = 'e';
                    break;

                case 'F':
                    gagnantManche = 'M';
                    break;

                case 'C':
                    gagnantManche = 'J';
                    break;
                }
                break;
                
            case 'F':
                switch (coupMachine)
                {
                case 'P':
                    gagnantManche = 'J';
                    break;

                case 'F':
                    gagnantManche = 'e';
                    break;

                case 'C':
                    gagnantManche = 'M';
                    break;
                }
                break;
                    
            case 'C':
                switch (coupMachine)
                {
                case 'P':
                    gagnantManche = 'M';
                    break;

                case 'F':
                    gagnantManche = 'J';
                    break;

                case 'C':
                    gagnantManche = 'e';
                    break;
                }
                break;
            }
            
            
            // coupJoueur >> afficherLeCoupDuJoueur >> affichageCoup
            if (coupJoueur == 'P')
            {
                affichageCoup = "Pierre.";
            }
            else if (coupJoueur == 'F')
            {
                affichageCoup = "Feuille.";
            }
            else if(coupJoueur == 'C')
            {
                affichageCoup = "Ciseau.";
            }

            // affichageCoup >> afficherCoupJoueur >> écran
            afficherTexteEnCouleur("Coup joue par le joueur --> ", vert, false);
            afficherTexteEnCouleur(affichageCoup, vert, true);

            // coupMachine >> afficherLeCoupDeLaMachine >> affichageCoup
            if (coupMachine == 'P')
            {
                affichageCoup = "Pierre.";
            }
            else if (coupMachine == 'F')
            {
                affichageCoup = "Feuille.";
            }
            else if(coupMachine == 'C')
            {
                affichageCoup = "Ciseau.";
            }

            // affichageCoup >> afficherCoupMachine >> écran
            afficherTexteEnCouleur("Coup joue par la machine --> ", jaune, false);
            afficherTexteEnCouleur(affichageCoup, jaune, true);
            

            // gagnantManche >> afficherGagnantManche >> écran
            if (gagnantManche == 'e')
            {
                afficherTexteEnCouleur("Egalite. Il n'y a pas de gagnant pour cette manche.", grisFonce, true);
            }
            else if (gagnantManche == 'J')
            {
                afficherTexteEnCouleur("Le gagnant de la manche est Le joueur.", vert, true);
            }
            else if (gagnantManche == 'M')
            {
                afficherTexteEnCouleur("Le gagnant de la manche est la machine.", jaune, true);
            }
            

            // gagnantManche >> incrementerScore >> scoreJoueur, scoreMachine
            switch (gagnantManche)
            {
            case 'e':
                break;
            
            case 'J':
                scoreJoueur++;
                break;

            case 'M':
                scoreMachine++;
                break;
            }
            

            // scoreJoueur, scoreMachine >> afficherScores >> écran
            afficherTexteEnCouleur("Joueur : ", vert, false);
            afficherNombreEnCouleur(scoreJoueur, vert, false);
            afficherTexteEnCouleur("    /    ", grisFonce, false);
            afficherTexteEnCouleur("Machine : ", jaune, false);
            afficherNombreEnCouleur(scoreMachine, jaune, false);
            cout << " " << endl;
        }
        else
        {
            afficherTexteEnCouleur("ERREUR : coup inconnu", rougeFonce, true);
        }
    }


    // scoreJoueur, scoreMachine >> affichagefINpARTIE >> écran
    afficherTexteEnCouleur("Fin de la partie.", blanc, true);

    // scoreJoueur, scoreMachine >> afficherScoresFinPartie >> écran
    afficherTexteEnCouleur("Score final : ", blanc, false);
    afficherTexteEnCouleur("Joueur : ", vert, false);
    afficherNombreEnCouleur(scoreJoueur, vert, false);
    afficherTexteEnCouleur("    /    ", grisFonce, false);
    afficherTexteEnCouleur("Machine : ", jaune, false);
    afficherNombreEnCouleur(scoreMachine, jaune, false);
    cout << " " << endl;

    if (scoreJoueur == scoreMachine)
    {
        afficherTexteEnCouleur("Egalite. Il n'y a pas de gagnant pour cette partie.", grisFonce, true);
    }
    else if (scoreJoueur < scoreMachine)
    {
        afficherTexteEnCouleur("Le gagnant de la partie est la machine !", jaune, true);
    }
    else if (scoreJoueur > scoreMachine)
    {
        afficherTexteEnCouleur("Le gagnant de la partie est Le joueur !", vert, true);
    }

    cout << "Appuyez sur une touche pour quitter le jeu " << endl;
    cin >> affichageCoup;
    return 0;
}


//Corps du sous programme random
int randomMinMax(int min, int max)
{
    return rand()%(max-min) + min;
}
