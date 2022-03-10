/*
 Programme : 
 But : 
 Date de dernière modification : 
 Auteur : Chabanat M
 Remarques : ca fonctionne 
*/

#include <iostream>
using namespace std;

struct Adresse
{
    string numRue;           // le numéro de rue (par exemple 2bis)
    string nomRue;           // Le nom de la rue (par exemple allée du Parc Montaury)
    unsigned int codePostal; // Le code postal (par exemple 64600)
    string ville;            // le nom de la ville (par exemple Anglet)
};

struct Personne
{
    string nom;      // Le nom de la personne
    string prenom;   // Le prénom de la personne
    Adresse adresse; // L'adresse de la personne
};



// Declaration
Adresse donnerAdresse(Personne personne);
/* BUT : Retourner l'adresse d'une personne personne */

int main(void)
{
    // VARIABLES
    Personne jeanmich = {"Chips","Jean-Michel",{"2","Allée du stade de France",95000,"Paris"}};
    Adresse adressePersonne = donnerAdresse(jeanmich);

    // TRAITEMENTS
    cout << "Jean-Michel habite a : " << adressePersonne << endl;

    return 0;
}

// Definition
Adresse donnerAdresse(Personne personne)
{
    return personne.adresse;
}