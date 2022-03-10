#include "Fenetre.h"
#include "Souris.h"
#include "Couleur.h"
#include "CaseACocher.h"

int main (int argc, char **argv){

    gtk_init(&argc, &argv);

    // VARIABLES
    Fenetre f;

    Souris s;
    int x,y,b;


    int coordX = 200;
    int coordY = 200;
    int cote = 100;
    Couleur noir;
    CaseACocher cac(coordX-(cote/2),coordY-(cote/2),cote,noir,'R');

    // TRAITEMENTS
    f.apparait("Ex3 du TP Cases à cocher");
    s.associerA(f);

    noir.definir(0,0,0);

    f.delai(100);
    cac.afficher(f);


    while(true)
    {
        while(!s.testeBoutons(x,y,b));

        if(b==3)
        {
            f.disparait();
            break;
        }
        else if(b==1)
        {
            if(cac.cadre().touche(x,y))
            {
                if(cac.etat() == 'C')
                {
                    cac.effacer(f);
                    cac.definirEtat('N');
                    cac.afficher(f);
                }
                else
                {
                    cac.effacer(f);
                    cac.definirEtat('C');
                    cac.afficher(f);
                }
            }
        }
    }

    return 0;
}








