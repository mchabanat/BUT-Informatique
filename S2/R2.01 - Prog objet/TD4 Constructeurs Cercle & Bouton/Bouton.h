#ifndef BOUTON_H
#define BOUTON_H

// #include "Fenetre.h"
// #include "Couleur.h"
// #include "Souris.h"
#include "Cercle.h"

class Bouton
{
private:
    Cercle m_cercle;
    bool m_estActif;
    void dessiner(Fenetre&,Couleur) const;
public:
    // Constructeurs 
    Bouton(); // Par défaut
    Bouton(const Bouton&); // de copie
    Bouton(Cercle,bool);

    // Methodes
    void definir(int,int,int,int,int,int,bool = false);
    void definir(int,int,int,Couleur = Couleur(0,0,255),bool = false);
    void activer();
    void desactiver();
    bool actif() const;
    int coordX() const;
    int coordY() const;
    int rayon() const;
    Couleur couleur() const;
    void definirCouleur(Couleur);
    void afficher(Fenetre&) const;
    void effacer(Fenetre&) const;
    bool touche(int,int) const;
};


#endif