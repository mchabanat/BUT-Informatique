.DATA 
x DW 50
y DW 65
largeur DW 100
hauteur DW 50
.CODE
	LEA SP,STACK
	LD R0,0
	OUT R0,5
	
;envoi des paramètres dans la pile
	LD R0,%1011	;code couleur a envoyer dans la pile
	PUSH R0
	PUSH x
	PUSH y
	PUSH largeur
	PUSH hauteur
	CALL rectangle
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
	ADD R1,%0101	;rectangle plein rose
	OUT R1,5
	PULL R1
	RET 5
	
.STACK 10