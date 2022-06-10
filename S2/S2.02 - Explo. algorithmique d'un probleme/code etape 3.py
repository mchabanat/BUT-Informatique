# -*- coding: utf-8 -*-

import json
from math import sin, cos, acos, pi, sqrt
from graphics import *

#Import du fichier .json
donneesbus = open("donneesbus.json")

#Transformation du fichier json en dictionnaire
donneesbus = json.load(donneesbus)

#Création de la liste de toutes les clé du dictionnaire
noms_arrets = list(donneesbus.keys())

#Renvoie le nom de l'arrêt dans noms_arrets à l'indice donné par l'user
def nom(ind):
    return noms_arrets[ind]

#Renvoie l'indice dans la liste noms_arrets correspondant au nom donné par l'user
def indic_som(nom_som):
    for i in range(len(noms_arrets)):
        if noms_arrets[i] == nom_som:
            return i

#Renvoie la latitude de nom_som
def latitude(nom_som):
    return donneesbus[nom_som][0]

#Renvoie la longitude de nom_som
def longitude(nom_som):
    return donneesbus[nom_som][1]

#renvoie la liste des voisins de nom_som
def voisin(nom_som):
    return donneesbus[nom_som][2]

#Renvoie la matrice d'adjacence du dictionnaire
def mat_bus(dico):
    mat_bus = []
    nomKey = list(dico.keys())
    for i in range(len(nomKey)):
        ligne = []
        for y in range(len(nomKey)):
            if nomKey[y] in voisin(nomKey[i]):
                ligne.append(1)
            else:
                ligne.append(0)
        mat_bus.append(ligne)
    return mat_bus

#Renvoie le graphe du dictionnaire en paramètre sous forme de dictionnaire 
def dic_bus(dico):
    dic_bus = {}
    nomKey = list(dico.keys())
    for i in range(len(nomKey)):
        dic_bus[nomKey[i]] = voisin(nomKey[i])
    return dic_bus

#Renvoie la distance en mètre à vol d'oiseau de deux coordonnées gps
def distanceGPS(latA,latB,longA,longB):
    # Conversions des latitudes en radians
    ltA=latA/180*pi
    ltB=latB/180*pi
    loA=longA/180*pi
    loB=longB/180*pi
    # Rayon de la terre en mètres (sphère IAG-GRS80)
    RT = 6378137 
    # angle en radians entre les 2 points 
    S = acos(round(sin(ltA)*sin(ltB) + cos(ltA)*cos(ltB)*cos(abs(loB-loA)),14))
    # distance entre les 2 points, comptée sur un arc de grand cercle
    return S*RT

#Renvoie la distance à vol d'oiseau entre deux sommets voisins ou pas
def distarrets(arret1, arret2):
    lat1 = latitude(arret1)
    lat2 = latitude(arret2)
    long1 = longitude(arret1)
    long2 = longitude(arret2)
    return distanceGPS(lat1, lat2, long1, long2)

#Renvoie le poids de l'arc entre deux sommets
def distArc(arret1, arret2):
    if arret1 in voisin(arret2):
        return distarrets(arret1, arret2)
    else:
        return float('inf')

#Renvoie le graphe pondéré du dictionnaire en paramètre sous forme de matrice
def poids_bus(dico):
    matPoids = []
    nomKey = list(dico.keys())
    for i in range(len(nomKey)):
        ligne = []
        for y in range(len(nomKey)):
            ligne.append(distArc(nomKey[i], nomKey[y]))
        matPoids.append(ligne)
    return matPoids


#Parcours
def minTableau(table):
    mini = table[0]
    indiceMin = 0
    for i in range(len(table)):
        if table[i] < mini:
            mini = table[i]
            indiceMin = i
    return (mini, indiceMin)
        
def inverseTab(tab):
    newTab = []
    i = len(tab)-1
    while i >= 0:
        newTab.append(tab[i])
        i -= 1
    return tab

