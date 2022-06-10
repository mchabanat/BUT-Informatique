#ifndef CHIFOUMIMODELE_H
#define CHIFOUMIMODELE_H

#include <QObject>


class ChifoumiModele : public QObject
{
    Q_OBJECT
public:
    enum UnCoup {pierre, papier, ciseau, rien};

    explicit ChifoumiModele(UnCoup coupJoueur=rien,
                            UnCoup coupMachine=rien,
                            QObject *parent = nullptr);

    ChifoumiModele::UnCoup genererUnCoup();
    /* retourne une valeur aléatoire = pierre, papier ou ciseau.
    Utilisée pour faire jouer la machine */

    // Getters
    UnCoup getCoupJoueur();
    /* retourne le dernier coup joué par le joueur */

    UnCoup getCoupMachine();
    /* retourne le dernier coup joué par le joueur */

    unsigned int getScoreJoueur();
    /* retourne le score du joueur */

    unsigned int getScoreMachine();
    /* retourne le score de la machine */


    uint16_t getTemps();

    void setTemps(uint16_t);

    char determinerGagnant();
    /* détermine le gagnant 'J' pour joueur, 'M' pour machine, 'N' pour match nul
    en fonction du dernier coup joué par chacun d'eux */

    void setCoupJoueur(ChifoumiModele::UnCoup p_coup);
    /* initialise l'attribut coupJoueur avec la valeur
    du paramètre p_coup */

    void setCoupMachine(ChifoumiModele::UnCoup p_coup);
    /* initialise l'attribut coupmachine avec la valeur
    du paramètre p_coup */

    void setScoreJoueur(unsigned int p_score);
    /* initialise l'attribut scoreJoueur avec la valeur
    du paramètre p_score */

    void setScoreMachine(unsigned int p_score);
    /* initialise l'attribut coupMachine avec la valeur
    du paramètre p_score */

    // Autres modificateurs
    void majScores(char p_gagnant);
    /* Mise à jour des scores en fonction des règles de gestion actuelles :
            - 1 point pour le gagnant lorsqu'il y a un gagnant
            - 0 point en cas de match nul
    */
    void initScores();
    /* initialise à 0 les attributs scoreJoueur et scoreMachine
    NON indispensable */

    void initCoups();
    /* initialise à rien les attributs coupJoueur et coupMachine
    NON indispensable */





private:

    unsigned int _scoreJoueur;   // score actuel du joueur
    unsigned int _scoreMachine;  // score actuel de la Machine

    ChifoumiModele::UnCoup _coupJoueur;          // dernier coup joué par le joueur
    ChifoumiModele::UnCoup _coupMachine;         // dernier coup joué par la machine

    uint16_t _temps;

};

#endif // CHIFOUMIMODELE_H
