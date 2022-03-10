#include "Fenetre.h"
#include "Couleur.h"
#include "Souris.h"
#include "Cercle.h"

int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);

    // VARIABLES
    Fenetre f;
    
    Cercle c;
    int coordX, coordY = 40;
    int rayon = 30;
    bool estBleu = false;

    Souris s;
    int x,y,b;

    // TRAITEMENTS
    s.associerA(f);
    f.apparait("Exercice 3");
    
    c.definirCouleur(255,0,0);
    c.placer(coordX,coordY); 
    c.dimensionner(rayon);
    c.afficher(f);

    while(true)
    {
        while(!s.testeBoutons(x,y,b));

        if(b==3)
        {
            f.disparait();
            break;
        }
        else if (b==1)
        {
            if (c.touche(x,y))
            {
                if (estBleu)
                {
                    c.definirCouleur(255,0,0);
                    c.afficher(f);
                }
                else
                {
                    c.definirCouleur(0,0,255);
                    c.afficher(f);
                }
            }
        }
    }




    return 0;
}