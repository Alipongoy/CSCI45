.global student_calc
student_calc:
    PUSH {LR}
    PUSH {R4-R12}        @This preserves R4 through R12 

	@R0 is x
	@R1 is y
	@R2 is z
	@R3 is loops

	@You should implement your code here
	@It must do the same thing as teacher_calc
	MOV R4, #0
	
	b loop

loop:
	CMP R4, R3
	BGE quit
	MUL R0, R0, R1
	SUB R0, R0, R2
	CMP R3, #2
	MOVLE R0, R0, LSR #1
	ADD R4, #1
	BAL loop
	

quit:
	@Return value is X, so it should already be in R0...
    POP {R4-R12}         @Restore R4 through R12 for the calling function
	POP {PC}             @Return from a function

.data
	line_0: .acsii "Joshua Jardenil 2016"
