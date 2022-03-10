#include "Bouton.h"

void Bouton::definir(int x, int y, int rayon, int r, int g, int b, bool etat)
{
    this->m_cercle.placer(x, y);
    this->m_cercle.dimensionner(rayon);
    this->m_cercle.definirCouleur(r, g, b);
    this->m_estActif = etat;
}

void Bouton::definir(int x, int y, int rayon, Couleur coul, bool etat)
{
    this->m_cercle(x,y,rayon,coul.rouge(),coul.vert(),coul.bleu(),etat);
}

void Bouton::activer()
{
    this->m_estActif = true;
}

void Bouton::desactiver()
{
    this->m_estActif = false;
}

bool Bouton::actif() const
{
    return this->m_estActif;
}

int Bouton::coordX() const
{
    return this->m_cercle.coordX();
}

int Bouton::coordY() const
{
    return this->m_cercle.coordY();
}

int Bouton::rayon() const
{
    return this->m_cercle.rayon();
}

Couleur Bouton::couleur() const
{
    return this->m_cercle.couleur();
}

void Bouton::definirCouleur(Couleur coul)
{
    this->m_cercle.definirCouleur(coul);
}

void Bouton::afficher(Fenetre &f) const
{
    this->m_cercle.afficher(f);
    this->dessiner(f, this->couleur());
}

void Bouton::effacer(Fenetre &f) const
{
    this->m_cercle.effacer(f);
    this->dessiner(f, f.couleurFond());
}

bool Bouton::touche(int x, int y) const
{
    return this->m_cercle.touche(x, y);
}

void Bouton::dessiner(Fenetre &f, Couleur coul) const
{
    if(this->m_estActif)
    {
        f.choixCouleurTrace(coul);
        f.remplitEllipse(this->coordX(),
                         this->coordY(),
                         this->rayon(),
                         this->rayon());
    }
}
