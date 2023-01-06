# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

def pgcd(n,m):
    r = n % m
    while r > 0:
        n = m
        m = r
        r = n % m
    return m   


def euclide(a,b):
    u0,u1 = 1,0
    v0,v1 = 0,1
    r0,r1 = a,b
    while r1 != 0:
        q = r0 // r1
        r2 = r0 % r1
        u2 = u0 - q * u1
        v2 = v0 - q * v1
        r0 = r1
        r1 = r2
        u0,v0 = u1,v1
        u1,v1 = u2,v2
    return (r0,u0,v0)

print(euclide(165,72))