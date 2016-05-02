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
	LDR R0, R9
	BL print_number
line_20:
	LDR R0, =string_20
	BL print_string
line_30:
	BAL quit

quit:
	MOV R0, #42
	POP {R4-R12}
	POP {PC}
.data
string_20: .ascii "WHAT THE FUCK RIGHT NOW"

