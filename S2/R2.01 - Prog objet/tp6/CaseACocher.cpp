#include "CaseACocher.h"

//Constructeurs
CaseACocher::CaseACocher():
    Carre(),
    m_estActif(false)
{}

CaseACocher::CaseACocher(const CaseACocher& original):
    Carre(original),
    m_estActif(original.m_estActif)
{}

CaseACocher::CaseACocher(Carre c,char etat):
    Carre(c),
    m_estActif(etat)
{}

CaseACocher::CaseACocher(int x,int y,int cote,Couleur c,char etat):
    Carre(x,y,cote,c),
    m_estActif(etat == 'C')
{}

// Methodes
void CaseACocher::definirCadre(int x, int y, int cote, Couleur coul)
{
    this->placer(x,y);
    this->dimensionner(cote);
    this->definirCouleur(coul);
}

Carre CaseACocher::cadre() const
{
    return (*this);
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
    this->Carre::afficher(f);
    this->dessiner(f,this->couleur());
}

void CaseACocher::effacer(Fenetre& f) const
{
    this->Carre::effacer(f);
    this->dessiner(f,f.couleurFond());
}

void CaseACocher::dessiner(Fenetre& f, Couleur coul) const
{
    if(this->m_estActif)
    {
        f.choixCouleurTrace(coul);

        f.traceLigne(this->coordX(),this->coordY(),this->coordX()+this->cote(),this->coordY()+this->cote());
        f.traceLigne(this->coordX(),this->coordY()+this->cote(),this->coordX()+this->cote(),this->coordY());
    }
}

