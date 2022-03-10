mat1=[[0,0,0,1],[0,1,1,0],[1,0,0,1],[1,0,1,0]]
mat2=[[0,1,0,0],[1,0,1,0],[0,0,0,1],[0,0,0,0]]

s=0

def succ(M,s):
    listeSucc = []
    for i in range (len(M[s])):
        if M[s][i] == 1:
            listeSucc.append(i)
    return listeSucc

def parcoursProfondeur(M,s):
    S=[]
    Vu=[]
    p=[]
    Succ=[]
    p.append(s)
    Vu.append(s)
    while p != []:
        s=p.pop()
        S.append(s)
        Succ = succ(M,s)
        for i in range(len(Succ)):
            if Succ[i] not in Vu:
                p.append(Succ[i])
                Vu.append(Succ[i])
    return (S)

def parcoursLargeur(M,s):
    S=[]
    Vu=[]
    f=[]
    Succ=[]
    f.append(s)
    Vu.append(s)
    while f != []:
        s=f.pop(0)
        S.append(s)
        Succ = succ(M,s)
        for i in range(len(Succ)):
            if Succ[i] not in Vu:
                f.append(Succ[i])
                Vu.append(Succ[i])
    return (S)

print(parcoursLargeur(mat2, 1))

