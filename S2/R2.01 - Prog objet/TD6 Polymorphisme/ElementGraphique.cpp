#include "ElementGraphique.h"

ElementGraphique(const ElementGraphique& original):
    this->m_x(original.m_x),
    this->m_y(original.m_y),
    this->m_coul(original.m_coul)
{}

ElementGraphique(int x,int y,Couleur c):
    this->m_x(x),
    this->m_y(y),
    this->m_coul(c)
{}

void placer(int x,int y)
{
    this->m_x = x;
    this->m_y = y;
}

int coordX() const
{
    return this->m_x;
}

int coordY() const
{
    return this->m_y;
}

Couleur couleur() const
{
    return this->m_coul;
}

void definirCouleur(Couleur coul)
{
    this->m_coul.definir(coul.rouge(),coul.vert(),coul.bleu());
}

