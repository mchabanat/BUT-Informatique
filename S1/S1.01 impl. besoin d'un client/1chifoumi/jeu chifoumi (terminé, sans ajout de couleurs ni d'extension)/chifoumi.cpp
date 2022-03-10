/*
    Jeu : Chifoumi
    But : Faire jouer une personne contre la machine au jeu du Pierre / Feuille / Ciseau
    Auteurs : Matis Chabanat et Arthur Le Menn (TD2 TP3)
    Date de dernière modification : 21/09/2021
    Remarques : Le jeu est fonctionnel a 100%, nous n'avons pas ajouté de modification.
*/


#include <iostream>
#include <cstdlib> //pour le tirage obligatoire
#include <ctime> //pour le tirage obligatoire
#include <string>

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
    cout << "Bienvenue dans le jeu du Chifoumi !" << endl;
    cout << " " << endl;
    cout << "Les regles sont simples : choisi un coup entre la pierre, la feuille ou le ciseau" << endl;
    cout << "La pierre gagne contre le ciseau, qui gagne contre la feuille qui gagne contre la pierre" << endl;
    cout << " " << endl;
    cout << "La partie ne s'arrete jamais : appuye sur 'Q' a la fin de la manche pour arreter la partie." << endl;

    // Initialisation
    // coupJoueur, coupMachine >> mettreScoreAZero >> coupJoueur, coupMachine
    scoreJoueur = 0;
    scoreMachine = 0;

    // Jouer la partie
    while (true)
    {
        // affichageNouvelleManche >> écran
        cout << "Nouvelle Manche !" << endl;
        cout << "Chifoumi !" << endl;
        cout << " " << endl;
        cout << "Veuillez saisir le coup que vous souhaitez jouer : " << endl;

        // clavier >> saisieCoupJoueur >> coupJoueur
        cout << "(P)ierre ? (F)euille ? ou (C)iseau ? ou (Q) pour arreter la partie ?" << endl;
        cin >> coupJoueur;

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
        if (coupJoueur != 'Q')
        {
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
        cout << "Coup joue par le joueur --> " << affichageCoup << endl;

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
        cout << "Coup joue par la machine --> " << affichageCoup << endl;
        

        // gagnantManche >> afficherGagnantManche >> écran
        if (gagnantManche == 'e')
        {
            cout << "Egalite. Il n'y a pas de gagnant pour cette manche." << endl;
        }
        else if (gagnantManche == 'J')
        {
            cout << "Le gagnant de la manche est Le joueur." << endl;
        }
        else if (gagnantManche == 'M')
        {
            cout << "Le gagnant de la manche est la machine." << endl;
        }
        

        // gagnantManche >> incrementerScore >> scoreJoueur, scoreMachine
        switch (gagnantManche)
        {
        case 'e':
            break;
        
        case 'J':
            scoreJoueur = scoreJoueur + 1;
            break;

        case 'M':
            scoreMachine = scoreMachine + 1;
            break;
        }
        

        // scoreJoueur, scoreMachine >> afficherScores >> écran
        cout << "Joueur : " << scoreJoueur << "    /    Machine : " << scoreMachine << endl;
        cout << " " << endl;
    }


    // scoreJoueur, scoreMachine >> affichageScoreFinal >> écran
    cout << "Fin de la partie." << endl;
    cout << " " << endl;

    if (scoreJoueur == scoreMachine)
    {
        cout << "Egalite. Il n'y a pas de gagnant pour cette partie." << endl;
    }
    else if (scoreJoueur < scoreMachine)
    {
        cout << "Le gagnant de la partie est la machine sur le score de " << scoreMachine << " / " << scoreJoueur << "." << endl;
    }
    else if (scoreJoueur > scoreMachine)
    {
        cout << "Le gagnant de la partie est Le joueur sur le score de " << scoreJoueur << " / " << scoreMachine << "." << endl;
    }

    
    return 0;
}


//Corps du sous programme random
int randomMinMax(int min, int max)
{
    return rand()%(max-min) + min;
}
