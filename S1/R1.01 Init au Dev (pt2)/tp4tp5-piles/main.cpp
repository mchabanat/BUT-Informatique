/*
 Programme : Hanoi - itératif - avec Tableau de piles et sous-programmes 
 But :  Résolution des tours de Hanoi - version itérative - pour 3 à 9 disques
 Date de dernière modification : 04-12-2021
 Auteur : M Chabanat
 Remarques : Code conforme aux spécifications précisées dans le sujet R1.01-partie2 - TD n°4
*/
#include <iostream>
#include "pile.h"
using namespace std;

const unsigned int NB_TOURS = 3; // CONSTANTE dite 'GLOBALE' : accéssible dans les sous programmes
                                 // portée = tous les Sous-programmes
                                 // présents dans ce fichier

/* ---------- Observateurs
   ------------------------------------------------------------------*/
bool estDeplacable(UnePile tourDepart, UnePile tourArrivee);
// BUT : si on peut déplacer le disque de la tourDepart à la tourArrivee alors true, false sinon

unsigned int positionTourSuivante(unsigned int positionTour);
// But : retourne la position suivante du paramètre positionTour, à savoir :
// 1 si positionTour = 0
// 2 si positionTour = 1
// 0 si positionTour = 2 

bool sontVides(const UnePile &tourA, const UnePile &tourB);
// But : retourne vrai si les deux tours tourA et tourB sont vides, faux sinon

/* ---------- Primitives modifiant 1 tour
   ------------------------------------------------------------------*/

void remplirTour(UnePile &tourARemplir, unsigned int nbDisques);
// But : remplit la tourARemplir avec nbDisques, du plus grand (en bas) au plus
// petit (au sommet) de la tour

/* ---------- Primitives modifiant plusieurs tours
   ------------------------------------------------------------------*/

void initialiserTours(UnePile lesTours[]);
// But : initialise les NB_TOURS tours du tableau lesTours

void deplacerDisque(UnePile &tourDepart, UnePile &tourArrivee);
// But : déplace un disque d'une tour (tourDepart) à une autre (tourArrivee)
// pré-condition : estDeplacable(tourOrigine, tourDestination) est VRAI
//                 c'est à dire :
//
//                 estVide(tourOrigine)  = FAUX
//                 et  (
//                        (estVide(tourDestination) = VRAI )
//                         OU
//                        ( estVide(tourDestination)  = FAUX
//                          et
//                          sommet(tourOrigine) < sommet(tourDestination)
//                         )
//                     )


/* ---------- Affichages
   ------------------------------------------------------------------*/

void afficherTour(UnePile tour);
// Affiche le contenu de la tour passée en paramètre

void afficherTours(const UnePile lesTours[]);
// Affiche le contenu des tours passées en paramètre (pour le nombre de tours on utilisera NB_TOURS en variable globale)

void afficherToursGraphique(const UnePile lesTours[], const unsigned short int &nDisques);
// Affiche le contenu des tours dans le tableau passe en parametres en fonction du nombre de disques

/* ---------- Algorithmes de résolution du problème des tours de Hanoi
   --------------------------------------------------------------------*/

void resoudreToursHanoiManuel(unsigned int nbDisques);
// Buts : 1- faire résoudre les tours de Hanoi avec nbDisques au joueur
//        2-pour tester les primitives
//        - initialiserTours()
//        - remplirTour()
//        - afficherTour()
//        - afficherTours()
//        - deplacerDisque()

void resoudreToursHanoiAutomatique(unsigned int nbDisques);
// But : résoudre automatiquement les tours de Hanoi avec nbDisques disques

/* ---------- Boîte à outils pour resolutionToursHanoiManuel ()
   -------------------------------------------------------------------*/

void saisieVerifDeplacementDemande(bool &reponseOk, unsigned int &origine, unsigned int &destination);
// saisie du choix des tours prenant part au déplacement d'un disque :
// 12 pour deplacement d'un disque de la tour 1 vers la tour 2
// 13 pour deplacement d'un disque de la tour 1 vers la tour 3
// 31 pour deplacement d'un disque de la tour 3 vers la tour 1
// ...
// 0 si aucun deplacement demandé

