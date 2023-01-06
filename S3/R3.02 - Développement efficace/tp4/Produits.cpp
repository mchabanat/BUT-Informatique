#include "Produits.h"
#include <string>

Produits::Produits(string ref,string lib,int price){
    reference = ref;
    libelle = lib;
    prix = price;
}

string Produits::toString(){
    return "Le produit reference " + reference + " est " + libelle + " au prix de " + std::to_string(prix) + " euros.";
}