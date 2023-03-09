import collections

#Variables globales
alpha = "abcdefghijklmnopqrstuvwxyz"

#Fonctions
def corresp(lettre):
    '''
    Cette fonction retourne l'entier lui correspondant.
    '''
    for i in range(len(alpha)):
        if lettre == alpha[i]:
            return i

def cryptageVigenere(cle, chaine):
    '''
    Cette fonction retourne une chaine crypté par vigenère de chaine. 
    '''
    chaineCrypte = ""
    for i in range(len(chaine)):
        chaineCrypte += alpha[corresp(chaine[i])+int(corresp(cle[i%len(cle)]))] #On incrémente la lettre chaine[i] décaler de i modulo longueur de clé dans la clé
    return chaineCrypte

def decryptageVigenere(cle, chaine):
    '''
    Cette fonction retourne une chaine décrypté par vigenère de chaine.
    '''
    chaineDecrypte= ""
    for i in range(len(chaine)):
        chaineDecrypte += alpha[corresp(chaine[i])-int(corresp(cle[i%len(cle)]))] #On incrémente la lettre chaine[i] décaler de -i modulo longueur de clé dans la clé
    return chaineDecrypte

def scindermod(text, longueur):
    '''
    Cette fonction découpe le texte en longeur.
    '''
    tab = []
    for i in range(longueur):
        tab.append('')
    for i in range(len(text)):
        tab[i%longueur] += text[i]
    return tab

def compterLettre(text, nbLettre):
    '''
    Retourne un tableau avec les lettres les plus récurente.
    '''
    return collections.Counter(text).most_common(nbLettre)
     

def findCle(textCrypte, longueurCle):
    '''
    Retourne une suggestion de clé par rapport à la récurence des lettres.
    '''
    tabText = scindermod(textCrypte, longueurCle)
    cleInt = []
    cle = ""
    for i in range(len(tabText)):
        tab = compterLettre(tabText[i], 2)
        cleInt.append((corresp(tab[0][0])-corresp('e'))%len(alpha))
        cle += str(alpha[cleInt[i]])
    return cle

def cryptanalyse(textCrypte, longueurCle):
    '''
    Retourne la chaine de caractère décrypté.
    '''
    return decryptageVigenere(findCle(textCrypte, longueurCle), textCrypte)


#RSA
def puissModulaire(a,b,mod):
    return (a**b)%mod


#TEST

chaine = "amhrccrzdslttmgbcgcwjapplbtsvtpqkgmgcirazdapplbumtacutlbpsfwczqcascawyqajwcqlppotlbdsttqwacqabmayudlbpevtdqtpmasqiamhrccnmigbkytfsqbmchqmsczpwwcqccqwabiihmjlmqmcrfmdsdtpbtrmicvjcmijicsyjcjpgocyvibicqttdzpgarpmhqwczttsldpbxjmhrmicvsslplaafmgzmhmchjicsmeyttbicqadltxrdtpbdstpjcbgmgcxaccijmhnqtbasyvhjmhetpgmjjaxjldpbhmcggicrkdkutqwjpqgyqisvtlnplbbytpbmxjnpgbjladkutliisztzmgamackwycscutlbxjiupwxbttqxppnjkaccndlbeyaupqhqwclmgqicyzxlmxjldpbsyvhjmhmttgtayupgvhszhyxdgbggvtrzplyjgtacqayltsfipwjqzdsotqijawiclgmqi"

print(cryptanalyse(chaine, 3))

print(puissModulaire(9,3,33))

print(27*9)