.DATA
chaine DW "chabanatmatisssssSSS"
	   DW 0
maxi DSW 1
.CODE
	LEA SP,STACK
	LEA R2,chaine	;on met dans R2 l'adresse de chaine
	LD R1,0
boucle:
	LD R0,[R2]
	CMP R0,0
	BEQ fin		; si ils sont egaux on va direct a l'etiquette fin
	CALL max	; appel de la procédure max 
	LD R1,R3
	INC R2
	JMP boucle 	; retour ligne 9
fin:
	ST R3,maxi	; on met la valeur de R3 dans maxi
	HLT	
max:
	LD R3,R0
	CMP R3,R1
	BGTU suite	;si R3 est plus grand que R1 on va direct a suite
	LD R3,R1	
suite:
	RET 
.STACK 10
