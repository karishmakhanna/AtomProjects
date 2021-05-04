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

		// int Sum(int Ai, int Bi, Cin) ;
		.global		Sum1
		.thumb_func
		.align
		// Sum = Ai ^ Bi ^ Cin
Sum1:	EOR			R0,R0,R1			// R0 -> Ai^Bi
		EOR			R0,R0,R2			// R0 -> (Ai^Bi)^Cin
		BX			LR

		.global		Sum2
		.thumb_func
		.align
		// Sum = (Ai + Bi + Cin) & 1
Sum2:	ADD			R0,R0,R1			// R0 -> Ai+Bi
		ADD			R0,R0,R2			// R0 -> Ai+Bi+Cin
		AND			R0,R0,1				// R0 -> (Ai+Bi+Cin)&1
		BX			LR

		.global		Sum3
		.thumb_func
		.align
		// Sum = ((0b10010110 >> ((Cin << 2) | (Bi << 1) | Ai)) & 1
Sum3:	LSL			R2,R2,2				// R2 -> R2 << 2
		LSL			R1,R1,1				// R1 -> R1 << 1
		ORR			R2,R2,R1			// R2 -> (Cin << 2) | (Bi << 1)
		ORR			R2,R2,R0			// R2 -> (Cin << 2) | (Bi << 1) | Ai
		LDR			R1,=0b10010110		// R1 -> 0b10010110
		LSR			R0,R1,R2			// R0 -> 0b10010110 >> ((Cin << 2) | (Bi << 1) | Ai)
		AND			R0,R0,1				// R0 -> (0b10010110 >> ((Cin << 2) | (Bi << 1) | Ai)) & 1
		BX			LR

		.global		Sum4
		.thumb_func
		.align
		// Sum = sum[(Cin << 2) | (Bi << 1) | Ai)]
Sum4:	LSL			R2,R2,2				// R2 -> Cin << 2
		LSL			R1,R1,1				// R1 -> Bi << 1
		ORR			R2,R2,R1			// R2 -> (Cin << 2) | (Bi << 1)
		ORR			R2,R2,R0			// R2 -> (Cin << 2) | (Bi << 1) | Ai
		LDR			R0,=sum				// R0 -> &sum[0]
		LDRB		R0,[R0,R2]			// R0 -> sum[(Cin << 2) | (Bi << 1) | Ai)]
		BX			LR
sum:	.byte		0,1,1,0,1,0,0,1

		// int Cout(int Ai, int Bi, Cin) ;
		.global		Cout1
		.thumb_func
		.align
		// Cout = Ai&Bi | Ai&Cin | Bi&Cin
Cout1:	MOV			R3,R2				// R3 -> Cin
		AND			R2,R0,R1			// R2 -> Ai&Bi
		AND			R0,R0,R3			// R0 -> Ai&Cin
		AND			R1,R1,R3			// R1 -> Bi&Cin
		ORR			R0,R0,R1			// R0 -> Ai&Cin | Bi&Cin
		ORR			R0,R0,R2			// R2 -> Ai&Bi | Ai&Cin | Bi&Cin
		BX			LR

		.global		Cout2
		.thumb_func
		.align
		// Cout = (Ai + Bi + Cin) >> 1
Cout2:	ADD			R0,R0,R1			// R0 -> Ai+Bi
		ADD			R0,R0,R2			// R0 -> Ai+Bi+Cin
		LSR			R0,R0,1				// R0 -> (Ai+Bi+Cin) >> 1
		BX			LR

		.global		Cout3
		.thumb_func
		.align
		// Cout = ((0b11101000 >> ((Cin << 2) | (Bi << 1) | Ai)) & 1
Cout3:	LSL			R2,R2,2				// R2 -> R2 << 2
		LSL			R1,R1,1				// R1 -> R1 << 1
		ORR			R2,R2,R1			// R2 -> (Cin << 2) | (Bi << 1)
		ORR			R2,R2,R0			// R2 -> (Cin << 2) | (Bi << 1) | Ai
		LDR			R1,=0b11101000		// R1 -> 0b11101000
		LSR			R0,R1,R2			// R0 -> 0b11101000 >> ((Cin << 2) | (Bi << 1) | Ai)
		AND			R0,R0,1				// R0 -> (0b11101000 >> ((Cin << 2) | (Bi << 1) | Ai)) & 1
		BX			LR

		.global		Cout4
		.thumb_func
		.align
		// Cout = carry[(Cin << 2) | (Bi << 1) | Ai)]
Cout4:	LSL			R2,R2,2				// R2 -> Cin << 2
		LSL			R1,R1,1				// R1 -> Bi << 1
		ORR			R2,R2,R1			// R2 -> (Cin << 2) | (Bi << 1)
		ORR			R2,R2,R0			// R2 -> (Cin << 2) | (Bi << 1) | Ai
		LDR			R0,=carry			// R0 -> &carry[0]
		LDRB		R0,[R0,R2]			// R0 -> sum[(Cin << 2) | (Bi << 1) | Ai)]
		BX			LR
carry:	.byte		0,0,0,1,0,1,1,1
		BX			LR
		.end
