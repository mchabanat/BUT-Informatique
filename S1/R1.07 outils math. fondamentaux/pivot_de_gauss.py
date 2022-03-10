t=[[1,3,2],
   [0,-1,-1],
   [0,0,3]]

v=[64,
   -24,
   31]

def remontee(t,v):
    w=v
    sol=[None for i in range(len(t))]
    for i in range ((len(v)-1) , -1 , -1):
        sol[i]=w[i]/t[i][i]
        for j in range (len(t[i])-1 , -1  ,-1):
            w[j] = w[j] - sol[i] * t[j][i]
    return sol

#print(remontee(t, v))

def echangeLignes(m,w,l1,l2):
    #echange du vecteur
    copieW=w[l1]
    w[l1]=w[l2]
    w[l2]=copieW
    
    #echange des lignes
    copieL1=m[l1]
    m[l1]=m[l2]
    m[l2]=copieL1
    
    print(m)
    print(w)

#echangeLignes(t, v, 2, 1)