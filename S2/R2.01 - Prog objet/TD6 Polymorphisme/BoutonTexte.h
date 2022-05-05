#ifndef BOUTONTEXTE_H
#define BOUTONTEXTE_H

#include "Bouton.h"

class BoutonTexte : public Bouton 
{
private:
    char* m_texte;
    void dessiner(Fenetre&,Couleur) const;
    void affecterTexte(const char*);
public:
    BoutonTexte();
    BoutonTexte(const BoutonTexte&);
    BoutonTexte(Bouton,const char*);

    ~BoutonTexte();

    void definirTexte(const char*);
    void afficher(Fenetre&) const;
    void effacer(Fenetre&) const;
}

#endif