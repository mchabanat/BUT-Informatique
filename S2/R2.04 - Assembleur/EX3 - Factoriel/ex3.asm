.DATA
valinit DW 6
Fact DSW 1
.CODE
		LEA SP,STACK
		LD R0,1
		LD R1,2
boucle:	CMP R1,valinit
		BGTU fin
		MULU R0,R1
		INC R1
		JMP boucle
fin:	ST R0,Fact
		HLT
.STACK 10