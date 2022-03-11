#ifndef CERCLE_H
#define CERCLE_H

#include "Fenetre.h"
#include "Couleur.h"
#include "Souris.h"


class Cercle
{
private:
    int m_x,m_y,m_rayon;
    Couleur m_couleur;
    void dessiner(Fenetre&,Couleur) const;
public:
    // Constructeurs
    Cercle(); // Par défaut
    Cercle(const Cercle&); // de copie
    Cercle(int,int,int,Couleur = Couleur(0,0,255));

    // Methodes
    void placer(int, int);
    void dimensionner(int);
    void definirCouleur(int,int,int);
    void definirCouleur(Couleur);
    int coordX() const;
    int coordY() const;
    int rayon() const;
    Couleur couleur() const;
    void afficher(Fenetre&) const;
    void effacer(Fenetre&) const;
    bool touche(int,int) const;
};

#endif
