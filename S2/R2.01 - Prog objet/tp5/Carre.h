#ifndef _CARRE
#define _CARRE

#include "Fenetre.h"
#include "Souris.h"
#include "Couleur.h"


class Carre {
private:
    int m_x,m_y,m_cote;
    Couleur m_coul;
    void dessiner(Fenetre&,Couleur) const;
public :
    // Constructeurs
    Carre();
    Carre(const Carre&);
    Carre(int,int,int,Couleur = Couleur(0,0,0));

    // Methodes
    void placer(int,int);
    int coordX() const;
    int coordY() const;
    int cote() const;
    Couleur couleur() const;
    void dimensionner(int);
    void definirCouleur(int,int,int);
    void definirCouleur(Couleur);
    void afficher(Fenetre&) const;
    void effacer(Fenetre&) const;
    bool touche(int,int) const;
};
#endif
