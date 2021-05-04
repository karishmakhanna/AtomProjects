/*
	This code was written to support the book, "ARM Assembly for Embedded Applications",
	by Daniel W. Lewis. Permission is granted to freely share this software provided
	that this notice is not removed. This software is intended to be used with a run-time
	library adapted by the author from the STM Cube Library for the 32F429IDISCOVERY
	board and available for download from http://www.engr.scu.edu/~dlewis/book3.
*/
						.syntax		unified
						.cpu		cortex-m4
						.text

						// Q16 Normalize(Q16 divisor, int zeros) ;
						.global		Normalize
						.thumb_func
						.align
Normalize:				// R0 = divisor, R1 = zeros
						CMP			R1,16				// compare R1 to 16
						ITTEE		HS					// is zeros >= 16?
						SUBHS		R1,R1,16			// if yes, then R1 -> (zeros - 16)
						LSLHS		R0,R0,R1			// if yes, then R0 -> divisor << (zeros - 16)
						RSBLO		R1,R1,16			// if no, then R1 -> (16 - zeros)
						LSRLO		R0,R0,R1			// if no, then R0 -> divisor >> (16 - zeros)
						BX			LR

						// Q16 Denormalize(Q16 estimate, int zeros) ;
						.global		Denormalize
						.thumb_func
						.align
Denormalize:			// R0 = estimate, R1 = zeros
						CMP			R1,16				// compare R1 to 16
						ITTEE		HS					// is zeros >= 16?
						SUBHS		R1,R1,16			// if yes, then R1 -> (zeros - 16)
						LSRHS		R0,R0,R1			// if yes, then R0 -> estimate >> (zeros - 16)
						RSBLO		R1,R1,16			// if no, then R1 -> (16 - zeros)
						LSLLO		R0,R0,R1			// if no, then R0 -> estimate << (16 - zeros)
						BX			LR

						// Q16 NormalizedEstimate(Q16 divisor) ;
						.global		NormalizedEstimate
						.thumb_func
						.align
NormalizedEstimate:		// R0 = divisor
						LDR			R1,=123362			// constant for FIXED(32.0/17.0)
						SMULL		R0,R1,R0,R1			// R1.R0 -> Q16Product(divisor, FIXED(32.0/17.0), centered
						LSR			R0,R0,16			// shift right to capture lower middle bits in R0
						ORR			R0,R0,R1,LSL 16		// use ORR to capture upper middle bits in R0
						LDR			R1,=185043			// constant for FIXED(48.0/17.0)
						SUB			R0,R1,R0			// R0 -> FIXED(48.0/17.0) - Q16Product(divisor, FIXED(32.0/17.0))
						BX			LR

						// Q16 InitialEstimate(Q16 divisor) ;
						.global		InitialEstimate
						.thumb_func
						.align
InitialEstimate:		// R0 = original divisor
						PUSH		{R4,LR}				// preserve LR,R4
						CLZ			R4,R0				// R4 -> zeros = LeadingZeros(divisor)
						MOV			R1,R4				// R1 -> zeros
						BL			Normalize			// R0 -> divisor = Normalize(divisor, zeros)
						BL			NormalizedEstimate	// R0 -> estimate = NormalizedEstimate(divisor)
						MOV			R1,R4				// R1 -> zeros
						BL			Denormalize			// R0 -> Denormalize(estimate, zeros)
						POP			{R4,PC}				// restore LR,R4 and return

						// Q16 Reciprocal(Q16 divisor) ;
						.global		Reciprocal
						.thumb_func
						.align
Reciprocal:				// R0 = divisor
						PUSH		{R4,R5,R6,R7,R8,LR}	// preserve LR,R4,R5,R6,R7,R8
						MOV			R4,R0				// R4 -> divisor
						BL			InitialEstimate		// R0 -> curr = InitialEstimate(divisor)
						MOV			R7,R0				// R7 -> curr
L1:						MOV			R5,R7				// R5 -> prev = curr
						SMULL		R0,R1,R4,R5			// R1.R0 -> Q16Product(divisor, prev), centered
						LSR			R0,R0,16			// shift right to capture lower middle bits in R0
						ORR			R0,R0,R1,LSL 16		// use ORR to capture upper middle bits in R0
						LDR			R1,=131072			// constant for FIXED(2.0)
						SUB			R6,R1,R0			// R6 -> temp = FIXED(2.0) - Q16Product(divisor, prev)
						SMULL		R0,R1,R6,R5			// R1.R0 -> Q16Product(temp, prev), centered
						LSR			R0,R0,16			// shift right to capture lower middle bits in R0
						ORR			R7,R0,R1,LSL 16		// use ORR to capture upper middle bits in R0
						SUB			R8,R7,R5			// R8 -> diff = curr - prev
						ADD			R0,R8,66			// R0 -> diff + FIXED(0.001)
						CMP			R0,132				// is R0 > 132?
						BLS			L2					// if no, then branch to L2 to exit the loop
						BL			L1					// else if yes, branch to L1 to keep looping
L2:						MOV			R0,R7				// upon exiting the loop, R0 -> curr
						POP			{R4,R5,R6,R7,R8,PC}	// restore LR,R4,R5,R6,R7,R8 and return
						.end
