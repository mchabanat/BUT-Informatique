#include "Bouton.h"
// Constructeurs
Bouton::Bouton():
    m_cercle(Cercle()),
    m_estActif(false)
{}

Bouton::Bouton(const Bouton& original):
    m_cercle(original.m_cercle),
    m_estActif(original.m_estActif)
{}

Bouton::Bouton(Cercle c,bool etat):
    m_cercle(c),
    m_estActif(etat)
{}

// Methodes
void Bouton::definir(int x, int y, int rayon, int r, int g, int b, bool etat)
{
    this->m_cercle.placer(x, y);
    this->m_cercle.dimensionner(rayon);
    this->m_cercle.definirCouleur(r, g, b);
    this->m_estActif = etat;
}

void Bouton::definir(int x, int y, int rayon, Couleur coul, bool etat)
{
    this->m_cercle.placer(x, y);
    this->m_cercle.dimensionner(rayon);
    this->m_cercle.definirCouleur(coul);
    this->m_estActif = etat;
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
        f.remplitEllipse(this->coordX()-this->rayon()/4,
                         this->coordY()-this->rayon()/4,
                         this->rayon()/2,
                         this->rayon()/2);
    }
}
