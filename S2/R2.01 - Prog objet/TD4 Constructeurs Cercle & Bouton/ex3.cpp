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
    b = Bouton(Cercle(coordX,coordY,rayon),etat);

    Souris s;
    int x,y,clic;

    // TRAITEMENTS
    s.associerA(f);
    f.apparait("Exercice 3");

    // Attente des clics
    while(true)
    {
        while(!s.testeBoutons(x,y,b));

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