#You are going to write three functions here:
# function_one
# function_two
# function_three

#Here's an example function_two.
#DO NOT JUST USE MY EXAMPLE FUNCTION_TWO
#function signature: int function_two(int *arr, int width, int height, int stride);
.global function_two
function_two:
    PUSH {LR}
    PUSH {R4-R12}        @This preserves R4 through R12 

	@R0 is *arr
	@R1 is width
	@R2 is height
	@R3 is stride
	MULS R4,R1,R2 @R4 will hold how many bytes to process - this is enough for the red part
	BLE quit @If image is zero size, quit
	ADD R4, R4, R4, LSL #1 @R4 *= 3 - this will make it big enough for all four colors
loop:
	SUBS R4,R4,#16 @If we drop below 0 we're done, otherwise knock off 128 bits
	BLT quit
	vld1.u8 {q0}, [R0]	 @Load 128 bits from arr
	vshr.u8 q0,q0,#1	 @Right shift them all by 1 bit (darken it)
	vst1.u8 {q0}, [R0]!	 @Store 128 bits to arr
	@TODO: Implement striding
	BAL loop

quit:
	MOV R0,#0			 @Return value of 0
    POP {R4-R12}         @Restore R4 through R12 for the calling function
	POP {PC}             @Return from a function
