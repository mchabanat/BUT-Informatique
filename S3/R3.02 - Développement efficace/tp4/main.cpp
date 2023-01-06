#include <iostream>
using namespace std;

#include <string>
#include <list>
#include <map>
#include <algorithm>

#include "Produits.h"
#include "Piece.h"

//Déclarations au niveau global
    // Définition de 4 types de données : Libelle, Reference, Prix et Poids
    typedef string Libelle;
    typedef string Reference;
    typedef int Prix;
    typedef int Poids;

    //Variable globale
    Reference referenceCherchee = "fruits";

//Déclarations sous prog
void exempleDeFind();
void exempleDeFindIf();
bool memeReference(Produits p);
void afficher(Piece* unePiece);
void surPoids(Piece* unePiece);
bool tropCestTrop(Piece* unePiece);
void exempleForEachEtPartition();
void afficherSup100(Piece* unePiece); // Affiche uniquement les pieces dont le prix est superieur a 100
void afficherInf100(Piece* unePiece); // Affiche uniquement les pieces dont le prix est inferieur a 100


int main (void)
{
    // exempleDeFind();
    // exempleDeFindIf();
    exempleForEachEtPartition();
    

    return 0;
}

//Définitions sous prog
void afficherSup100(Piece* unePiece){
    if(tropCestTrop(unePiece)) {
        cout << unePiece->toString() << endl;
    }
}
void afficherInf100(Piece* unePiece) {
    if(!tropCestTrop(unePiece)) {
        cout << unePiece->toString() << endl;
    }
}
void exempleForEachEtPartition( ){
    Piece p1("viande","Cotes de boeuf",10,90);
    Piece p2("personne","The Rock",450,150);
    Piece p3("legume","Courgette",1,2);
    Piece p4("vehicule","Velo",200,15);

    typedef list<Piece*> ListeDePiece;
    ListeDePiece uneListeDePiece;

    uneListeDePiece.push_back(ListeDePiece::value_type(&p1));
    uneListeDePiece.push_back(ListeDePiece::value_type(&p2));
    uneListeDePiece.push_back(ListeDePiece::value_type(&p3));
    uneListeDePiece.push_back(ListeDePiece::value_type(&p4));

    for_each(uneListeDePiece.begin(),uneListeDePiece.end(),afficher);
    cout << endl;
    for_each(uneListeDePiece.begin(),uneListeDePiece.end(),surPoids);
    partition(uneListeDePiece.begin(),uneListeDePiece.end(),tropCestTrop);
    for_each(uneListeDePiece.begin(),uneListeDePiece.end(),afficherSup100);
    cout << endl;
    for_each(uneListeDePiece.begin(),uneListeDePiece.end(),afficherInf100);
}
bool tropCestTrop(Piece* unePiece) {
    return (unePiece->getPrix() > 100 ? true : false);
}
void surPoids(Piece* unePiece) {
    int poids = unePiece->getPoids();
    int prix = unePiece->getPrix();

    if(poids > 80){
        prix += (prix*10/100);
        unePiece->setPrix(prix);
    }
}
void afficher(Piece* unePiece) {
    cout << unePiece->toString() << endl;
}


bool memeReference(Produits p){
    if(p.reference == referenceCherchee){
        return true;
    }
    else {
        return false;
    }
}
void exempleDeFindIf(){
    typedef list<Produits> ListeDeProduits;
    ListeDeProduits uneListeDeProduits;

    uneListeDeProduits.push_back(ListeDeProduits::value_type("epices","Curry",5));
    uneListeDeProduits.push_back(ListeDeProduits::value_type("fruits","Orange",2));
    uneListeDeProduits.push_back(ListeDeProduits::value_type("legumes","Courgette",1));

    ListeDeProduits::iterator iterateur;

    iterateur = find_if(uneListeDeProduits.begin(),uneListeDeProduits.end(),memeReference);
    
    if(iterateur!=uneListeDeProduits.end()){
        cout << "L'article " << iterateur->libelle << " coute " << iterateur->prix << " euros." << endl;
    }
    else{
        cout << "Produit introuvable" << endl;
    }
}


void exempleDeFind(){
    typedef pair<Libelle,Prix> Produit;
    typedef map<Reference,Produit> MapDeProduit;
    MapDeProduit unMapDeProduit;

    Produit unProduit1;
    unProduit1.first = "Souris";
    unProduit1.second = 10;
    unMapDeProduit.insert(MapDeProduit::value_type("Curseurs01",unProduit1));

    Produit unProduit2;
    unProduit2.first = "Clavier";
    unProduit2.second = 50;
    unMapDeProduit.insert(MapDeProduit::value_type("Claviers01",unProduit2));

    Produit unProduit3;
    unProduit3.first = "Moniteur";
    unProduit3.second = 100;
    unMapDeProduit.insert(MapDeProduit::value_type("Moniteurs01",unProduit3));

    Reference referenceRecherchee = "Claviers01";
    MapDeProduit::iterator existe;

    existe = unMapDeProduit.find(referenceRecherchee);
    if (existe != unMapDeProduit.end()){
        cout << "Libelle : " << existe->second.first << " / Prix : " << existe->second.second << endl;
    }
    else{
        cout << "echec de recherche" << endl;
    }
}