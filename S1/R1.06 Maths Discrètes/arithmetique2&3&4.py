# -*- coding: utf-8 -*-
"""
Created on Mon Oct 11 08:06:50 2021

@author: mchabanat
"""

#import timeit


def verifPremier(nombre):
    compteur = 0
    for i in range (1,nombre):
        if nombre % i == 0:
            compteur = compteur + 1
    if nombre == 1:
        return False
    if compteur > 2 :
        return False
    else: 
        return True
    
def eratosthene():
    for i in range(1,301):
        print (i, " ", verifPremier(i))
        
def listePremier(n):
    tab = []
    for i in range (2,n+1):
        if verifPremier(i) == True:
            tab.append(i)
    return tab




#SEANCE 3

'''
debut = timeit.default_timer()
listePremier(1000)
fin = timeit.default_timer()
duree = fin - debut
print(duree)


entier=[i for i in range(0, 10000, 100)]
temps=[]
for i in entier:
    tps1 = timeit.default_timer()
    listePremier(i)
    tps2 = timeit.default_timer()
    temps.append(tps2 - tps1)
 
# Représentation avec pyplot de matplotlib
import matplotlib.pyplot as plt

plt.plot(entier,temps)
plt.show() # affiche la figure a l'ecran
'''

def decomposition(n):
    ldiv=[]
    for i in range (2, n+1):
        while n % i == 0:
            ldiv.append(i)
            n = n / i
    return ldiv


#PROGRAMME PRINCIPAL
'''
n = int(input("Saisissez un entier superieur ou egal a 2 : "))
print ("Liste des facteurs premiers : ",decomposition(n))'''


.def pgcd(n,m):
    r = n % m
    while r > 0:
        n = m
        m = r
        r = n % m
    return m        

def pgcdRecursif(n,m):
    r = n % m
    if r==0:
        return m
    else:
        return pgcdRecursif(m, r)






















