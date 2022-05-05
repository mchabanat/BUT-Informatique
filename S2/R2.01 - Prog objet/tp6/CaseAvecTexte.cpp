#include "CaseAvecTexte.h"

// Constructeurs
CaseAvecTexte::CaseAvecTexte(CaseACocher cac, const char* texte):
    CaseACocher(cac)
{
    this->m_texte = new char [strlen(texte)+1];
    strcpy(this->m_texte,texte);
}

CaseAvecTexte::CaseAvecTexte(const CaseAvecTexte& original):
    CaseACocher(original)
{
    this->m_texte = new char [strlen(original.m_texte)+1];
    strcpy(this->m_texte,original.m_texte);
}


// Destructeur
CaseAvecTexte::~CaseAvecTexte()
{
    delete [] this->m_texte;
}

// Methodes
void CaseAvecTexte::definirTexte(const char* texte)
{
    delete [] this->m_texte;
    this->m_texte = new char [strlen(texte)+1];
    strcpy(this->m_texte,texte);
}

void CaseAvecTexte::afficher(Fenetre& f) const
{
    this->CaseACocher::afficher(f);
    this->dessiner(f,this->couleur());
}

void CaseAvecTexte::effacer(Fenetre& f) const
{
    this->CaseACocher::effacer(f);
    this->dessiner(f,f.couleurFond());
}

void CaseAvecTexte::dessiner(Fenetre& f, Couleur c) const
{
    f.choixCouleurTrace(c);
    f.ecrit(this->coordX()+this->cote()+5,
            this->coordY()+this->cote(),
            this->m_texte);
}