#Djikstra
def djikstra(depart, arrive):
    #Déclaration des tableaux
    G = poids_bus(donneesbus)
    sommetATraite = []
    dist = []
    pred = []
    tab = []
    sommetTraite = indic_som(depart)
    
    #Initialisation tab des tableaux
    for i in range(len(G)):
        pred.append(float("inf"))
        dist.append(float("inf"))
        tab.append(float("inf"))
        sommetATraite.append(i)
    
    #On traite le sommet de départ
    sommetATraite.remove(sommetTraite)
    pred[sommetTraite] = sommetTraite #Comme c'est l'arrêt de départ son prédecesseur est lui même
    dist[sommetTraite] = 0
    
    #Début de la boucle
    while sommetATraite != []:
        #Réinitialisation des variable 
        for i in range(len(G)):
            if i in sommetATraite:
                tab[i] = G[sommetTraite][i]
            else:
                tab[i] = float('inf')
        
        #Relachement
        for i in range(len(tab)):
            if tab[i] != float('inf'):
                if dist[i] > (dist[sommetTraite]+tab[i]):
                    pred[i] = sommetTraite
                    dist[i] = dist[sommetTraite]+tab[i]
        
        #Reinitialisation
        for i in range(len(G)):
            if i in sommetATraite:
                tab[i] = dist[i]
            else:
                tab[i] = float('inf')
        
        #On établit le prochain arrêt à traiter
        sommetTraite = minTableau(tab)[1]
        sommetATraite.remove(sommetTraite)
        
        #On verifie qu'on ne soit pas arrivé au sommet
        if sommetTraite == indic_som(arrive):
            break
        
    #On remonte les chemin 
    result = []
    sommet = indic_som(arrive)
    while sommet != indic_som(depart):
        result.append(nom(sommet))
        sommet = pred[sommet]
    result.append(depart)
    return inverseTab(result)

#Bellman
def belmann(arret_dep,arret_arriv):
    #init des dist et pred
    dicoDistPred = {som: [float('inf'), None] for som in noms_arrets}
    #On init le poids de l'arret de départ a 0
    dicoDistPred[arret_dep][0]=0
    
    #fonction pour relacher un arc
    def relachement(depart,arrivee):
        if dicoDistPred[depart][0] + distArc(depart, arrivee) < dicoDistPred[arrivee][0]:
            dicoDistPred[arrivee][0] = dicoDistPred[depart][0] + distArc(depart, arrivee)
            dicoDistPred[arrivee][1] = depart
            #s'il y a un amelioration, on retourne true pour dire qu'un relachement a été fait
            #et que l'on doit etudier les autres arrets
            return True
        else:
            return False

    
    #début boucle : on considère qu'aucun changement a été réalisé
    change=False
    #etude de tous les arrets
    for i in range(0, len(noms_arrets) - 1):
        for arret1 in noms_arrets:
            #2e boucle pour etudier les voisins de l'arret1
            for arret2 in voisin(arret1):
                #on relache le sommet
                if change and not relachement(arret1, arret2):
                    break
                change = relachement(arret1, arret2)
                
    #Après avoir tout relaché, on retrouve le chemin à réaliser pour faire arret1->arret2 
    lastArret = dicoDistPred[arret_arriv][1]
    cheminArrets = [lastArret]
    while lastArret != arret_dep:
        lastArret=dicoDistPred[lastArret][1]
        cheminArrets = [lastArret]+cheminArrets
    
    #On place a la fin du chemin le nom de l'arret d'arrivée
    cheminArrets.append(arret_arriv)
    
    #la fonction renvoie le chemin et la distance a parcourir (round permet d'arrondir la distance)
    return cheminArrets,round(dicoDistPred[arret_arriv][0])

#_______________________________________________________________________________________________________
#Graphique
#parcours complet -> récuperer les longitudes et latitudes max et min
# init des long/lat à ceux du premier sommet


#Met tout les points à l'échelle de l'écran
def miseEchelle(lat, long, plageEcran):
    longMin=longitude("7PUI")
    longMax=longMin
    latMin=latitude("7PUI")
    latMax=latMin
    for i in range (1,len(donneesbus)-1):
        nomSom=nom(i)
        if longitude(nomSom) > longMax:
            longMax = longitude(nomSom)
        if longitude(nomSom) < longMin:
            longMin = longitude(nomSom)
        if latitude(nomSom) > latMax:
            latMax = latitude(nomSom)
        if latitude(nomSom) < latMin:
            latMin = latitude(nomSom)
    plageLat = latMax - latMin
    plageLong = longMax - longMin
    coordX = ((plageEcran * ((long-longMin)))/plageLong)+25
    coordY = (plageEcran-(plageEcran * ((lat-latMin)))/plageLat)+25
    coord = (coordX, coordY)
    return coord

