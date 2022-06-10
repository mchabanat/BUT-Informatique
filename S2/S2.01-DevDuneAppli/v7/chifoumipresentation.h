/**\
  * @file chifoumipresentation.h
  * @author Tom Planche, Angel Garcia, Matis Chabanat
  * @brief Présentation du jeu Chifoumi
  * @date 08-06-2022
  *
  * @copyright Copyright (c) 2022
  *
\**/

#ifndef CHIFOUMIPRESENTATION_H
#define CHIFOUMIPRESENTATION_H

#include <QObject>
#include <QTimer>

#include "chifoumimodele.h"

class ChifoumiVue;

/**\
  * @brief Notre présentation du jeu Chifoumi
  *
\**/
class ChifoumiPresentation : public QObject {
    Q_OBJECT
   public:
    /**\
      * @brief Constructeur de la présentation
      *
      * @param m Modèle du jeu
      * @param parent Parent de la présentation
    \**/
    explicit ChifoumiPresentation(ChifoumiModele *m, QObject *parent = nullptr);

    /**\
      * @brief Types d'états de la partie
      *
    \**/
    enum UnEtat { etatInitial,
                  partieEnCours,
                  partieEnPause,
                  finDePartie };

    /**\
      * @brief Retourne le Modèle
      *
      * @return ChifoumiModele* Modèle du jeu
    \**/
    ChifoumiModele *getModele();

    /**\
      * @brief Retourne la Vue
      *
      * @return ChifoumiVue* Vue du jeu
    \**/
    ChifoumiVue *getVue();

    /**\
      * @brief Retourne l'Etat de la partie
      *
      * @return ChifoumiPresentation::UnEtat Etat de la partie
    \**/
    ChifoumiPresentation::UnEtat getEtat();

    //.  =======================================================================
    //.                                SETTERS
    //.  =======================================================================
    /**\
      * @brief Définit le Modèle
      *
      * @param m Modèle à définir
    \**/
    void setModele(ChifoumiModele *m);

    /**\
      * @brief Définit la Vue
      *
      * @param v Vue à définir
    \**/
    void setVue(ChifoumiVue *v);

    /**\
      * @brief Définit l'Etat de la partie
      *
      * @param e Etat à définir
    \**/
    void setEtat(ChifoumiPresentation::UnEtat e);

   public slots:
    void lancerPartie();

    void jouePierre();
    void jouePapier();
    void joueCiseau();

    /**\
      * @brief Lance la fenêtre de dialogue 'a propos'
      *
    \**/
    void aProposDe();

    /**\
      * @brief Lance la fenêtre de dialogue 'paramètres'
      *
    \**/
    void parametrer();

    /**\
      * @brief Fonction appelée à chaque tick du timer
      *
    \**/
    void updaterTimer();

    void pauseTimer();
    void reprendreTimer();

    void pauseButtonClicked();

   private:
    ChifoumiModele *_leModele;  // Modèle du jeu
    ChifoumiVue *_laVue;        // Vue du jeu
    UnEtat _etat;               // Etat de la partie

    QTimer *timer; // Pointeur sur le timer
    const uint16_t DELAIS = 1000;  // Délai entre chaque tick du timer

    /**\
      * @brief Gestion de la fin de partie
      *
    \**/
    void finPartie();
};

#endif  // CHIFOUMIPRESENTATION_H
