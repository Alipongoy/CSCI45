.global main
main:
	PUSH {LR}
	PUSH {R4-R12}

	MOV R4, #0
	MOV R5, #0
	MOV R6, #0
	MOV R7, #0
	MOV R8, #0
	MOV R9, #0
	MOV R10, #0
	MOV R11, #0
line_5:
@this is a comment  

quit:
	MOV R0, #42
	POP {R4-R12}
	POP {PC}
.data
