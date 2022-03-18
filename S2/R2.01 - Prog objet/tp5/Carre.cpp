#include "Carre.h"

//Constructeurs
Carre::Carre():
    m_x(10),
    m_y(10),
    m_cote(20),
    m_coul(Couleur(0,0,0))
{}

Carre::Carre(const Carre& original):
    m_x(original.m_x),
    m_y(original.m_y),
    m_cote(original.m_cote),
    m_coul(original.m_coul)
{}

Carre::Carre(int x,int y,int cote,Couleur c):
    m_x(x),
    m_y(y),
    m_cote(cote),
    m_coul(c)
{}

// Methodes
void Carre::placer(int x, int y)
{
    (*this).m_x = x;
    (*this).m_y = y;
}

int Carre::coordX() const
{
    return (*this).m_x;
}

int Carre::coordY() const
{
    return (*this).m_y;
}

int Carre::cote() const
{
    return (*this).m_cote;
}

Couleur Carre::couleur() const
{
    return (*this).m_coul;
}

void Carre::dimensionner(int cote)
{
    (*this).m_cote = cote;
}

void Carre::definirCouleur(int r, int g, int b)
{
    (*this).m_coul.definir(r,g,b);
}

void Carre::definirCouleur(Couleur c)
{
    (*this).m_coul.definir(c.rouge(),c.vert(),c.bleu());
}

void Carre::dessiner(Fenetre& f, Couleur c) const
{
    f.choixCouleurTrace(c);
    f.traceLigne((*this).m_x,(*this).m_y,((*this).m_x+(*this).m_cote),(*this).m_y);
    f.traceLigne((*this).m_x,(*this).m_y,(*this).m_x,((*this).m_y+(*this).m_cote));
    f.traceLigne((*this).m_x,(*this).m_y+(*this).m_cote,((*this).m_x+(*this).m_cote),(*this).m_y+(*this).m_cote);
    f.traceLigne((*this).m_x+(*this).m_cote,(*this).m_y,(*this).m_x+(*this).m_cote,(*this).m_y+(*this).m_cote);
}

void Carre::afficher(Fenetre& f) const
{
    dessiner(f,(*this).m_coul);
}

void Carre::effacer(Fenetre& f) const
{
    dessiner(f,f.couleurFond());
}

bool Carre::touche(int x, int y) const
{
    if(x < (*this).m_x || x > (*this).m_x+(*this).m_cote || y < (*this).m_y || y > (*this).m_y+(*this).m_cote)
    {
        return false;
    }
    else
    {
        return true;
    }
}