#Trace un trait entre les deux couples de coordonnées
def tracerTrait(win, couple1, couple2, couleur=color_rgb(0,0,0)):
    chemin = Line(Point(couple1[0], couple1[1]), Point(couple2[0], couple2[1]))
    chemin.setFill(couleur)
    chemin.draw(win)
    return chemin

#Trace tout les voisin d'un points
def tracerVoisin(win, tabCoord, nom, couleur=color_rgb(0,0,0)):
    tabTrait = []
    voisins = voisin(nom)
    sommetActuel = tabCoord[indic_som(nom)]
    for i in range(len(voisins)):
        sommetVoisin = tabCoord[indic_som(voisins[i])]
        trait = tracerTrait(win, sommetActuel, sommetVoisin, couleur)
        tabTrait.append(trait)
    return tabTrait
    
#Return un tableau avec pour chaque point un tuple de coordonnée
def definirTabCoord(tab, plageEcran):
    tabCoord = []
    for i in range(len(tab)):
        coord = miseEchelle(latitude(nom(i)), longitude(nom(i)), plageEcran)
        tabCoord.append(coord)
    
    return tabCoord

# Fonction qui dessine un point
def point(window,posX,posY, coul = color_rgb(255,255,255)):
    window.plot(posX, posY)
    c = Circle(Point(posX,posY), 4)
    c.setFill(coul)
    c.draw(window)
    return c

#Return True si coordX et coordY sont à l'interieurs du cercle
def touche(coordX, coordY, coord2X, coord2Y, rayon):
    distance = sqrt(((coord2X - coordX)**2)+((coord2Y - coordY)**2))
    if distance <= rayon:
        return True
    else:
        return False
  
#Affiche le graphe
def miseEnPlaceGraphe(win, plageEcran):
    tabCoord = definirTabCoord(donneesbus, plageEcran)
    tabPoints = []
    for i in range(len(noms_arrets)):
        coord = miseEchelle(latitude(nom(i)), longitude(nom(i)), plageEcran)
        pActuel = point(win, coord[0], coord[1])
        tabPoints.append(pActuel)
        
    for i in range(len(tabCoord)):
        tabTrait = tracerVoisin(win, tabCoord, nom(i), color_rgb(255, 255, 255))
    return (tabPoints, tabTrait)

#Efface le graphe
def effacerGraphe(tabPoints, tabTrait):
    for i in range(len(tabPoints)):
        tabPoints[i].undraw()
    for i in range(len(tabTrait)):
        tabTrait[i].undraw()
        
