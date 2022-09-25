#include <iostream>
using namespace std;

#include "Individu.h"
#include "Voiture.h"

int main (void)
{
    Voiture voit1("RenaultClio","123AB64");
    Voiture voit2("Peugeot106","678CD96");
    Voiture voit3("CitroenPicasso","456EF75");

    Individu ind1("Cocheril","Boss");    
    Individu ind2("Salle","Oumar");    
    Individu ind3("Cabot","Arthuro");    

    ind3.setVoiture(&voit3);
    voit3.setIndividu(&ind3);

    voit3.setPlaque("77777NO22");

    cout << "Plaque de la voiture pilotee par ind3 \n";
    cout << ind3.getVoiture()->getPlaque();

    return 0;
}
