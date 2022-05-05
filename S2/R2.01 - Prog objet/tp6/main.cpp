#include "Fenetre.h"
#include "Souris.h"
#include "Carre.h"
#include "CaseACocher.h"
#include "FenGrille.h"

int main (int argc, char **argv){

    gtk_init(&argc, &argv);

    FenGrille f("Test",600,600,0,0,255,255,255,20,40);
    Souris s;
    int x,y,b;
    s.associerA(f);

    CaseACocher c1(40,40,50,(0,0,0),'C');
    CaseACocher c2(400,40,50,(0,0,0));

    f.afficherCase(c1);
    f.afficherCase(c2);

    while(!s.testeBoutons(x,y,b));
    f.effacer(); // Test de effacer()
    while(!s.testeBoutons(x,y,b));

    return 0;
}
