#include "Fenetre.h"
#include "Souris.h"
#include "Couleur.h"
#include "Carre.h"

int main (int argc, char **argv){

    gtk_init(&argc, &argv);

    // VARIABLES
    Fenetre f;

    Souris s;
    int x,y,b;

    Carre c;
    bool estBleu = false;

    Couleur rouge;
    Couleur bleu;

    // TRAITEMENTS
    f.apparait("Ex3 du TD avec un Carré");
    s.associerA(f);

    rouge.definir(255,0,0);
    bleu.definir(0,0,255);

    c.placer(40,40);
    c.dimensionner(30);
    c.definirCouleur(rouge);
    c.afficher(f);

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
            if(c.touche(x,y))
            {
                if(!estBleu)
                {
                    c.definirCouleur(bleu);
                    estBleu = true;
                }
                else
                {
                    c.definirCouleur(rouge);
                    estBleu = false;
                }
                c.afficher(f);
            }
        }
    }

    return 0;
}







