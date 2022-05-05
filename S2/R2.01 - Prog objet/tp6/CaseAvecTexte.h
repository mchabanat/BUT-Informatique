#ifndef CASEAVECTEXTE_H
#define CASEAVECTEXTE_H

#include "Fenetre.h"
#include "Souris.h"
#include "Couleur.h"

#include "CaseACocher.h"

class CaseAvecTexte : public CaseACocher {
private :
    char* m_texte;
    void dessiner(Fenetre&,Couleur) const;
public:
    // Constructeurs
    CaseAvecTexte(CaseACocher = CaseACocher(),const char* = "Sans Texte");
    CaseAvecTexte(const CaseAvecTexte&);

    // Destructeur
    ~CaseAvecTexte();

    // Methodes
    void definirTexte(const char*);
    void afficher(Fenetre&) const;
    void effacer(Fenetre&) const;
};

#endif
