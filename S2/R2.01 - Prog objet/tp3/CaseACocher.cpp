#include "CaseACocher.h"

void CaseACocher::definirCadre(int x, int y, int cote, Couleur coul)
{
    this->m_carre.placer(x,y);
    this->m_carre.dimensionner(cote);
    this->m_carre.definirCouleur(coul);
}

Carre CaseACocher::cadre() const
{
    return (*this).m_carre;
}

void CaseACocher::definirEtat(char etat)
{
    if(etat=='C')
    {
        this->m_estActif = true;
    }
    else
    {
        this->m_estActif = false;
    }
}

char CaseACocher::etat() const
{
    if(this->m_estActif)
    {
        return 'C';
    }
    else
    {
        return 'N';
    }
}

void CaseACocher::afficher(Fenetre& f) const
{
    this->m_carre.afficher(f);
    this->dessiner(f,this->m_carre.couleur());
}

void CaseACocher::effacer(Fenetre& f) const
{
    this->m_carre.effacer(f);
    this->dessiner(f,f.couleurFond());
}

void CaseACocher::dessiner(Fenetre& f, Couleur coul) const
{
    if(this->m_estActif)
    {
        f.choixCouleurTrace(coul);

        f.traceLigne(this->m_carre.coordX(),this->m_carre.coordY(),this->m_carre.coordX()+this->m_carre.cote(),this->m_carre.coordY()+this->m_carre.cote());
        f.traceLigne(this->m_carre.coordX(),this->m_carre.coordY()+this->m_carre.cote(),this->m_carre.coordX()+this->m_carre.cote(),this->m_carre.coordY());
    }
}
