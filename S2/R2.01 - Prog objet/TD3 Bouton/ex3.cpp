#include "Fenetre.h"
#include "Couleur.h"
#include "Souris.h"
#include "Cercle.h"
#include "Bouton.h"

int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);

    // VARIABLES
    Fenetre f;
    
    Bouton b;
    int coordX, coordY = 200;
    int rayon = 30;
    bool etat = false;

    Souris s;
    int x,y,b;

    // TRAITEMENTS
    s.associerA(f);
    f.apparait("Exercice 3");
    
    // Dessin du bouton
    b.definir(coordX,coordY,rayon,0,0,255,etat);
    b.afficher(f);

    // Attente des clics
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
            if (b.touche(x,y))
            {
                b.effacer(f);
                if(etat)
                {
                    b.desactiver();
                }
                else
                {
                    b.activer();
                }
                b.afficher(f);
            }
        }
    }

    cout << "Bisous <3";

    return 0;
}