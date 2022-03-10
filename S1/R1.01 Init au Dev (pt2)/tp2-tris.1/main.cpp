/*
 Programme : test du module bibTableauxEntiers
 But :  Tester la conformité de chaque fonctionnalité du module bibTableauxEntiers
        par rapport aux jeux d'essais prévus
 Date de dernière modification : xxxx
 Auteur : xxx
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - TD n°3
*/

#include "BibTableaux.h"

// Declarations des sous programmes de test
void testRechercheDichoEntiers();
// BUT : Tester le sous prog recherchePremiereOccDichoEntier

void testRechercheDichoPersonne();
// BUT : Tester le sous prog recherchePremiereOccDichoPersonne

int main()
{
    testRechercheDichoPersonne();

    return 0;
}

// Definition des sous programmes de test
void testRechercheDichoEntiers()
{
    const unsigned int NB_CASES = 10;
    int tableau[NB_CASES] = {60, 45, 30, 25, 15, 10, 0, -15, -20, -45};
    int val = 0;
    unsigned int positionVal;
    bool existe;
    unsigned int compteur;

    recherchePremiereOccDichoEntier(tableau, NB_CASES, val, positionVal, compteur, existe);

    if (existe)
    {
        cout << "La valeur " << val << " se trouve a la position " << positionVal << " dans le tableau." << endl;
        cout << "La position de la valeur " << val << " a ete trouvee apres " << compteur << " acces aux cases du tableau." << endl;
    }
    else
    {
        cout << "La valeur " << val << " ne se trouve pas dans le tableau." << endl;
        cout << "Il y a eu  " << compteur << " recherche(s) pour tenter de trouver la valeur " << val << " dans le tableau." << endl;
    }
}

void testRechercheDichoPersonne()
{
    Personne etudiant1;
    Personne etudiant2;
    Personne etudiant3;
    Personne etudiant4;

    etudiant1.nom = "Chabanat";
    etudiant1.prenom = "Matis";
    etudiant1.adresse.numRue = "6";
    etudiant1.adresse.nomRue = "Rue des Coutiourlious";
    etudiant1.adresse.codePostal = 40230;
    etudiant1.adresse.nomVille = "Tyrosse";

    etudiant2.nom = "Le Menn";
    etudiant2.prenom = "Arthur";
    etudiant2.adresse.numRue = "8";
    etudiant2.adresse.nomRue = "Avenue de l'iut";
    etudiant2.adresse.codePostal = 64600;
    etudiant2.adresse.nomVille = "Anglet";

    etudiant3.nom = "Pericou";
    etudiant3.prenom = "Paul";
    etudiant3.adresse.numRue = "140";
    etudiant3.adresse.nomRue = "Rue des arènes";
    etudiant3.adresse.codePostal = 64600;
    etudiant3.adresse.nomVille = "Anglet";

    etudiant4.nom = "Melanchon";
    etudiant4.prenom = "JL";

    const unsigned int NB_CASES = 3;
    Personne effectif[NB_CASES] = {etudiant3,
                                   etudiant2,
                                   etudiant1};

    Personne recherche = etudiant4;
    unsigned int positionPersonne;
    bool existe;

    recherchePremiereOccDichoPersonne(effectif, NB_CASES, recherche, positionPersonne, existe);

    if (existe)
    {
        cout << "L'etudiant nomme " << recherche.prenom << " " << recherche.nom << " se trouve a la " << positionPersonne << "e place dans l'effectif.";
    }
    else
    {
        cout << recherche.prenom << " " << recherche.nom << " ne se trouve pas dans l'effectif.";
    }
}