int carToChiffre(char car);
// convertit un caractère en chiffre

/* ---------- Boîte à outils pour resolutionToursHanoiAutomatique ()
   -------------------------------------------------------------------*/
void deplacerPetit(UnePile lesTours[], unsigned int& posPetit);
/* Déplace :
 - le plus petit disque, situé dans la tour indiquée par posPetit
 - vers la tour suivante, toujours dans l’ordre t1 -> t2 -> t3 -> t1 ...
 Et met à jour posPetit pour préparer le prochain tour
 */ 

void deplacerAutre(UnePile lesTours[], unsigned int posDisque);
// But : déplace le seul disque deplaçable autre que le plus petit
// pré-condition : le déplacement est possible


// ======================================================================
int main()
{

    const unsigned int NB_MINIMUM_DISQUES = 3; // nbre minimum autorisé de disques
    const unsigned int NB_MAXIMUM_DISQUES = 9; // nbre maximum autorisé de disques
    unsigned int nbDisques;                    // nbre de disques à déplacer

    // (clavier), NB_MINIMUM_DISQUES, NB_MINIMUM_DISQUES >> saisie du nbre de disques >> nbDisques
    do
    {
        cout << "Entrer le nbre de disques de la tour de Hanoi (entre " << NB_MINIMUM_DISQUES << " et " << NB_MAXIMUM_DISQUES << ") : ";
        cin >> nbDisques;
    } while (!((nbDisques >= NB_MINIMUM_DISQUES) && (nbDisques <= NB_MAXIMUM_DISQUES)));
    cout << endl;

    // nbDisques >>  résoudre Hanoi manuellement pour le nb de disques entré >> ()
    // resoudreToursHanoiManuel(nbDisques);

    // nbDisques >> résoudre Hanoi automatiquement pour le nb de disques entré >> ()
    resoudreToursHanoiAutomatique(nbDisques);

    return 0;
}

// ======================================================================

// ---------- Observateurs
bool estDeplacable(UnePile tourDepart, UnePile tourArrivee)
{
    bool possibilite = false;

    // Recherche
    if (!estVide(tourDepart) && estVide(tourArrivee))
    {
        possibilite = true;
    }
    else if (!estVide(tourDepart) && !estVide(tourArrivee))
    {
        possibilite = (sommet(tourArrivee) > sommet(tourDepart));
    }

    return possibilite;
}

unsigned int positionTourSuivante(unsigned int positionTour)
{
    unsigned int futurPos;

    futurPos =(positionTour+1) % NB_TOURS;

    return futurPos;
}

bool sontVides(const UnePile &tourA, const UnePile &tourB)
{
    // Si les 2 tours en paramètres sont vides alors return true
    return (estVide(tourA) && estVide(tourB));
}

// ---------- Primitives modifiant 1 tour
void remplirTour(unsigned int nbDisques, UnePile &tourARemplir)
{
    unsigned int i;

    for (i = nbDisques; i > 0; i--)
    {
        empiler(tourARemplir, i);
    }
}

// ---------- Primitives modifiant plusieurs tours
void initialiserTours(UnePile lesTours[])
{
    unsigned int i;

    for (i = 0; i <= NB_TOURS - 1; i++)
    {
        initialiser(lesTours[i]);
    }
}

void deplacerDisque(UnePile &tourDepart, UnePile &tourArrivee)
{
    unsigned int disqueADeplacer;

    if (estDeplacable(tourDepart, tourArrivee))
    {
        depiler(tourDepart, disqueADeplacer);
        empiler(tourArrivee, disqueADeplacer);
    }
    else
    {
        cout << endl;
        cout << "Deplacement impossible !" << endl;
        cout << endl;
    }
}



// ---------- Affichages

void afficherTour(UnePile tour)
// paramètre passé par valeur
{
    unsigned int disque;
    cout << "{ ";
    while (!estVide(tour))
    {
        depiler(tour, disque);
        cout << disque << ". ";
    }
    cout << " }";
}

