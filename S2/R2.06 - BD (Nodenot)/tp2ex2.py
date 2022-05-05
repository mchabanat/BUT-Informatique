# -*- coding: utf-8 -*-
"""
Created on Tue Mar 22 10:08:46 2022

@author: mchabanat
"""

import pyodbc
import pandas as pd
import matplotlib.pyplot as plt

conn=pyodbc.connect('DSN=BD_Chabanat_Lakartxela') #Connexion au DSN (connexion odbc)
cursor= conn.cursor()

'''
#Question 1-2
RefArticles=[]
qteStockArticles=[]

sql="SELECT a.Reference,a.QteStock FROM Article a WHERE PrixHT > 5.0 ORDER BY a.QteStock ASC"

cursor.execute(sql)

for row in cursor.fetchall():
    RefArticles.append(row[0])
    qteStockArticles.append(row[1])

plt.bar(RefArticles, qteStockArticles)
plt.xlabel("Reference des articles")
plt.ylabel("Stock articles")
plt.title("Graphique des stocks des articles de plus de 5 euros à l'unité")
plt.show()'''




#Question 5
filter=input("Saisissez la reference des articles dont vous voulez connaitre la quantite disponible : ")

mysql=f"SELECT Reference, QteStock FROM Article WHERE Reference = '{filter}'"

df1 = pd.read_sql(mysql,conn)

df1.plot(kind="bar", x="Reference", y="QteStock")
plt.show()