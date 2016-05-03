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
line_10:
	BL input_number
	MOV R9, R0
line_20:
	LDR R0, =string_1
	BL print_string
line_30:
	MOV R0, R9
	BL print_number

quit:
	MOV R0, #42
	POP {R4-R12}
	POP {PC}
.data
string_1: .ascii "x =  "