void afficherTours(const UnePile lesTours[])
{
    unsigned int i;

    for (i = 0; i <= NB_TOURS - 1; i++)
    {
        afficherTour(lesTours[i]);
    }
}

void afficherToursGraphique(const UnePile lesTours[], const unsigned int &nbDisques)
{
    // VARIABLES
    unsigned short int espaceMilieu;        //Nombre de characteres séparant une bordure du centre
    unsigned short int espaceBordure;       //Espace séparant la bordure (|) d'un disque (-)
    unsigned short int largeur;             //Nombre de characteres séparant les 2 bordures (|)
    unsigned short int tailleDisque;        //Nombre de tirets représentant un disque
    
    UnePile copieTours[3];                  //Copie de lesTours qui est modifiable
    UnElement nombreDepile;                 //Disque (nombre) depilé d'une tour
    
    // TRAITEMENTS
    largeur = static_cast<unsigned short int>(1 + 2 * nbDisques) ;
    for (unsigned int i = 0; i < 3; i++)
    {
        copieTours[i] = lesTours[i];
    }
    
    espaceMilieu = largeur/2;

    // -- Affichage entête de grille --
    //Premiere ligne
    cout << "|";
    for (unsigned short int i = 0; i < 6 ; i++)
    {
        for (unsigned short int n = 0; n < espaceMilieu; n++)
        {
            cout << " ";
        }
        if (i%2 == 0)
        {
            cout << 1 + i/2;
        }
        else
        {
            cout << "|";
        }
    }
    
    cout << endl;

    //Deuxieme ligne
    cout << "|";
    for (unsigned short int i = 0; i < 3; i++)
    {
        for (unsigned n = 0; n < largeur; n++)
        {
            cout << "-";
        }
        cout << "|";
    }
    cout << endl;


    //Autres lignes
    for (unsigned short int etage = static_cast<unsigned short int>(nbDisques) ; etage > 0 ; etage--)
    {
        cout << "|";
        for (unsigned short int colonne = 0; colonne < 3; colonne++)
        {
            if(taille(copieTours [colonne]) == etage)
            {
                //Depilement
                depiler(copieTours[colonne],nombreDepile);

                //Calculs taille et espacements
                tailleDisque =  static_cast<unsigned short int>(nombreDepile*2-1);
                espaceBordure = static_cast<unsigned short int>((largeur - tailleDisque)/2);

                //Affichage disques
                for (unsigned int i = 0; i < espaceBordure; i++)
                {
                    cout << " ";
                }
                for (unsigned int i = 0; i < tailleDisque; i++)
                {
                    cout << "_";
                }
                for (unsigned int i = 0; i < espaceBordure; i++)
                {
                    cout << " ";
                }
                
                cout << "|";
            }
            else
            {
                //Affiche ligne vide
                for (unsigned int i = 0; i < largeur; i++)
                {
                    cout << " ";
                }
                cout << "|";
            }
        }
        cout << endl;
    }
    

    //Dernière ligne
    cout << "|";
    for (unsigned short int i = 0; i < 3; i++)
    {
        for (unsigned n = 0; n < largeur; n++)
        {
            cout << "m";
        }
        cout << "|";
    }
}

// ---------- Algorithme de résolution du problème des tours de Hanoi

void resoudreToursHanoiManuel(unsigned int nbDisques)
{
    UnePile lesTours[NB_TOURS];

    unsigned int tourOrigine;     // tour origine du déplacement
    unsigned int tourDestination; // tour destination du déplacement
    bool deplacementDemande;      // = vrai si, mors de la saisie, un déplacement est demandé,
                                  // = faux si pas de déplacement demandé

    // Initialiser tours et éléments de la réussite
    initialiserTours(lesTours);
    remplirTour(nbDisques, lesTours[0]);
    afficherToursGraphique(lesTours,nbDisques);
    cout << endl;

    // faire des déplacements manuels jusqu'à gagner
    do
    {
        // saisie - verif
        saisieVerifDeplacementDemande(deplacementDemande, tourOrigine, tourDestination);

        if (deplacementDemande)
        {
            // faire le déplacement demandé
            deplacerDisque(lesTours[tourOrigine], lesTours[tourDestination]);
            afficherToursGraphique(lesTours,nbDisques);
        }
    } while (!(estVide(lesTours[0]) && estVide(lesTours[1])));
}

