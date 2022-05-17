.DATA
initialisee DW "Aller le foot."
.CODE
	LEA SP,STACK
	LEA R3,initialisee	;on met dans R2 l'adresse de initialisée
	LD R0,0
	OUT R0,5			;efface ecran
	LD R1,25			;pos en x
	LD R2,128 			;pos en y
	OUT R1,1
	OUT R2,2
	;PUSH R1				;sauvegarde des registres dans la pile (save de x et y du départ)
	;PUSH R2	
	CALL ecriture
	CALL souligner
	HLT
ecriture:	;procedure recoit les parametre par registre
	PUSH R0
	PUSH R3
boucle:
	CMP [R3],'.'
	BEQ fin
	OUT [R3],3			;on met le ASCII du carac étudié
	LD R0,%11110111		;ecriture du texte
	OUT R0,5
	INC R3
	JMP boucle
fin:
	PULL R3
	PULL R0
	RET
	
souligner:
	PUSH R0
	PUSH R2
	OUT R1,3
	ADD R2,2			;on baisse le trait de 2px
	OUT R2,4
	IN R2,2				;on recup le y de la fin de la chaine 
	ADD R2,2			;on baisse le trait de 2px
	OUT R2,2
	LD R0,%11110010		;on trace la ligne en blanc
	OUT R0,5
	PULL R2
	PULL R0
	RET
	
.STACK 10
