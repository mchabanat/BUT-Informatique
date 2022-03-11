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

    int coordX = 200;
    int coordY = 200;
    int rayon = 200;
    bool etat = false;
    Couleur noir;
    noir.definir(0,0,0);
    Bouton b(Cercle(coordX,coordY,rayon,noir),etat);

    Souris s;
    int x,y,clic;

    // TRAITEMENTS
    s.associerA(f);
    f.apparait("Exercice 3");

    b.afficher(f);

    // Attente des clics
    while(true)
    {
        while(!s.testeBoutons(x,y,clic));

        if(clic==3)
        {
            f.disparait();
            break;
        }
        else if (clic==1)
        {
            if (b.touche(x,y))
            {
                b.effacer(f);
                if(b.actif())
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

    return 0;
}
