#include "Bouton.h"
// Constructeurs
Bouton::Bouton():
    Cercle(),
    m_estActif(false)
{}

Bouton::Bouton(const Bouton& original):
    Cercle(original),
    m_estActif(original.m_estActif)
{}

Bouton::Bouton(Cercle c,bool etat):
    Cercle(c),
    m_estActif(etat)
{}

// Methodes
void Bouton::definir(int x, int y, int rayon, int r, int g, int b, bool etat)
{
    this->placer(x, y);
    this->dimensionner(rayon);
    this->definirCouleur(r, g, b);
    this->m_estActif = etat;
}

void Bouton::definir(int x, int y, int rayon, Couleur coul, bool etat)
{
    this->placer(x, y);
    this->dimensionner(rayon);
    this->definirCouleur(coul);
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

void Bouton::afficher(Fenetre &f) const
{
    this->Cercle::afficher(f);
    this->dessiner(f, this->couleur());
}

void Bouton::effacer(Fenetre &f) const
{
    this->Cercle::effacer(f);
    this->dessiner(f, f.couleurFond());
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