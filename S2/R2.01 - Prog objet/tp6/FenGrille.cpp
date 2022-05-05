#include "FenGrille.h"

FenGrille::FenGrille(int larg, int haut):
    m_hauteur(haut),
    m_largeur(larg),
    Fenetre()
{
}

FenGrille::FenGrille(const char* titre, int fenHaut, int fenLarg, int x, int y, int r, int g, int b, int caseHaut, int caseLarg):
    m_hauteur(caseHaut),
    m_largeur(caseLarg),
    Fenetre()
{
    (*this).apparait(titre,fenHaut,fenLarg,x,y,r,g,b);
}

FenGrille::FenGrille(const FenGrille& original):
    m_hauteur(original.m_hauteur),
    m_largeur(original.m_largeur),
    Fenetre(original)
{
}

void FenGrille::apparait(const char* titre, int fenHaut, int fenLarg, int x, int y, int r, int g, int b)
{
    (*this).Fenetre::apparait(titre,fenHaut,fenLarg,x,y,r,g,b);
    int nbTrait = 0;
    int id = 0;

    this->choixCouleurTrace(200,200,200);
    // On trace les lignes
    while(id < fenLarg)
    {
        nbTrait++;
        id = 0+(nbTrait*this->m_largeur);
        (*this).traceLigne(0,id,fenHaut,id);
    }

    // On trace les colonnes
    nbTrait = 0;
    id = 0;
    while(id < fenHaut)
    {
        nbTrait++;
        id = 0+(nbTrait*this->m_hauteur);
        (*this).traceLigne(id,0,id,fenLarg);
    }
}

void FenGrille::effacer()
{
    this->Fenetre::effacer();

    // Faire re apparaitre la grille
    int nbTrait = 0;
    int id = 0;

    this->choixCouleurTrace(200,200,200);
    // On trace les lignes
    while(id < this->largeur())
    {
        nbTrait++;
        id = 0+(nbTrait*this->m_largeur);
        (*this).traceLigne(0,id,this->hauteur(),id);
    }

    // On trace les colonnes
    nbTrait = 0;
    id = 0;
    while(id < this->hauteur())
    {
        nbTrait++;
        id = 0+(nbTrait*this->m_hauteur);
        (*this).traceLigne(id,0,id,this->largeur());
    }
}

void FenGrille::afficherCase(CaseACocher cac)
{
    cac.afficher(*this);
}


