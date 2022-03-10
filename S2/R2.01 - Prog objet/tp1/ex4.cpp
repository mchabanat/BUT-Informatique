#include "Fenetre.h"
#include "Souris.h"

int main (int argc, char **argv){
    gtk_init(&argc, &argv);

    // VARIABLES
    Fenetre f;
    Souris s;
    Couleur noir(0,0,0);
    Couleur blanc(255,255,255);
    unsigned int ancienX,tresAncienX;
    unsigned int ancienY,tresAncienY;

    int x,y,bouton;
    bool clicked = false;

    //TRAITEMENTS
    f.apparait("Ex3");
    s.associerA(f);

    while(true){
        while(!s.testeBoutons(x,y,bouton));

        if(bouton==3){
            f.disparait();
            break;
        }
        else if (bouton==1){
            if(clicked){
                f.choixCouleurTrace(noir);
                f.traceLigne(ancienX,ancienY,x,y);
                tresAncienX = ancienX;
                tresAncienY = ancienY;
                ancienX = x;
                ancienY = y;
            }

            else{
                ancienX = x;
                ancienY = y;
                clicked = true;
            }
        }
        else  if(bouton == 2){
            f.choixCouleurTrace(blanc);
            f.traceLigne(ancienX,ancienY,tresAncienX,tresAncienY);
            ancienX = tresAncienX;
            ancienY = tresAncienY;
        }
    }



    return 0;
}
