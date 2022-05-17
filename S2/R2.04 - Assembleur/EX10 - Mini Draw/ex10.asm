.DATA
x DW 0
y DW 0
largeur DW 20
hauteur DW 16
premierClic DW 0
couleur DSW 1
.CODE
	LEA SP,STACK
debutprog:
	LD R0,0
	OUT R0,5
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
attenteClic:
	IN R0,0
	CMP R0,%11000111
	BEQ debutdessin
	CMP R0,%11000110	;on regarde si touche B appuyée
	BEQ findessin
	CMP R0,%11000101 	;on regarde si touche A appuyée
	BNE attenteClic
	LD R0,0
	ST R0,premierClic	;reinit de premierClic
	ST R0,y
	JMP debutprog
debutdessin:
	IN R1,6
	IN R2,7		;récup des coord du clic : R1 = x, R2 = y
	CMP R1,20	;on regarde si le clic est dans la partie dessin ou choixCouleur
	BGTU trace
	LD R3,R2	;changer couleur
	DIVU R3,16
	ST R3,couleur
	SHL couleur
	SHL couleur
	SHL couleur
	SHL couleur
	LD R4,couleur
	ADD R4,%0010
	ST R4,couleur
	JMP attenteClic
trace:
	LD R0,premierClic
	CMP R0,0
	BNE pasPremier
	INC premierClic
	JMP finTrace
pasPremier:
	OUT R5,1
	OUT R6,2	;placement des anciennes coord dans le point de depart
	OUT R1,3
	OUT R2,4	;placement des dernieres coord dans le point d'arrivée
	CMP R3,couleur	;on regarde si la couleur a été changée, 
	BEQ memeCouleur	;si pas de chgt on va direct au tracé
	SHL R3
	SHL R3
	SHL R3
	SHL R3
	ADD R3,%0010	;dessin du trait
memeCouleur:
	OUT R3,5
finTrace:
	LD R5,R1
	LD R6,R2 	;save des x et y
	JMP attenteClic
findessin:
	HLT
	
	
;********** sous programmes **********
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
.STACK 10

