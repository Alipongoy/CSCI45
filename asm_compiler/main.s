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
line_1:
line_2:
line_3:
line_10:
	CMP R9, R10
	BNE line_30
	BAL line_40
line_30:
line_40:
line_50:
	MOV R0, R9
	BL print_number
line_60:
	LDR R0, =string_1
	BL print_string
line_70:
	CMP R9, R10
	BEQ line_100
	BAL line_110
