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

		LDR R1, =0x12345678
		LDR R0, [R1]

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

#### Flynn's Taxonomy
__Flynn's Taxonomy__ categorizes computers by how they answer two questions:

1. Does the computer process 1 stream of instructions at a time, or can it do 2+ in parallel?
2. Does the computer have the ability to have 1 instruction work on one bit of data at a time, or can it work on 2+ in parallel?

In Flynn's Taxonomy, there are 4 types of architectures. These include:

1. __SISD__
		- Single Instruction Single Data. This type of computer has a single instruction stream and a single data stream.
		- This type of data structure runs one program at a time. In order for it to multiprocess, the OS swaps one program out and another program in.
2. __SIMD__
		- Single Instruction Multiple Data. One instruction can operate on multiple chunks of data at once. 
		```
			for (i = R0; R0 < R8; i++) {
				// Imagine this, but happening in one cycle.
				MUL i, #10
			}
		```
		- Massive preformance boost in comparison to __SISD__
3. __MISD__
		- 

## 5 Points on Physical Computing
#### Caching

#### ALU
An __Arithmatic Logic Unit(ALU)__ is a single block of circuitry that can do multiple commands. An ALU typically has 32 commands. These commands include:

1. ADD
2. SUB
3. INCREMENT
4. NEGATE
5. MULTIPLY
6. Logical Expressions(AND, OR, EOR, NOT)
7. Rotate

An 8 bit __ALU__ would take two 8 bit numbers as inputs, and an 8 bit command.

Instructions such as multiply would take at least 4 cycles to complete, so if you have one __ALU__, there would be a pipeline stall. To prevent this, we have multiple __ALUs__, AKA superscalar computing.

#### Superscalar Computing
__Superscalar Computing__ is the idea that we have multiple ALUs implemented in the CPU. With multiple ALUs, we could __dispatch__ these commands to different __functional units__, and have all of them execute in parallel with each other.

An __ALU__ is a functional unit.
A __FPU__ handles floating point math.
We can also issue __load__ and __store__ commands.

You can also bitpack to make instructions more efficient.

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
