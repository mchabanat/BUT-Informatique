#include "fichierTexte.h"

void associer ( UnFichierTexte& f,
                string nom)
/* relie le NOM LOGIQUE du fichier (ou "fichier logique") � son NOM SYSTEME
  -- (ou "fichier physique")
  -- : ne peut occasionner aucune erreur
*/
{
    f.nom = nom;
    f.modeOuvertureDefini = false;
}

void ouvrir ( UnFichierTexte& f,
              UnModeOuverture mode)
/*rend le fichier disponible pour les Entr�es/Sorties autoris�es
  -- : peut occasionner erreurDeStatut si le fichier est d�j� ouvert,
  --                    erreurDeNomOuUsage : le fichier n'a pu �tre ouvert,
  --                          * DeNom, si le nom est ill�gal ou le fichier inexistant,
  --                          * DUsage, si les protections du fichiers rendent l'op�ration ill�gale
*/
{
    if (f.modeOuvertureDefini == true)
    {
        //cerr << "erreurDeStatut" << endl;
        throw string("erreurDeStatut");
    }
    else
    {
        switch (mode)
        {
        case consultation :
            f.donnees.open (f.nom.c_str(), ios::in);
            break;
        case creation :
            f.donnees.open (f.nom.c_str(), ios::out | ios::trunc);
            break;
        case extension :
            f.donnees.open (f.nom.c_str(), ios::out |ios::app);
            break;
            //case modification ! NON FAIT
        default :
            break;
        }
    }
    if (f.donnees.is_open() == false)
    {
        cerr << "erreurDeNomOuUsage" << endl ;
        throw string ("erreurDeNomOuUsage");
    }
    else
    {
        f.modeOuverture = mode;
        f.modeOuvertureDefini = true;
    }
}

void fermer (UnFichierTexte& f)
/*rend le mode du fichier ind�fini, et donc le fichier indisponible pour toutes
  -- les Entr�es/Sorties
  -- : peut occasionner erreurDeStatut si le fichier n'est pas ouvert
  -- :                  erreurInconnue si la fermeture n'a pu se faire
*/
{
    if (f.modeOuvertureDefini == false)
    {
        cerr << "erreurDeStatut" << endl ;
        throw string ("erreurDeStatut");
    }
    else
    {
        f.donnees.close();
        if (f.donnees.is_open() == true)
        {
            cerr << "erreurInconnue" << endl ;
            throw string ("erreurInconnue");
        }
        else
        {
            f.modeOuvertureDefini = false;
            //f->.ficheEnCours = false;
        }
    }
}

void lireLigne ( UnFichierTexte& f,
                 string& chaine,
                 bool& finFichier)
