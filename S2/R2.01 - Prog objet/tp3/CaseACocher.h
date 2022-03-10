#ifndef CASEACOCHER_H
#define CASEACOCHER_H

#include "Carre.h"


class CaseACocher {
private :
    Carre m_carre;
    bool m_estActif;
    void dessiner(Fenetre&,Couleur) const;
public :
    void definirCadre(int,int,int,Couleur = Couleur(0,0,0));
    Carre cadre() const;
    void definirEtat(char);
    char etat() const;
    void afficher(Fenetre&) const;
    void effacer(Fenetre&) const;
};
#endif
