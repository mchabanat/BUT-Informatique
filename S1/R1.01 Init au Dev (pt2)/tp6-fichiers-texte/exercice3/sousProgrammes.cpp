#include <iostream>
#include "sousProgrammes.h"

using namespace std;

// Sous-programmes utilisés par les sous-programmes de cryptage
// ---------------------------------------------------------------------
string genererNom(string nom);
/* retourne un nouveau nom de fichier contenant --> _crypted
   cas de figure :
   nom    -->  nouveauNom généré     : motif
   .           .                     : nom de fichier illégal, la fonction retourne le paramètre initial donné
   .h          .h_crypted            : le point est ici unla marque d'un fichier caché, "_crypted" est donc ajouté  
                                       en fin de nom pour que le nouveau nom de fichier soit aussi un nom de fichier caché
   x.          x._crypted            : pas de suffixe après la point, "_crypted" ajouté en fin de nom
   x           x_crypted             : pas de suffixe, "_crypted" ajouté en fin de nom
   x.h         x_crypted.h           : "_crypted" inséré avant le point de suffixe
   x.js        x_crypted.js          : "_crypted" inséré avant le point de suffixe
   x.cpp       x_crypted.cpp         : "_crypted" inséré avant le point de suffixe
   x.data      x_crypted.data        : "_crypted" inséré avant le point de suffixe
   x.config    x_crypted.config      : "_crypted" inséré avant le point de suffixe
   x.texinfo   x_crypted.texinfo     : "_crypted" inséré avant le point de suffixe
   x.12345678  x.12345678_crypted    : au dela de 7 caractères après le point, on considère
                                       que le point fait partie du nom du fichier et ne marque pas
                                       un suffixe --> "_crypted" ajouté en fin de nom
   ../x.h      ../x_crypted.h
   ../x        ../x_crypted
   ./x.h       ./x_crypted.h
   ./x         ./x_crypted

    sources : https://fr.wikipedia.org/wiki/Extension_de_nom_de_fichier
              https://fr.wikipedia.org/wiki/Liste_d%27extensions_de_fichiers
    
    cas particulier non (ou mal traité) : x.tar.gz --> x.tar_crypted.gz
   */
// ---------------------------------------------------------------------

string cryptage(string nomSysFicSource)
{
    // VARIABLES
    UnFichierTexte fic;
    UnFichierTexte nvFic;
    string nvNomSys;
    bool fdf;
    char carEnCours;
    char nvCarac;

    // Generer le nom du fichier apres cryptage
    nvNomSys = genererNom(nomSysFicSource);

    // Préparer les fichiers
    associer(fic, nomSysFicSource);
    associer(nvFic, nvNomSys);
    ouvrir(fic, consultation);
    ouvrir(nvFic, creation);

    // TRAITEMENTS
    while (true)
    {
        // Tentative de lecture
        lireCar(fic, carEnCours, fdf);

        // Condition de sortie
        if (fdf)
        {
            break;
        }

        // Définition du nouveau caractère
        switch (carEnCours)
        {
            case 'a': nvCarac = 'e'; break;
            case 'A': nvCarac = 'E'; break;
            case 'e': nvCarac = 'i'; break;
            case 'E': nvCarac = 'I'; break;
            case 'i': nvCarac = 'o'; break;
            case 'I': nvCarac = 'O'; break;
            case 'o': nvCarac = 'u'; break;
            case 'O': nvCarac = 'U'; break;
            case 'u': nvCarac = 'y'; break;
            case 'U': nvCarac = 'Y'; break;
            case 'y': nvCarac = 'a'; break;
            case 'Y': nvCarac = 'A'; break;
            default: nvCarac = carEnCours; break;
        }

        // Ecriture dans le nouveau fichier
        ecrire(nvFic, nvCarac);
    }

    // Fermeture des fichiers
    fermer(fic);
    fermer(nvFic);

    // retourner le nom du fichier créé
    return nvNomSys;
}

