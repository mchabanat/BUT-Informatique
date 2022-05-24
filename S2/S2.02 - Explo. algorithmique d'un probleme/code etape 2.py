# -*- coding: utf-8 -*-

"""
Auteurs :
    Chabanat Matis
    Le Menn Arthur
    TD1 | TP1
"""

import json
from math import sin, cos, acos, pi
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
        return float ('inf')

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




def dijkstra(depart, arrive):
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
    

    
    
def floydWarshall(depart, arrivee):
    #Initialisation
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
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if distances[i][j] > distances[i][k] + distances[k][j]:
                    distances[i][j] = distances[i][k] + distances[k][j]
                    pred[i][j] = pred[i][k]  
                    
    #Recherche du chemin depart --> arrivée
    chemin.append(depart)
    position = indiceDepart 
    while position != indiceArrivee:
        position = pred[position][indiceArrivee]
        chemin.append(nom(position))
    return chemin
        