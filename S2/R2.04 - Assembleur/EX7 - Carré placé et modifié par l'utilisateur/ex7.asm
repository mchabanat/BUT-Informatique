.DATA 

.CODE
	LEA SP,STACK
	
attenteClic:
	IN R0,0
	CMP R0,%11000111
	BNE attenteClic
	;coordonnées pour le grandCarré
	IN R6,6		;coord X du clic
	IN R5,7		;coord Y du clic
	CMP R6,50		;on regarde si les coordonnées ne sont pas hors de l'ecran
	BGEU verifY
	LD R6,50
verifY:
	CMP R5,50
	BGEU effacer
	LD R5,50
effacer:
	LD R0,0
	OUT R0,5
boucle:
	CALL grandCarré
	IN R1,0
	CMP R1,%11000110	;on regarde si touche B appuyée
	BEQ fin
	CMP R1,%11000101 	;on regarde si touche A appuyée
	BNE boucle
	CALL petitCarré
attenteRelachement:
	IN R1,0
	CMP R1,%10000101 	;on regarde si touche A relachée
	BNE attenteRelachement
	JMP effacer
fin:
	HLT

;********** sous programmes **********
grandCarré:
	PUSH R0		;save des registres
	PUSH R6
	PUSH R5
	SUB R6,50
	SUB R5,50
	;LD R0,R6
	OUT R6,1
	;LD R0,R5
	OUT R5,2
	LD R0,100
	OUT R0,3
	OUT R0,4
	LD R0,%11110011		;carré blanc au centre de la fenetre
	OUT R0,5
	PULL R5
	PULL R6
	PULL R0
	RET
petitCarré:
	PUSH R0		;save des registres
	PUSH R6
	PUSH R5
	SUB R6,25
	SUB R5,25
	LD R0,0
	OUT R0,5	;effacement de l'ecran
	;LD R0,103
	OUT R6,1
	OUT R5,2
	LD R0,50
	OUT R0,3
	OUT R0,4
	LD R0,%11110011		;carré blanc au centre de la fenetre
	OUT R0,5
	PULL R5
	PULL R6
	PULL R0 
	RET
	
.STACK 10