#Permet à l'utilisateur de selectionner les sommets auquels sont appliqué les algorithme avec la souris
def cliqueSommet(win, tabCoord):
    nomSommet1 = ""
    nomSommet2 = ""
    #Texte Départ
    textDepart = Text(Point(100,200), "Départ : ")
    textDepart.setSize(18)
    textDepart.setFill(color_rgb(0, 200, 255))
    textDepart.draw(win)
    #Texte Arrivée
    textArrivee = Text(Point(100,250), "Arrivée : ")
    textArrivee.setSize(18)
    textArrivee.setFill(color_rgb(179, 0, 255))
    textArrivee.draw(win)
    
    #Bouton Valider
    boutonValider = Rectangle(Point(50,300), Point(150,330))
    boutonValider.setFill(color_rgb(255, 255, 255))
    textBoutonValider = Text(Point(100, 315), "Valider")
    textBoutonValider.setFill(color_rgb(0, 0, 0))
    textBoutonValider.setSize(11)
    dessiner = False
    
    while True:
        clique = win.getMouse() #On récupe les cliques souris
        coord = (clique.getX(), clique.getY())
        saisie = False

        #Annulation Clique
        if nomSommet1 != "" and saisie == False:
            if touche(coord[0], coord[1], tabCoord[indic_som(nomSommet1)][0], tabCoord[indic_som(nomSommet1)][1], 4):
                textDepart.undraw()
                textDepart.setText("Départ : ")
                textDepart.draw(win)
                point(win, tabCoord[indic_som(nomSommet1)][0], tabCoord[indic_som(nomSommet1)][1], color_rgb(255, 255, 255))
                nomSommet1 = ""
                saisie = True
                boutonValider.undraw()
                textBoutonValider.undraw()
                dessiner = False
        if nomSommet2 != "" and saisie == False:
            if touche(coord[0], coord[1], tabCoord[indic_som(nomSommet2)][0], tabCoord[indic_som(nomSommet2)][1], 4):
                textArrivee.undraw()
                textArrivee.setText("Arrivée : ")
                textArrivee.draw(win)
                point(win, tabCoord[indic_som(nomSommet2)][0], tabCoord[indic_som(nomSommet2)][1], color_rgb(255, 255, 255))
                nomSommet2 = ""
                saisie = True
                boutonValider.undraw()
                textBoutonValider.undraw()
                dessiner = False
        #Clique
        if nomSommet1 == "" and saisie == False:
            for i in range(len(tabCoord)):
                if touche(coord[0], coord[1], tabCoord[i][0], tabCoord[i][1], 4):
                    point(win, tabCoord[i][0], tabCoord[i][1], color_rgb(0, 200, 255))
                    nomSommet1 = nom(i)
                    textDepart.undraw()
                    textDepart.setText(textDepart.getText() + nomSommet1)
                    textDepart.draw(win)
                    saisie = True
        elif nomSommet2 =="" and saisie == False:
            for i in range(len(tabCoord)):
                if touche(coord[0], coord[1], tabCoord[i][0], tabCoord[i][1], 4):
                    point(win, tabCoord[i][0], tabCoord[i][1], color_rgb(179, 0, 255))
                    nomSommet2 = nom(i)
                    textArrivee.undraw()
                    textArrivee.setText(textArrivee.getText() + nomSommet2)
                    textArrivee.draw(win)
                    saisie = True
                    break
        #Cas d'arrêt / validation
        if nomSommet2 != "" and nomSommet1 !="": 
            if(dessiner == False):
                boutonValider.draw(win)
                textBoutonValider.draw(win)
                dessiner = True
            else:
                if 50 < clique.getX() < 150 and 300 < clique.getY() < 330:
                    break
    return (nomSommet1, nomSommet2, textDepart, textArrivee)

#Affiche un chargement à l'écran 
def afficherChargement(win):
    textChargement = Text(Point(100, 225), "Chargement...")
    textChargement.setFill(color_rgb(255, 255, 255))
    textChargement.setSize(20)
    textChargement.draw(win)
    return textChargement

#Ajoute à l'interface deux boutons fonctionnels quitter et clear
def buttonClearQuitter(win):
    #Bouton Clear
    boutonClear = Rectangle(Point(200,250), Point(260,280))
    boutonClear.setFill(color_rgb(255, 255, 255))
    textBoutonClear = Text(Point(230, 265), "Clear")
    textBoutonClear.setFill(color_rgb(0, 0, 0))
    textBoutonClear.setSize(11)
    boutonClear.draw(win)
    textBoutonClear.draw(win)
    
    #Bouton Quitter
    boutonQuit = Rectangle(Point(200,300), Point(260,330))
    boutonQuit.setFill(color_rgb(255, 255, 255))
    textBoutonQuit = Text(Point(230, 315), "Quitter")
    textBoutonQuit.setFill(color_rgb(0, 0, 0))
    textBoutonQuit.setSize(11)
    boutonQuit.draw(win)
    textBoutonQuit.draw(win)
    
    #On attends le clique
    while True:
        clique = win.getMouse()
        if 200 < clique.getX() < 260 and 300 < clique.getY() < 330:
            boutonClear.undraw()
            textBoutonClear.undraw()
            boutonQuit.undraw()
            textBoutonQuit.undraw()
            return True
            break
        elif 200 < clique.getX() < 260 and 250 < clique.getY() < 280:
            boutonClear.undraw()
            textBoutonClear.undraw()
            boutonQuit.undraw()
            textBoutonQuit.undraw()
            return False
            break


