# -*- coding: utf-8 -*-
"""
Created on Fri Feb 18 10:26:40 2022

@author: mchabanat
"""

import pandas as pd
import matplotlib.pyplot as plt

'''

profilentrant=pd.read_table('F:\\BUT-Informatique\\S2\\R2.08 - Stats\\dataFrames\\ProfilEntrant.csv',
                            sep=";",
                            index_col=(0),
                            encoding='ANSI')

poursuite=pd.read_table('F:\\BUT-Informatique\\S2\\R2.08 - Stats\\dataFrames\\Poursuite.csv',
                        sep=";",
                        index_col=(0),
                        encoding='ANSI')

resultats=pd.read_table('F:\\BUT-Informatique\\S2\\R2.08 - Stats\\dataFrames\\Resultats.csv',
                        sep=";",
                        index_col=(0),
                        encoding='ANSI')
'''

valpineta=pd.read_table('F:\\BUT-Informatique\\S2\\R2.08 - Stats\\dataFrames\\valpineta_log.csv',
                        sep=";",
                        index_col=(0),
                        encoding='ANSI')


''' test :
valpineta['visit_total_time'].plot(kind='hist')
plt.title('Temps total par visite')
plt.xlabel('Temps total en secondes')
plt.ylabel('Nombre de visites')
plt.xlim(0,5000)
plt.grid(True)
plt.show()


valpineta['config_os'].value_counts()
'''

#Analyse bivariée quali-quali
croise=pd.crosstab(valpineta['config_os'],valpineta['moment de connexion'],normalize='index')
croise.plot(kind="bar",stacked=True)
#croise.index
#croise=croise["matin","midi","fin d'après midi","soir","nuit tardive"]
#plt.legend(title="Moment de connexion",bbox_to_anchor=(1.05,1.0,loc='upper left'))
plt.title('Répartition de l utilisation des OS en fonction du moment de la journée')
plt.xlabel('Utilisation de l OS')
plt.ylabel('Moment de la journée')
plt.show()


#Analyse bivariée quali-quanti 1
croise2=valpineta['visit_total_time'].groupby(valpineta['countrié']).mean()
croise2 = croise2.sort_values(ascending = False)
croise2.plot(kind='bar')
plt.title('Temps moyen de connexion sur le site par pays')
plt.xlabel('Lieu de connexion')
plt.ylabel('Temps de connexion moyen (en secondes)')
plt.show()



#Analyse bivariée quali-quanti 2

#tri



valpineta.boxplot(by ='countrié', column =['visit_total_time'],grid=False,showmeans=True)
plt.title('Temps moyen de connexion sur le site par pays')
plt.xlabel('Lieu de connexion')
plt.ylabel('Temps de connexion moyen (en secondes)')
plt.show()



