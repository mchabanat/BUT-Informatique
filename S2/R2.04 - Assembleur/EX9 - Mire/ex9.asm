.DATA
x DW 0
y DW 0
largeur DW 255
hauteur DW 16
.CODE
	LEA SP,STACK
	LD R0,0
	OUT R0,5	;on efface l'ecran
	LD R0,%0000	;code couleur a envoyer dans la pile
mire:
	PUSH R0		;push la couleur
	PUSH x
	PUSH y
	PUSH largeur
	PUSH hauteur
	CALL rectangle		;trace une ligne de mire
	INC R0		;on change de couleur
	LD R2,y
	ADD R2,16	;on ajoute 16 a y pour pouvoir faire un nouveau rectangle vers le bas
	ST R2,y
	CMP R2,255 ;tant que R2 est inferieur a 255
	BLTU mire ;on retourne a l'étiquette mire
	HLT

rectangle:
	PUSH R1
	LD R1,[SP+5]	;recup du x
	OUT R1,1
	LD R1,[SP+4]	;recup du y
	OUT R1,2
	LD R1,[SP+3]	;recup de la largeur
	OUT R1,3
	LD R1,[SP+2]	;recup de la hauteur
	OUT R1,4
	LD R1,[SP+6]	;recup de la couleur
	SHL R1		
	SHL R1
	SHL R1
	SHL R1		;permet de mettre décaler a gauche de 4 bits le code couleur pour pouvoir ensuite y ajouter le code de tracé
	ADD R1,%0101	;rectangle plein 
	OUT R1,5
	PULL R1
	RET 5
.STACK 20


	