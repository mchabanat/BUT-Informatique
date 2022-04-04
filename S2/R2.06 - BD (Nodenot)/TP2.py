# -*- coding: utf-8 -*-
"""
Created on Wed Mar 16 16:20:47 2022

@author: mchabanat
"""

import pyodbc

conn=pyodbc.connect('DSN=BD_Chabanat_Lakartxela') #Connexion au DSN (connexion odbc)
cursor= conn.cursor() #creation du curseur

sql= "select a.Reference,t.TauxTVA from Article a JOIN Categorie c ON a.CodeCategorie=c.CodeCategorie JOIN TVA t ON c.CodeTVA=t.CodeTVA WHERE a.Descriptif like 'B%' AND t.TauxTVA > 0.05"
cursor.execute(sql) #execution de la requete
for row in cursor.fetchall():
    print (row)

    




