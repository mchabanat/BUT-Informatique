.DATA 

.CODE
	LEA SP,STACK
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

;********** sous programmes de tracé des carrés **********
grandCarré:
	PUSH R0		;save du registre
	LD R0,78
	OUT R0,1
	OUT R0,2
	LD R0,100
	OUT R0,3
	OUT R0,4
	LD R0,%11110011		;carré blanc au centre de la fenetre
	OUT R0,5
	PULL R0
	RET
petitCarré:
	PUSH R0		;save du registre
	LD R0,0
	OUT R0,5	;effacement de l'ecran
	LD R0,103
	OUT R0,1
	OUT R0,2
	LD R0,50
	OUT R0,3
	OUT R0,4
	LD R0,%11110011		;carré blanc au centre de la fenetre
	OUT R0,5
	PULL R0		;récup du registre 
	RET
	
.STACK 10