#include "Fenetre.h"
#include "Souris.h"

int main (int argc, char **argv){
    gtk_init(&argc, &argv);

    // VARIABLES
    unsigned int i;
    unsigned int rayon = 100;
    unsigned int position = 50;
    Fenetre f;


    //TRAITEMENTS
    f.apparait("Ex2",200,200);
    f.choixCouleurTrace(0,0,0);

    for(i = 1 ; i <= 5 ; i++)
    {
        f.traceArc(position,position,rayon,rayon,0,360,2);

        rayon -= 20;
        position += 10;
    }

    f.delai(10000);

    return 0;
}
