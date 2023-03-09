from collections import Counter

# Retourne les nbPremiers premieres lettres qui reviennent le plus dans le cryptogramme
def analysefreq(chaine,nbPremiers=10):
    c=Counter(chaine)
    freq=c.most_common(nbPremiers)
    return freq


alpha = "abcdefghijklmnopqrstuvwxyz"


def corresp(alpha):
    dic = {}
    for i in range(len(alpha)):
        dic[alpha[i]] = i
    return dic

def corresp(lettre):
    '''
    Cette fonction retourne l'entier lui correspondant.
    '''
    for i in range(len(alpha)):
        if lettre == alpha[i]:
            return i


dic = corresp(alpha)


def retrouvelettre(dic, code):
    for lettre in dic:
        if dic[lettre] == code:
            return lettre


def chiffrecesar(message, cle):
    code = ''
    for lettre in message:
        decalage = (dic[lettre]+cle) % 26
        lettrecodee = retrouvelettre(dic, decalage)
        code = code+lettrecodee
    return code


def dechiffrecesar(cryptogramme, cle):
    return chiffrecesar(cryptogramme, -cle)


def pgcd_euclide_etendu(n, m):
    if (n < m):
        temp = n
        n = m
        m = temp
    L1 = [n, 1, 0]
    L2 = [m, 0, 1]
    while L2[0] != 0:
        q = L1[0]//L2[0]
        L = L2[:]
        for i in range(0, 3):
            L2[i] = L1[i]-q*L2[i]
        L1 = L
    print("Le pgcd est ", L1[0])
    print("Les coéfficients de Bézout sont ", L1[1], ", ", L1[2])
    return L1[0], L1[1],  L1[2]


def inversemod(nb, mod):
    return pgcd_euclide_etendu(nb, mod)[2]


def chiffreaffine(message, a, b):
    code = ''
    for i in range(len(message)):
        numCar = dic[message[i]]
        numCarCode = (a*numCar+b) % 26
        code = code + retrouvelettre(dic, numCarCode)
    return code


def dechiffreaffine(cryptogramme, a, b):
    inverseModulaireA = inversemod(a, 26)  # Inversion modulaire
    bModifie = inverseModulaireA*-b % 26
    for i in range(len(cryptogramme)):
        numCar = dic[cryptogramme[i]]
        numCarCode = (inverseModulaireA*numCar-bModifie) % 26
        code = code + retrouvelettre(dic, numCarCode)
    return code


# Vigénère # 
texte='lavielemalheurlisolementlabandonlapauvretesontdeschampsdebataillequiontleursherosvictorhugo'
texteScinde=['lieluilelaoauestsasbalunesrvtho','aemhrsenannpvtodcmdaieituhoiou','vlaelomtbdlarenehpetlqolrescrg']

def scindermod(texte,longueur):
    texteScinde = []
    for i in range(longueur):
        chaine=''
        for j in range(len(texte)):
            if j%longueur==i:
                chaine+=texte[j]
        texteScinde.append(chaine)
    return texteScinde


def reecriremod(scinde,longueur):
    lgrTexte=0
    for i in range(longueur-1):
        maxLgr=max(len(scinde[i]),len(scinde[i+1]))
        if maxLgr>lgrTexte:
            lgrTexte=maxLgr

    texte=''
    for i in range(0,lgrTexte):
        for j in range (longueur):
            if i <= len(scinde[j])-1:
                texte+=scinde[j][i]
                
    return texte


def findCle(textCrypte, longueurCle):
    '''
    Retourne une suggestion de clé par rapport à la récurence des lettres.
    '''
    tabText = scindermod(textCrypte, longueurCle)
    cleInt = []
    cle = ""
    for i in range(len(tabText)):
        tab = analysefreq(tabText[i], 2)
        cleInt.append((corresp(tab[0][0])-dic['e'])%len(alpha))
        cle += str(alpha[cleInt[i]])
    return cle

cryptogramme='snzsmmifkcgusivsniwnasotshnohbzizgkcsfmgulifbsmizfiwyvhybjyvocmbnxfcaruvgxmguntuqfyaeoqgyupfiwyvhcudizhuvhyasnkchawxmfujzyadoqgkcsfmgazohlsmxslachvsmijuqshbzuqfnzsmwqwcdymgybduzqyyiivbykcgxfyvocbfcmbutsozgamgnmgfwfmyiivguxslkccbihjsucxicfkcsfmilacwkijihcwbmachbdcmhlmgfmilusnqslnwamsnyictghwbnxzoarytwyvopmqfijcmdicfkcccvsjigwwbnqbomfnmzovshnohbojwfnmffiryagoazyusgmfyoolleomgozqyyicmgnmhlibamfliwhmfgifcifctyytsnbfyaoovxycbyxcybs'
cle=findCle(cryptogramme,3)



def chiffrevigenere(message,cle):
    longueur = len(cle)
    msgScinde=scindermod(message,longueur)
    msgScindeTraduit=[]

    # Effectuer le decalage de chaque caractère
    for i in range(len(msgScinde)):
        indiceCle = dic[cle[i]]
        chaine=''
        for j in range(len(msgScinde[i])):
            indiceCar = dic[msgScinde[i][j]]
            indiceCar = (indiceCar+indiceCle)%26
            chaine+=retrouvelettre(dic,indiceCar)
        msgScindeTraduit.append(chaine)
    
    # Ecriture du cryptogramme
    cryptogramme=reecriremod(msgScindeTraduit,longueur)

    return cryptogramme


def dechiffrevigenere(cryptogramme,cle):
    message = ''

    cryptogrammeScinde = scindermod(cryptogramme,len(cle))
    cryptoScindeTraduit = []

    for i in range(len(cryptogrammeScinde)):
        chaine=''
        indiceCle = dic[cle[i]]
        for j in range(len(cryptogrammeScinde[i])):
            indiceCar = dic[cryptogrammeScinde[i][j]]
            indiceCar = (indiceCar-indiceCle)%26
            chaine+=retrouvelettre(dic,indiceCar)
        cryptoScindeTraduit.append(chaine)
    
    # Assemblage du mot final
    message = reecriremod(cryptoScindeTraduit,len(cle))
    
    return message


texteB=chiffrevigenere(texte,'bec')
print(texteB)
texteC=dechiffrevigenere(texteB,'bec')
print(texteC)