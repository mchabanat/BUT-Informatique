#include <iostream>
using namespace std;

#include <string>
#include <list>
#include <map>

//Déclarations
void listeSimple();
void listePaires();
void leMap();

int main (void)
{
    // listeSimple();
    //listePaires();
    leMap();

    return 0;
}

//Definitions
void leMap() {
    typedef map<string,string> Annuaire;
    Annuaire unAnnuaire;

    typedef pair<Annuaire::iterator,bool> ResultatInsert;
    ResultatInsert unResultatInsert;

    Annuaire::iterator iterateur;

    unResultatInsert = unAnnuaire.insert(Annuaire::value_type("Pantxica","06.01.01.01.01"));
    
    //Test:
    /*if (unResultatInsert.second == true){
        cout << "insertion BIEN realise";
    }
    else{
        cout << "insertion MAL realise";
    }*/

    unResultatInsert = unAnnuaire.insert(Annuaire::value_type("Yann","06.02.02.02.02"));
    unResultatInsert = unAnnuaire.insert(Annuaire::value_type("Philippe","06.03.03.03.03"));
    unResultatInsert = unAnnuaire.insert(Annuaire::value_type("Patoche","06.04.04.04.04"));

    iterateur = unAnnuaire.begin();

    while(iterateur != unAnnuaire.end()) {
        cout << iterateur->second << endl; //affiche ce qui est pointé par iterateur
        iterateur++;
    }

    iterateur = unAnnuaire.begin();
    while(iterateur != unAnnuaire.end()) {
        if(iterateur->first == "Philippe"){
            break;
        }
        iterateur++;
    }
    // Resultat (1 : Si Philippe pas trouvé / 2 : affichage numéro en fonction de la clef philippe
    if(iterateur->first != "Philippe"){
        cout << "Philippe clef inconnue" << endl;
    }
    else{
        cout << iterateur->second << endl;
    }
}

void listePaires() {
    typedef pair<string,string> Paire;
    typedef list<Paire> ListeP;

    ListeP uneListeP;

    uneListeP.push_back(ListeP::value_type("Pantxica","06.01.01.01.01"));
    uneListeP.push_back(ListeP::value_type("Yann","06.02.02.02.02"));
    uneListeP.push_back(ListeP::value_type("Philippe","06.03.03.03.03"));
    uneListeP.push_back(ListeP::value_type("Patoche","06.04.04.04.04"));

    ListeP::iterator iterateur;

    iterateur = uneListeP.begin();
    while(iterateur != uneListeP.end()) {
        cout << iterateur->first << " - " << iterateur->second << endl; //affiche ce qui est pointé par iterateur
        iterateur++;
    }
}

void listeSimple(){
    typedef list<string> ListeS;
    ListeS uneListeS;
    
    uneListeS.push_back(ListeS::value_type("Pantxica"));
    uneListeS.push_back(ListeS::value_type("Yann"));
    uneListeS.push_back(ListeS::value_type("Philippe"));
    uneListeS.push_back(ListeS::value_type("Patoche"));

    ListeS::iterator iterateur;

    iterateur = uneListeS.begin();
    while(iterateur != uneListeS.end()) {
        cout << *iterateur << endl; //affiche ce qui est pointé par iterateur
        iterateur++;
    }
}