/*pour les modes consultation (et Modification NON FAIT), 2 cas de retour
  -- 	S'il y a une ligne suivante (chaine suivie d'un caract�re FIN_DE_LIGNE ou FIN_DE_FICHIER) :
  --		son contenu est affect� au param�tre chaine
  --		le param�tre finFichier est retourn� � Faux
  -- 	S'il n'y a pas de ligne suivante (uniquement le caract�re FIN_DE_FICHIER trouv�):
  --		le param�tre chaine n'est pas modifi�
  --		le param�tre finFichier est retourn� � Vrai
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit la consultation,
  --                    erreurInconnue si la consultation s'est mal d�roul�e (fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==creation) | (f.modeOuverture==extension))
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode consultation : on peut donc y lire
        if (getline(f.donnees, chaine))
        {
            finFichier = false;
        }
        else if (f.donnees.eof())
        {
            finFichier = true;
        }
        else
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

void lireCar ( UnFichierTexte& f,
               char& item,
               bool& finFichier)
/*pour les modes consultation (et modification NON FAIT), 2 cas de retour
  -- 	S'il y a un item suivant :
  --		son contenu est affect� au param�tre item
  --		le param�tre finFichier est retourn� � Faux
  -- 	S'il n'y a pas d'item (fin de fichier  trouv�e):
  --		le param�tre item n'est pas modifi�
  --		le param�tre finFichier est retourn� � Vrai
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit la consultation,
  --                    erreurInconnue si la consultation s'est mal d�roul�e (fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==creation) | (f.modeOuverture==extension))
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode consultation : on peut donc y lire
        if (f.donnees.get(item))
        {
            finFichier = false;
        }
        else if (f.donnees.eof())
        {
            finFichier = true;
        }
        else
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

void lireMot ( UnFichierTexte& f,
               string& item,
               bool& finFichier)
/*pour les modes consultation (et Modification NON FAIT), 2 cas de retour
  -- 	S'il y a un item suivant (item suivi d'un caract�re s�parateur) :
  --		son contenu est affect� au param�tre item
  --		le param�tre finFichier est retourn� � Faux
  -- 	S'il n'y a pas d'item (fin de fichier  trouv�e):
  --		le param�tre item n'est pas modifi�
  --		le param�tre finFichier est retourn� � Vrai
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit la consultation,
  --                    erreurInconnue si la consultation s'est mal d�roul�e (fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==creation) | (f.modeOuverture==extension))
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode consultation : on peut donc y lire
        if (f.donnees >> item)
        {
            finFichier = false;
        }
        else if (f.donnees.eof())
        {
            finFichier = true;
        }
        else
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

void lireMot ( UnFichierTexte& f,
               int& item,
               bool& finFichier)
/*pour les modes consultation (et modification NON FAIT), 2 cas de retour
  -- 	S'il y a un item suivant (item suivi d'un caract�re s�parateur) :
  --		son contenu est affect� au param�tre item
  --		le param�tre finFichier est retourn� � Faux
  -- 	S'il n'y a pas d'item (fin de fichier  trouv�):
  --		le param�tre item n'est pas modifi�
  --		le param�tre finFichier est retourn� � Vrai
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit la consultation,
  --                    erreurInconnue si la consultation s'est mal d�roul�e (fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==creation) | (f.modeOuverture==extension))
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode consultation : on peut donc y lire
        if (f.donnees >> item)
        {
            finFichier = false;
        }
        else if (f.donnees.eof())
        {
            finFichier = true;
        }
        else
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

void lireMot ( UnFichierTexte& f,
               float& item,
               bool& finFichier)
/*pour les modes consultation (et modification NON FAIT), 2 cas de retour
  -- 	S'il y a un item suivant (item suivi d'un caract�re s�parateur) :
  --		son contenu est affect� au param�tre item
  --		le param�tre finFichier est retourn� � Faux
  -- 	S'il n'y a pas d'item (fin de fichier  trouv�):
  --		le param�tre item n'est pas modifi�
  --		le param�tre finFichier est retourn� � Vrai
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit la consultation,
  --                    erreurInconnue si la consultation s'est mal d�roul�e (fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==creation) | (f.modeOuverture==extension))
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode consultation : on peut donc y lire
        if (f.donnees >> item)
        {
            finFichier = false;
        }
        else if (f.donnees.eof())
        {
            finFichier = true;
        }
        else
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

void lireMot ( UnFichierTexte& f,
               bool& item,
               bool& finFichier)
/*pour les modes consultation (et modification NON FAIT), 2 cas de retour
  -- 	S'il y a un item suivant (item suivi d'un caract�re s�parateur) :
  --		son contenu est affect� au param�tre item
  --		le param�tre finFichier est retourn� � Faux
  -- 	S'il n'y a pas d'item (fin de fichier  trouv�):
  --		le param�tre item n'est pas modifi�
  --		le param�tre finFichier est retourn� � Vrai
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit la consultation,
  --                    erreurInconnue si la consultation s'est mal d�roul�e (fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==creation) | (f.modeOuverture==extension))
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode consultation : on peut donc y lire
        if (f.donnees >> item)
        {
            finFichier = false;
        }
        else if (f.donnees.eof())
        {
            finFichier = true;
        }
        else
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

void ecrireLigne ( UnFichierTexte& f,
                   string item)
/*pour les modes creation et extension, le contenu du param�tre item
  -- est enregistr� en fin de fichier, suivi d'un caract�re FIN_DE_LIGNE
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'�criture,
  --                    erreurInconnue si l'�criture s'est mal d�roul�e (plus d'espace disque, fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==consultation))  // | (f.modeOuverture==modification)  NON FAIT
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode creation ou extension : on peut donc y �crire la chaine item, en fin de fichier,
        // suivi d'un caract�re FIN_DE_LIGNE ('\n')
        f.donnees  << item << "\n" ;
        if (f.donnees.bad())
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

void ecrire ( UnFichierTexte& f,
              string item)
/*pour les modes creation et extension, le contenu du param�tre item
  -- est enregistr� en fin de fichier
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'�criture,
  --                    erreurInconnue si l'�criture s'est mal d�roul�e (plus d'espace disque, fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==consultation))  // | (f.modeOuverture==modification)  NON FAIT
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode creation ou extension : on peut donc y �crire l'item, en fin de fichier
        f.donnees << item ;
        if (f.donnees.bad())
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}



void ecrire ( UnFichierTexte& f,
              char* item)
/*pour les modes creation et extension, le contenu du param�tre item
  -- est enregistr� en fin de fichier
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'�criture,
  --                    erreurInconnue si l'�criture s'est mal d�roul�e (plus d'espace disque, fichier corrompu...)

    ATTENTION
  Cette version surcharg�e de la proc�dure est n�cessaire pour pouvoir prendre en charge l'appel :
  ecrire(monFichier, "bonjour");
    car, par d�faut, les constantes litt�rales cha�nes sont consid�r�es comme des bool.
         car C++ consid�re la constante string litt�rale comme un char* ...  puis comme bool (cf. document stackOverflow ci-joint)

  Si on ne met pas � disposition cette proc�dure, il faudrait forcer le typage de la constante litt�rale string au moment
  de l'appel de la proc�dure ecrire(  UnFichierTexte& f, string item) de la mani�re suivante :
  ecrire (monFichier, (string) "bonjour");

  Ce probl�me ne se pose pas lorsque la chaine se trouve dans une variable string pr�alablement d�clar�e.
  string maChaine = "bonjour";
  ecrire (monFichier, maChaine);  ... fait appel � la bonne proc�dure surcharg�e ayant le param�tre string item.
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==consultation))  // | (f.modeOuverture==modification)  NON FAIT
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode creation ou extension : on peut donc y �crire l'item, en fin de fichier
        f.donnees << item ;
        if (f.donnees.bad())
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

void ecrire ( UnFichierTexte& f,
              char item)
/*pour les modes creation et extension, le contenu du param�tre item
  -- est enregistr� en fin de fichier
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'�criture,
  --                    erreurInconnue si l'�criture s'est mal d�roul�e (plus d'espace disque, fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==consultation))  // | (f.modeOuverture==modification)  non encore fait
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode creation ou extension : on peut donc y �crire l'item, en fin de fichier
        f.donnees << item ;
        if (f.donnees.bad())
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

void ecrire ( UnFichierTexte& f,
              int item)
/*pour les modes creation et extension, le contenu du param�tre item
  -- est enregistr� en fin de fichier
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'�criture,
  --                    erreurInconnue si l'�criture s'est mal d�roul�e (plus d'espace disque, fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==consultation))  // | (f.modeOuverture==modification)  NON FAIT
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode creation ou extension : on peut donc y �crire l'item, en fin de fichier
        f.donnees << item ;
        if (f.donnees.bad())
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

void ecrire ( UnFichierTexte& f,
              float item)
/*pour les modes creation et extension, le contenu du param�tre item
  -- est enregistr� en fin de fichier
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'�criture,
  --                    erreurInconnue si l'�criture s'est mal d�roul�e (plus d'espace disque, fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==consultation))  // | (f.modeOuverture==modification)  NON FAIT
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode creation ou extension : on peut donc y �crire l'item, en fin de fichier
        f.donnees << item;
        if (f.donnees.bad())
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}

void ecrire ( UnFichierTexte& f,
              bool item)
/*pour les modes creation et extension, le contenu du param�tre item
  -- est enregistr� en fin de fichier
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'�criture,
  --                    erreurInconnue si l'�criture s'est mal d�roul�e (plus d'espace disque, fichier corrompu...)
*/
{
    if ((f.modeOuvertureDefini==false) | (f.modeOuverture==consultation))  // | (f.modeOuverture==modification)  NON FAIT
    {
        cerr << "erreurDeMode" << endl;
        throw string("erreurDeMode");
    }
    else
    {
        // le fichier est ouvert en mode creation ou extension : on peut donc y �crire l'item, en fin de fichier
        f.donnees << item;
        if (f.donnees.bad())
        {
            cerr << "erreurInconnue" << endl;
            throw string("erreurInconnue");
        }
    }
}


