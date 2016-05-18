.global main
main:
    PUSH {LR}
    PUSH {R4-R12}        @This preserves R4 through R12 

	@Read the readme file
	@You'll just want to have a bunch of calls to the write syscall here.
	@Remember you'll need a data section below to store the strings to be printed.
	MOV R0, #0
	LDR R1, =line_1
	MOV R2, #53
	MOV R7, #4
	SWI 0

	MOV R0, #0
	LDR R1, =line_2
	MOV R2, #44
	MOV R7, #4
	SWI 0

	MOV R0, #0
	LDR R1, =line_3
	MOV R2, #51
	MOV R7, #4
	SWI 0


	MOV R0, #0
	LDR R1, =line_4
	MOV R2, #48
	MOV R7, #4
	SWI 0


	MOV R0, #0
	LDR R1, =line_5
	MOV R2, #43
	MOV R7, #4
	SWI 0




quit:
	MOV R0, #0			 @Return 0 on a successful exit
    POP {R4-R12}         @Restore R4 through R12 for the calling function
	POP {PC}             @Return from a function

.data
	line_1: .ascii "MONETARY STATUS is not what matters (but it helps) \-\n"
	line_2: .ascii "A man is MEASURED by the way that he THINKS\n"
	line_3: .ascii "not clothing lines, ice memes, mudkips, and minks.\n"
	line_4: .ascii "I spent 20 plus years SEEKING KNOWLEDGE itself.\n"
	line_5: .ascii "So live life for LIFE, and not for wealth.\n"
	line_6: .ascii "Joshua Jardenil 2016"
