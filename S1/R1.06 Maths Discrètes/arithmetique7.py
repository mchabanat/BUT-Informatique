# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

def tab_add(n):
    add=[]
    for i in range (n):
        add.append([])
        for j in range (n):
            add[i].append((i+j)%n)
    for i in range (len(add)):
        print (add[i])
        
def tab_mult (n):
    mult=[]
    for i in range(n):
        mult.append([])
        for j in range (n):
            mult[i].append((i*j)%n)
    for i in range (len(mult)):
        print (mult[i])
        
