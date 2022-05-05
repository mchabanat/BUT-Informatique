# -*- coding: utf-8 -*-

import json
from math import sin, cos, acos, pi

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
        return 'inf'

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
def djikstra(arretDepart, arretArrive):
    
        
    
    
                
            
    