bool estOuvert (UnFichierTexte& f)
/*retourne VRAI si le fichier est ouvert, FAUX sinon */
{
    return (f.modeOuvertureDefini == true);
}

string nomSysteme (UnFichierTexte& f)
/* retourne le nom du fichier sur le disque */
{
    return f.nom;
}

void renommer (UnFichierTexte& f, string nouveauNom)
/* Valeur retourn�e par rename :
   . 0 si l'op�ration se d�roule correctement,
   . valeur diff�rente de 0 dans le cas contraire
  -- : peut occasionner ereurInconnue si l'op�ration �choue
*/
{
    if (rename (f.nom.c_str(), nouveauNom.c_str()) == 0)
    {
        f.nom = nouveauNom;
    }
    else
    {
        cerr << "erreurInconnue" << endl;
        throw string("erreurInconnue");
    }
}

void supprimer (UnFichierTexte& f)
/* Valeur retourn�e par remove :
   . 0 si l'op�ration se d�roule correctement,
   . valeur diff�rente de 0 dans le cas contraire
  -- : peut occasionner ereurInconnue si l'op�ration �choue
*/
{
    if (remove (f.nom.c_str()) != 0)
    {
        cerr << "erreurInconnue" << endl;
        throw string("erreurInconnue");
    }
}


/**Exceptions
  erreurDeStatut, erreurDeMode, erreurDeNomOuUsage, erreurInconnue;
  erreurDUsage (pour primitive r��crire non impl�ment�e)
**/


