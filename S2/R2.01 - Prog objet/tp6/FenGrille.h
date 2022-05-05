#ifndef FENGRILLE_H
#define FENGRILLE_H

#include "Fenetre.h"
#include "CaseACocher.h"

class FenGrille : public Fenetre
{
private:
    int m_largeur,m_hauteur;
public:
    //Constructeurs
    FenGrille(int = 20,int = 20);
    FenGrille(const char* ="Sans nom", int=400, int=400, int=0, int=0, int=255, int=255, int=255,int=20,int=20); // 2 derniers paramètres sont la largeur et la hauteur de chaque case, le reste sont les paramètres d'une fenetre normale
    FenGrille(const FenGrille&);

    // Méthodes
    void apparait(const char* ="Sans nom", int=400, int=400, int=0, int=0, int=255, int=255, int=255);
    void effacer();
    void afficherCase(CaseACocher);
};

#endif // FENGRILLE_H