void resoudreToursHanoiAutomatique(unsigned int nbDisques)
{
    UnePile lesTours[NB_TOURS];
    unsigned int posTourAvecPlusPetitDisque = 0;

    // Préparer les tours
    initialiserTours(lesTours);
    remplirTour(nbDisques, lesTours[0]);
    afficherToursGraphique(lesTours,nbDisques);
    cout << endl << "-----------------------------------------------" << endl<< endl;

    // lesTours >> déplacer les disques >> lesTours
    while (true)
    {
        if (sontVides(lesTours[0], lesTours[1]))
        {
            break;
        }

        deplacerPetit(lesTours, posTourAvecPlusPetitDisque);
        afficherToursGraphique(lesTours,nbDisques); cout << endl;

        if (sontVides(lesTours[0], lesTours[1]))
        {
            break;
        }

        deplacerAutre(lesTours, posTourAvecPlusPetitDisque);
        afficherToursGraphique(lesTours,nbDisques); cout << endl << endl;
    }
}

/* ---------- Boîte à outils pour Hanoi Manuel 
   -------------------------------------------------------------------*/

void saisieVerifDeplacementDemande(bool &deplacement, unsigned int &origine, unsigned int &destination)
{
    string demandeSaisie; // la demande de déplacement saisie
    bool reponseOk;       // indicateur de validité de la réponse saisie : "12", "21", .... "31", ou "0xx"

    deplacement = false; // = faux si l'utilisateur saisit "0" (pas de déplacement), vrai s'il saisit une des autres combinaisons autorisées
    cout << endl
         << " tourOrigine-tourDestination (exple : 12), 0 si pas de deplacement ";

    do
    {
        // saisie
        cout << " : ";
        cin >> demandeSaisie;

        // analyse de validité
        reponseOk = false;
        if (
            (demandeSaisie[0] == '0') || ((demandeSaisie[0] >= '1') && (demandeSaisie[0] <= '3') && (demandeSaisie[1] >= '1') && (demandeSaisie[1] <= '3')))
        {
            reponseOk = true;
        }
    } while (!reponseOk);

    // demandeSaisie >> Analyse de la réponse correcte >>  >> deplacement, [origine, destination]
    if (demandeSaisie[0] != '0')
    {
        origine = carToChiffre(demandeSaisie[0]) - 1;
        destination = carToChiffre(demandeSaisie[1]) - 1;
        deplacement = true;
    }
}

int carToChiffre(char car)
{
    int chiffre;
    chiffre = int(car - int('0'));
    return chiffre;
}

/* ---------- Boîte à outils pour resolutionToursHanoiAutomatique ()
   -------------------------------------------------------------------*/

void deplacerPetit(UnePile lesTours[], unsigned int& posPetit)
{
    // Calculer la future posPetit
    unsigned int futurPetit = positionTourSuivante(posPetit);

    // Deplacer le disque
    deplacerDisque(lesTours[posPetit], lesTours[futurPetit]);
    
    // Mettre à jour posPetit
    posPetit = futurPetit;
} 

void deplacerAutre(UnePile lesTours[], unsigned int posDisque)
{
    unsigned int suivante = positionTourSuivante(posDisque);

    unsigned int restante = positionTourSuivante(suivante);

    // Tenter de déplacer un disque
    if(estDeplacable(lesTours[suivante],lesTours[restante]))
    {
        deplacerDisque(lesTours[suivante],lesTours[restante]);
    }
    else if(estDeplacable(lesTours[restante],lesTours[suivante]))
    {
        deplacerDisque(lesTours[restante],lesTours[suivante]);
    }
}