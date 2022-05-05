#ifndef ELEMENTGRAPHIQUE_H
#define ELEMENTGRAPHIQUE_H

#include "Fenetre.h"
#include "Couleur.h"
#include "Souris.h"

class ElementGraphique
{
private:
    int m_x,m_y;
    Couleur m_coul;
public:
    ElementGraphique(const ElementGraphique&);
    ElementGraphique(int,int,Couleur);  

    void placer(int,int);
    int coordX() const;
    int coordY() const;
    Couleur couleur() const;
    void definirCouleur(Couleur);
    virtual void afficher(Fenetre&) const = 0; // Abstrait car virtual et =0
    virtual void effacer(Fenetre&) const = 0;
    virtual bool touche(int,int) const = 0;
};


#endif