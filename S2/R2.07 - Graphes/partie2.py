Dic1={'nom':'Dupont','prenom':'Pierre','age':18}

len(Dic1)

Dic1['prenom']='Mouloud'


etud={'Pierre':(175,75),'Claire':(180,68),'Jean':(160,55),'Lucie':(155,55)}

def fonc(dic):
    n=None
    t=None
    for (a,(b,c)) in etud.items():
        print(a,b,c)
        if t==None or t>b:
            t=b
            n=a
    return (n,t)


dic={0:[0,1,2],1:[1,2],2:[1,2,3],3:[2,3]}


        
        

M=[[1,0,1,0],[0,1,1,0],[1,1,1,1],[0,0,1,1]]    

def prog(Mat):
    bool=True
    n=len(Mat)
    for i in range(n):
        for j in range(n):
            print (Mat[i][j],Mat[j][i])
            if Mat[i][j]!=Mat[j][i]:
                bool=False
                break
    return bool 
        

dict={0:[0,1,2],1:[0,1,2],2:[1,2,3],3:[2,3]}

print(dict[2][1])