#Les algo en version Graphique
#Djikstra adapté pour le graphique
def djikstraGraphique(win, depart, arrive, winSize):
    #Déclaration des tableaux
    G = poids_bus(donneesbus)
    sommetATraite = []
    dist = []
    pred = []
    tab = []
    sommetTraite = indic_som(depart)
    tabCoord = definirTabCoord(noms_arrets, winSize -50)
    
    #Initialisation tab des tableaux
    for i in range(len(G)):
        pred.append(float("inf"))
        dist.append(float("inf"))
        tab.append(float("inf"))
        sommetATraite.append(i)
    
    #On traite le sommet de départ
    sommetATraite.remove(sommetTraite)
    pred[sommetTraite] = sommetTraite #Comme c'est l'arrêt de départ son prédecesseur est lui même
    dist[sommetTraite] = 0
    point(win, tabCoord[sommetTraite][0], tabCoord[sommetTraite][1], color_rgb(0,0,255))
    
    #Début de la boucle
    while sommetATraite != []:
        #Réinitialisation des variable 
        for i in range(len(G)):
            if i in sommetATraite:
                tab[i] = G[sommetTraite][i]
            else:
                tab[i] = float('inf')
        
        #Relachement
        for i in range(len(tab)):
            if tab[i] != float('inf'):
                if dist[i] > (dist[sommetTraite]+tab[i]):
                    point(win, tabCoord[i][0], tabCoord[i][1], color_rgb(255,0,0))
                    pred[i] = sommetTraite
                    dist[i] = dist[sommetTraite]+tab[i]
        
        #Reinitialisation
        for i in range(len(G)):
            if i in sommetATraite:
                tab[i] = dist[i]
            else:
                tab[i] = float('inf')
        
        #On établit le prochain arrêt à traiter
        sommetTraite = minTableau(tab)[1]
        sommetATraite.remove(sommetTraite)
        point(win, tabCoord[sommetTraite][0], tabCoord[sommetTraite][1], color_rgb(0,0,255))
        
        #On verifie qu'on ne soit pas arrivé au sommet
        if sommetTraite == indic_som(arrive):
            break
        
    #On remonte les chemin 
    result = []
    sommet = indic_som(arrive)
    while sommet != indic_som(depart):
        result.append(nom(sommet))
        point(win, tabCoord[sommet][0], tabCoord[sommet][1], color_rgb(0,255,0))
        sommet = pred[sommet]
    point(win, tabCoord[indic_som(depart)][0], tabCoord[indic_som(depart)][1], color_rgb(255,255,0))
    point(win, tabCoord[indic_som(arrive)][0], tabCoord[indic_som(arrive)][1], color_rgb(255,255,0))
    result.append(depart)
    return inverseTab(result)

#Floyd Warshall adapté pour le graphique
def floydWarshallGraphique(win, depart, arrivee, winSize):
    #Initialisation
    tabCoord = definirTabCoord(noms_arrets, winSize -50)
    indiceDepart = indic_som(depart)
    indiceArrivee = indic_som(arrivee)
    matrice = poids_bus(donneesbus)
    n = len(matrice)
    #On remplit les tableaux distance et pred
    distances, pred = [[0 for _ in range(n)] for _ in range(n)], [[0 for _ in range(n)] for _ in range(n)]
    chemin = []
    
    #On place les poids et les predécesseurs déjà existant
    for i in range(n):
        for j in range(n):
            distances[i][j] = matrice[i][j]
            pred[i][j] = j
    #boucles de Floyd Warshall
    #traits = []
    for k in range(n):
        #for i in range(len(traits)):
            #traits[i].undraw()
        point(win, tabCoord[k][0], tabCoord[k][1], color_rgb(0, 0, 255))
        for i in range(n):
            for j in range(n):
                if distances[i][j] > distances[i][k] + distances[k][j]:
                    distances[i][j] = distances[i][k] + distances[k][j]
                    pred[i][j] = pred[i][k]
                    #chemin = tracerTrait(win, tabCoord[i], tabCoord[k], color_rgb(255, 0, 0))
                    #traits.append(chemin)
                    
                    
    #Recherche du chemin depart --> arrivée
    chemin.append(depart)
    position = indiceDepart 
    while position != indiceArrivee:
        position = pred[position][indiceArrivee]
        point(win, tabCoord[position][0], tabCoord[position][1], color_rgb(0,255,0))
        chemin.append(nom(position))
    point(win, tabCoord[indic_som(depart)][0], tabCoord[indic_som(depart)][1], color_rgb(255,255,0))
    point(win, tabCoord[indic_som(arrivee)][0], tabCoord[indic_som(arrivee)][1], color_rgb(255,255,0))
    return chemin

