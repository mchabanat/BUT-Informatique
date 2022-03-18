# -*- coding: utf-8 -*-
"""
Created on Wed Mar 16 16:20:47 2022

@author: mchabanat
"""

import pyodbc

conn=pyodbc.connect('DSN=BD_Mchabanat_Lakartxela') #Connexion au DSN (connexion odbc)

cursor= conn.cursor() #creation du curseur
filter=input("Entrez le debut des descriptifs qui vous interessent : ")
sql= "select * from Article where ((Descriptif like ? and Reference <> ?))"
param = (f'{filter}%','B12')
cursor.execute(sql,param) #execution de la requete
print (cursor.fetchall()[0])
    




