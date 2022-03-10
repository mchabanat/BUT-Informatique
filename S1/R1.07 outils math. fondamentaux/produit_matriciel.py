# -*- coding: utf-8 -*-
"""
Created on Tue Nov 16 14:51:43 2021

@author: mchabanat
"""

m1 = [[1,3,5],
      [2,4,6]]

m2 = [[0,1],
      [-1,1],
      [1,0]]

m1xm2 = [[2,4],
         [2,6]]

#ca ne marche pas
def prod_matriciel(mat1,mat2):
    n=len(mat1)
    m=len(mat2)
    resultat=[]
    for i in range (n):
        resultat.append([])
        for j in range (m):
            resultat.append( mat1[i][j] * mat2[i][j] )
    return resultat

print(prod_matriciel(m1, m2))