#Bellman adapté pour le graphique
def belmannGraphique(win, arret_dep,arret_arriv, winSize):
    tabCoord = definirTabCoord(noms_arrets, winSize -50)
    #init des dist et pred
    dicoDistPred = {som: [float('inf'), None] for som in noms_arrets}
    #On init le poids de l'arret de départ a 0
    dicoDistPred[arret_dep][0]=0
    
    #fonction pour relacher un arc
    def relachement(depart,arrivee):
        if dicoDistPred[depart][0] + distArc(depart, arrivee) < dicoDistPred[arrivee][0]:
            dicoDistPred[arrivee][0] = dicoDistPred[depart][0] + distArc(depart, arrivee)
            dicoDistPred[arrivee][1] = depart
            #s'il y a un amelioration, on retourne true pour dire qu'un relachement a été fait
            #et que l'on doit etudier les autres arrets
            return True
        else:
            return False
    #début boucle : on considère qu'aucun changement a été réalisé
    change=False
    #etude de tous les arrets
    for i in range(0, len(noms_arrets)):
        point(win, tabCoord[i][0], tabCoord[i][1], color_rgb(0, 0, 255))
        for arret1 in noms_arrets:
            #2e boucle pour etudier les voisins de l'arret1
            #tracerTrait(win,tabCoord[indic_som(arret1)] , tabCoord[i], color_rgb(255, 0, 0))
            for arret2 in voisin(arret1):
                #on relache le sommet
                if change and not relachement(arret1, arret2):
                    break
                change = relachement(arret1, arret2)
                
    #Après avoir tout relaché, on retrouve le chemin à réaliser pour faire arret1->arret2 
    lastArret = dicoDistPred[arret_arriv][1]
    cheminArrets = [lastArret]
    while lastArret != arret_dep:
        lastArret=dicoDistPred[lastArret][1]
        cheminArrets = [lastArret]+cheminArrets
    
    #On place a la fin du chemin le nom de l'arret d'arrivée
    cheminArrets.append(arret_arriv)
    
    #On place les points du chemin final
    for i in range(len(cheminArrets)):
        point(win, tabCoord[indic_som(cheminArrets[i])][0], tabCoord[indic_som(cheminArrets[i])][1], color_rgb(0, 255, 0))
    point(win, tabCoord[indic_som(arret_dep)][0], tabCoord[indic_som(arret_dep)][1], color_rgb(255, 255, 0))
    point(win, tabCoord[indic_som(arret_arriv)][0], tabCoord[indic_som(arret_arriv)][1], color_rgb(255, 255, 0))
    
    
    #la fonction renvoie le chemin et la distance a parcourir (round permet d'arrondir la distance)
    return cheminArrets,round(dicoDistPred[arret_arriv][0])


#Main App

#Procédure d'execution de FloydWarshall
def execFloydWarshall(winSize):
    enChargement = False
    tabCoord = definirTabCoord(donneesbus, winSize - 50)
    win = GraphWin("Demo Floyd", winSize, winSize)
    win.setBackground(color_rgb(48, 48, 48))
    while True :
        graphe = miseEnPlaceGraphe(win, winSize - 50)
        if enChargement == True:
            chargement.undraw()
        sommets = cliqueSommet(win, tabCoord)
        floydWarshallGraphique(win, sommets[0], sommets[1], winSize)
        reponseUser = buttonClearQuitter(win)
        if reponseUser == True:
            break
        else:
            chargement = afficherChargement(win)
            enChargement = True
            sommets[2].undraw()
            sommets[3].undraw()
            effacerGraphe(graphe[0], graphe[1])
    win.close()

