# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

def pair(n):
    r = n % 2
    if r == 0:
        return True
    else:
        return False
    
def listeDiviseur(n):
    tab = []
    for i in range (1,n+1):
        r = n % i
        if r == 0:
            tab.append(i)
    return tab

def premiersEntreEux(n,m):
    tabN = [listeDiviseur(n)]
    tabM = [listeDiviseur(m)]
    
    