# Final
## 10 Questions on ASM
## 10 Questions on Binary
- LSR
- LSL
- ASR
- ROR
- IEE 754

## 10 Questions on Architecture
#### Ways Architectures Work with Memory
1) __Register + Memory Architecture__
	- When you directly load from memory and change values in memory directly
	- Slow
	- Most modern arcitectures disallow working directly with values in RAM

2) __Load/Store Architecture__
	- When you load values into a register from RAM and vice versa
	
	```assembly
		LDR R1, =0x12345678
		LDR R0, [R1]
	``` 

#### Computer Architectures
1) __RISC__
	- a design philosophy that a CPU should as little instructions as possible so hardware can be cheap, simple, and fast
	- Every command is usually 32 or 64 bits
	- Each command runs in one cycle
	- The ARM architecture follows this
	- This is more superior according to Brofessor Kerney
2) __CISC__
	- a design philosophy that a CPU should have more complex instructions, like sine or cosine, because its faster to run complex instructions in hardware than implement them in software
	- A flaw to __CISC__ is that instruction decoding can become very complicated

## 5 Points on Physical Computing
#### Caching

#### ALU
An __Arithmatic Logic Unit(ALU)__ is a single block of circuitry that can do multiple commands. An ALU typically has 32 commands. These commands include:

1) ADD
2) SUB
3) INCREMENT
4) NEGATE
5) MULTIPLY
6) Logical Expressions(AND, OR, EOR, NOT)
7) Rotate

An 8 bit __ALU__ would take two 8 bit numbers as inputs, and an 8 bit command.

Instructions such as multiply would take at least 4 cycles to complete, so if you have one __ALU__, there would be a pipeline stall. To prevent this, we have multiple __ALUs__, AKA superscalar computing.

#### Superscalar Computing
__Superscalar Computing__ is the idea that we have multiple ALUs implemented in the CPU. The 

## 5 Points Debugging
## 10 Points Writing Code

# Topics on the Final
## Registers (R0 through R15, including PC and LR)
R11 - Link Register
R13 - Stack Register
## Function calls
## Addressing modes
## Arithmetic operations (ADD, SUB, MUL, no DIV or MOD)
## Logical operations (CMP, or the –S suffix)
## Branching (BAL, BEQ, BGT, etc.)
## Bitwise operations (ORR, AND, BIC)
## Labels (local and global); .data labels (.skip, .asciz)
## Be able to read NEON