#Procédure d'execution de Dijkstra
def execDjikstra(winSize):
    enChargement = False
    tabCoord = definirTabCoord(donneesbus, winSize-50)
    win = GraphWin("Demo Djikstra", winSize, winSize)
    win.setBackground(color_rgb(48, 48, 48))
    while True :
        graphe = miseEnPlaceGraphe(win, winSize-50)
        if enChargement == True:
            chargement.undraw()
        sommets = cliqueSommet(win, tabCoord)
        djikstraGraphique(win, sommets[0], sommets[1], winSize)
        reponseUser = buttonClearQuitter(win)
        if reponseUser == True:
            break
        else:
            chargement = afficherChargement(win)
            enChargement = True
            sommets[2].undraw()
            sommets[3].undraw()
            effacerGraphe(graphe[0], graphe[1])
    win.close()

#Procédure d'execution de Belmann
def execBellman(winSize):
    enChargement = False
    tabCoord = definirTabCoord(donneesbus, winSize-50)
    win = GraphWin("Demo Belmann", winSize, winSize)
    win.setBackground(color_rgb(48, 48, 48))
    while True :
        graphe = miseEnPlaceGraphe(win, winSize-50)
        if enChargement == True:
            chargement.undraw()
        sommets = cliqueSommet(win, tabCoord)
        belmannGraphique(win, sommets[0], sommets[1], winSize)
        reponseUser = buttonClearQuitter(win)
        if reponseUser == True:
            break
        else:
            chargement = afficherChargement(win)
            enChargement = True
            sommets[2].undraw()
            sommets[3].undraw()
            effacerGraphe(graphe[0], graphe[1])
    win.close()

#Menu
def AfficherMenu(winSize):
    winMenu = GraphWin("S2.02", 900, 700)
    winMenu.setBackground(color_rgb(48, 48, 48))
    #Titre
    titre = Text(Point(450,50), "Menu S2.02")
    titre.setSize(36)
    titre.setFill(color_rgb(255, 255, 255))
    titre.draw(winMenu)
    #Bouton
    #Djikstra
    boutonDjikstra = Rectangle(Point(300,200), Point(600,250))
    boutonDjikstra.setFill(color_rgb(255, 255, 255))
    textDjikstra = Text(Point(450,225), "Djikstra")
    textDjikstra.setSize(18)
    textDjikstra.setFill(color_rgb(0, 0, 0))
    boutonDjikstra.draw(winMenu)
    textDjikstra.draw(winMenu)
    #Floyd Warshall
    boutonFloyd = Rectangle(Point(300,300), Point(600,350))
    boutonFloyd.setFill(color_rgb(255, 255, 255))
    textFloyd = Text(Point(450,325), "Floyd Warshall")
    textFloyd.setSize(18)
    textFloyd.setFill(color_rgb(0, 0, 0))
    boutonFloyd.draw(winMenu)
    textFloyd.draw(winMenu)
    #Bellman
    boutonBelmann = Rectangle(Point(300,400), Point(600,450))
    boutonBelmann.setFill(color_rgb(255, 255, 255))
    textBelmann = Text(Point(450,425), "Bellman")
    textBelmann.setSize(18)
    textBelmann.setFill(color_rgb(0, 0, 0))
    boutonBelmann.draw(winMenu)
    textBelmann.draw(winMenu)
    #Quitter
    boutonQuitter= Rectangle(Point(300,500), Point(600,550))
    boutonQuitter.setFill(color_rgb(255, 255, 255))
    textQuitter = Text(Point(450,525), "Quitter")
    textQuitter.setSize(18)
    textQuitter.setFill(color_rgb(0, 0, 0))
    boutonQuitter.draw(winMenu)
    textQuitter.draw(winMenu)
    
    while True:
        pointCLique = winMenu.getMouse() # Attendre un clique souris
        if 300 < pointCLique.getX() < 600 and 200 < pointCLique.getY() < 250:
            execDjikstra(winSize)
        elif 300 < pointCLique.getX() < 600 and 300 < pointCLique.getY() < 350:
            execFloydWarshall(winSize)
        elif 300 < pointCLique.getX() < 600 and 400 < pointCLique.getY() < 450:
            execBellman(winSize)
        elif 300 < pointCLique.getX() < 600 and 500 < pointCLique.getY() < 550:
            break
    winMenu.close()
AfficherMenu(900)