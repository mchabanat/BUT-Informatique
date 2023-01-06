#include "Piece.h"
#include <string>

Piece::Piece(string ref,string lib,int price,int kilo) {
    reference = ref;
    libelle = lib;
    prix = price;
    poids = kilo;
}

int Piece::getPrix(){
    return prix;
}
void Piece::setPrix(int nvPrix){
    prix = nvPrix;
}

int Piece::getPoids(){
    return poids;
}
void Piece::setPoids(int nvPoids){
    poids = nvPoids;
}

string Piece::toString() {
    return "La piece referencee " + reference + " est " + libelle + " au prix de " + std::to_string(prix) + " euros. Elle pese " + std::to_string(poids) + " kilos.";
}