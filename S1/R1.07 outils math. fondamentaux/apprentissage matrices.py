# -*- coding: utf-8 -*-
"""
Created on Tue Oct  5 10:16:52 2021

@author: mchabanat
"""

m = [[1,3,-1],
     [2,0, 4]]

def definirLigne (m,i):
    return m[i]

def definirColonne (m,j):
    liste = []
    for i  in range (len(m)):
        liste.append(m[i][j])
    return liste

#print (colonne(M1, 2))

def mult(m,x):
    liste = []
    for i in range (len(m)):
        for j in range (len(m[i])):
            liste.append(m[i][j]*x)
    return liste 

def prod_ligne_col(u,v):
    resultat = 0
    ligne = definirLigne(m,u)
    colonne = definirColonne(m, v)
    