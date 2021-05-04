// Karishma Khanna
// January 19, 2021
// functions.s
// Code for Lab2a of COEN 20
// Parameters are R0-R3

						.syntax				unified
						.cpu					cortex-m4
						.text

// int32_t Add(int32_t a, int32_t b);
						.global				Add
						.thumb_func
						.align
Add:				ADD 					R0,R0,R1 		// op1 = R0 = a, op2 = R1 = b, R0 = R0 + R1
						BX						LR					// PC <- LR

// int32_t Less1(int32_t a);
						.global				Less1
						.thumb_func
						.align
Less1:			SUB 					R0,R0,1 		// op1 = R0 = a, op2 = 1, R0 = R0 - 1
						BX						LR					// PC <- LR

// int32_t Square2x(int32_t x);
						.global				Square2x
						.thumb_func
						.align
Square2x:		ADD						R0,R0,R0 		// op1 = R0 = x, op2 = R0 = x, R0 = R0 + R0 = 2x
						B						  Square 			// Square(R0) = Square(2x), R0 = R0 * R0

// int32_t Last(int32_t x);
						.global				Last
						.thumb_func
						.align
Last: 			PUSH					{R4,LR}			// push R4 and LR onto stack
						MOV						R4,R0				// R4 = R0 = x, moves x to R4
						BL						SquareRoot	// SquareRoot(R4) = SquareRoot(x)
						ADD						R0,R4,R0		// op1 = R4 = x^(1/2), op2 = R0 = x, R0 = R4 + R0
						POP						{R4,LR}			// pops R4 and LR off stack
						BX						LR					// PC <- LR

						.end
