#include "Fenetre.h"
#include "Souris.h"

int main (int argc, char **argv){
    gtk_init(&argc, &argv);

    // VARIABLES
    Fenetre f;
    Souris s;
    Couleur coul(0,0,0);
    unsigned int ancienX = 0;
    unsigned int ancienY = 0;
    int bouton;
    int x,y;

    //TRAITEMENTS
    f.apparait("Ex3");
    s.associerA(f);

    f.choixCouleurTrace(coul);

    while(true){
        while(!s.testeBoutons(x,y,bouton));

        if(bouton==3){
            f.disparait();
            break;
        }
        else if (bouton==1){
            f.traceLigne(ancienX,ancienY,x,y);
        }

        ancienX = x;
        ancienY = y;
    }



    return 0;
}
