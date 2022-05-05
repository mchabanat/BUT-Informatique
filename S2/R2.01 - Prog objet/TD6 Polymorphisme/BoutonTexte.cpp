#include "BoutonTexte.h"

void BoutonTexte::affecterTexte(const char* txt)
{
    this->m_texte = new char [strlen(txt)+1];
    strcpy(this->m_texte,txt);
}

BoutonTexte::BoutonTexte():
    Bouton()
{
    this->affecterTexte("Sans Texte");
}

BoutonTexte::BoutonTexte(const BoutonTexte& original):
    Bouton(original)
{
    this->affecterTexte(original.m_texte);
}

BoutonTexte::BoutonTexte(Bouton b,const char* txt):
    Bouton(b)
{
    this->affecterTexte(txt);
}

BoutonTexte::~BoutonTexte()
{
    delete [] this->m_texte;
}

void BoutonTexte::definirTexte(const char* txt)
{
    delete [] this->m_texte;
    this->affecterTexte(txt);
}

void BoutonTexte::afficher(Fenetre& f) const
{
    this->Bouton::afficher(f);
    this->dessiner(f,this->couleur())
}

void BoutonTexte::effacer(Fenetre& f) const
{
    this->Bouton::effacer(f);
    this->dessiner(f,f.couleurFond());
}

void BoutonTexte::dessiner(Fenetre& f,Couleur c) const
{
    f.choixCouleurTrace(c);
    f.ecrit(this->coordX()+(3*this->rayon())/2,
            this->coordY()+this->rayon()+6,
            this->m_texte);
}