string cryptage(string nomSysFicSource, string nomSysFicCodes)
{
    // TYPE 
    struct UnBinome 
    {
        char carEnClair;
        char carCrypte;
    };

    // VARIABLES
    UnFichierTexte fic;
    UnFichierTexte nvFic;
    UnFichierTexte ficCodes;
    string nvNomSys;
    
    bool fdfCodes;
    bool fdf;
    string carEnClair;
    string carCorrespondant;
    char car;
    char carCrypte;
    unsigned int posCourante;

    UnBinome binomes[25];
    unsigned int nbBinomes;

    // Generer le nom du fichier apres cryptage
    nvNomSys = genererNom(nomSysFicSource);

    // Préparer les fichiers
    associer(fic, nomSysFicSource);
    associer(nvFic, nvNomSys);
    associer(ficCodes, nomSysFicCodes);
    ouvrir(fic, consultation);
    ouvrir(nvFic, creation);
    ouvrir(ficCodes, consultation);

    // Ecriture du code de traduction dans un tableau 
    nbBinomes = 0;

    // Parcours complet pour chargement du tableau
    while(true)
    {
        // Tentative de lecture
        lireMot(ficCodes,carEnClair,fdfCodes);

        if (fdfCodes)
        {
            break;
        }

        // Tentative de lecture
        lireMot(ficCodes,carCorrespondant,fdfCodes);

        // Charger le binome
        binomes[nbBinomes].carEnClair = carEnClair[0];
        binomes[nbBinomes].carCrypte = carCorrespondant[0];

        // Incrementation du nb de binomes
        nbBinomes++;
    }

    // Fermeture de ficCodes
    fermer(ficCodes);

    // TRAITEMENTS
    while (true) 
    {
        // Tentative de lecture
        lireCar(fic,car,fdf);

        if (fdf)
        {
            break;
        }

        // transformation du caractère
        // Initialisation de la recherche
        posCourante = 0; 
        carCrypte = car;

        // Chercher car dans les binomes
        while (true)
        {
            if(posCourante == nbBinomes)
            {
                break;
            }

            if(binomes[posCourante].carEnClair == car)
            {
                carCrypte = binomes[posCourante].carCrypte;
                break;
            }

            posCourante++;
        }

        // Ecriture dans le fichier crypté
        ecrire(nvFic,carCrypte);
    }
    


    // Fermeture des fichiers
    fermer(fic);
    fermer(nvFic);

    // nomSysFicCble >> retourner nom système du fichier cible
    return nvNomSys;
}

// ---------------------------------------------------------------------
// Corps des sous-programmes utilisés par les sous-programmes de cryptage
string genererNom(string nom)
{
    enum UnCas
    {
        nomIllegal,
        ajouterEnFin,
        insererAvantPoint
    };
    string nouveauNom = "";
    bool trouvePoint = false;
    bool trouveSlash = false;
    unsigned int posPoint; // position du dernier point, s'il en existe dans la chaîne nom
    unsigned int posSlash; // position du dernier slash, s'il en existe dans la chaîne nom
    UnCas cas;

    // nom >> determiner position dernierSlash >> posSlash
    for (unsigned int i = 0; i < nom.length(); i++)
    {
        if (nom[i] == '/')
        {
            trouveSlash = true;
            posSlash = i;
        }
    }
    // nom, trouveSlash, [posSlash] >> Déterminer position du dernier point >> trouvé, posPoint
    if (trouveSlash)
    {
        // on cherche le point de suffixe après les caractères indiquant le chemin relatif
        for (unsigned int i = posSlash + 1; i < nom.length(); i++)
        {
            if (nom[i] == '.')
            {
                trouvePoint = true;
                posPoint = i;
            }
        }
    }
    else
    {
        // on cherche le point de suffixe dès le début du nom de fichier
        for (unsigned int i = 0; i < nom.length(); i++)
        {
            if (nom[i] == '.')
            {
                trouvePoint = true;
                posPoint = i;
            }
        }
    }

    // posPoint, mot >> Analyse de la situation >> cas
    if (trouvePoint && (posPoint == 0) && nom.length() == 1)
    {
        // le nom ne contient qu'un point --> mauvais nom de fichier, on ne fait rien
        cas = nomIllegal;
    }
    else if (trouvePoint && (posPoint == 0) && nom.length() > 1)
    {
        // le nom démarre par un point --> c'est un fichier caché, on ajoute _crypted en fin de nom (après le point)
        cas = ajouterEnFin;
    }
    else if (trouvePoint && (posPoint > 0))
    {
        // mot contient au moins un point.
        // le dernier . est considéré comme . de suffixe si la longueur du suffixe est <= 7
        // sinon, le . est considéré comme faisant partie du nom de fichier
        if (((nom.length() - posPoint - 1) <= 7) && ((nom.length() - posPoint - 1) > 0))
        {
            cas = insererAvantPoint;
        }
        else
        {
            cas = ajouterEnFin;
        }
    }
    else // !trouve
    {
        // pas de point, ajout de la chaîne en fin de nom
        cas = ajouterEnFin;
    }

    // cas, posPoint, nom >> Generer le nouveaunom selon le cas >> nouveauNom
    switch (cas)
    {
    case nomIllegal:
        nouveauNom = nom;
        break;
    case ajouterEnFin:
        nouveauNom = nom + "_crypted";
        break;
    case insererAvantPoint:
        // ajouter la partie avant le point
        for (unsigned int i = 0; i < posPoint; i++)
        {
            nouveauNom = nouveauNom + nom[i];
        }

        // ajouter le tterme "_crypted" et le point
        nouveauNom = nouveauNom + "_crypted.";

        // ajouter la fin
        for (unsigned int i = posPoint + 1; i < nom.length(); i++)
        {
            nouveauNom = nouveauNom + nom[i];
        }
        break;
    }

    return nouveauNom;
}