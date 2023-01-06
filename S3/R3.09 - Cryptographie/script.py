alpha="abcçdefghijklmnopqrstuvwxyz" 

def corresp(alpha):
    dic={}
    for i in range(len(alpha)):
        dic[alpha[i]]=i
    return dic

def retrouvelettre(dic,code): 
    for lettre in dic:
        if dic[lettre] == code:
            return lettre

def codageCesar(message,cle): 
    code=''
    for lettre in message:
        decalage=(dic[lettre]+cle)%26
        lettrecodee=retrouvelettre(dic,decalage) 
        code=code+lettrecodee
    return code

def dechiffrecesar(cryptogramme,cle): 
    return codageCesar(cryptogramme,-cle)

def pgcd_euclide_etendu(n,m):
    if(n<m):
        temp=n
        n=m
        m=temp    
    L1=[n,1,0]
    L2=[m,0,1]
    while L2[0]!=0:
        q=L1[0]//L2[0]
        L=L2[:]
        for i in range(0,3):
            L2[i]=L1[i]-q*L2[i]
        L1=L
    print("Le pgcd est ", L1[0])
    print("Les coéfficients de Bézout sont ", L1[1], ", ",L1[2])
    return L1[0], L1[1],  L1[2]

def inversemod(nb,mod):
    return pgcd_euclide_etendu(nb,mod)[2]

def ch_affine(message,a,b):
    code = ''
    for i in range (len(message)):
        numCar = dic[message[i]]
        numCarCode = (a*numCar+b)%26
        code = code + retrouvelettre(dic,numCarCode)
    return code

def de_affine(cryptogramme,a,b):
    code =''
    inverseModulaireA = inversemod(a, 27) #Inversion modulaire
    bModifie = inverseModulaireA*-b%27
    for i in range (len(cryptogramme)):
        numCar = dic[cryptogramme[i]]
        numCarCode = (inverseModulaireA*numCar-bModifie)%27
        code = code + retrouvelettre(dic,numCarCode)
    return code

def frequenceCar(cryptogramme):
    from collections import Counter
    c=Counter(cryptogramme)
    freq=c.most_common(5)
    return freq

cpt = 'pgoyxjizginyigjikuvnnikrpykkiroioeinisgirojytgikioqpsdiregvyokjikeykoyrxoyvrkkvxypjikriziswiroiogimvreikçsiksgjsoyjyoxvnnsri'
print(frequenceCar(cpt))

dic = corresp(alpha)

print(de_affine(cpt,17,-14))


