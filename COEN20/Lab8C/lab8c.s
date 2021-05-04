/*
	This code was written to support the Tuesday book, "ARM Assembly for Embedded Applications",
	by Daniel W. Lewis. Permission is granted to freely share this software provided
	that this notice is not removed. This software is intended to be used with a run-time
	library adapted by the author from the STM Cube Library for the 32F429IDISCOVERY
	board and available for download from http://www.engr.scu.edu/~dlewis/book3.
*/
		.syntax     unified
		.cpu        cortex-m4
		.text

		// uint32_t Mul32X10(uint32_t multiplicand) ;
		.global		Mul32X10
		.thumb_func
		.align
Mul32X10:			// R0 = multiplicand
		ADD			R1,R0,R0,LSL 2	// R1=R0+(R0<<2)=R0+4*R0=5*R0
		LSL			R0,R1,1			// R0=(R1<<1)=10*R0
		BX			LR

		// uint32_t Mul64X10(uint64_t multiplicand) ;
		.global		Mul64X10
		.thumb_func
		.align
Mul64X10:			// R1.R0 = multiplicand
		MOV			R2,R0			// R2=R0
		MOV			R3,R1			// R3=R1 (now R3.R2=R1.R0)
		LSL			R1,R1,3			// R1=(R1<<3)
		ADD			R1,R1,R0,LSR 29	// R1=R1+(R0<<29)
		LSL			R0,R0,3			// R0=(R0<<3) (now R1.R0=8*R1.R0)
		LSL			R3,R3,1			// R3=(R3<<1)
		ADD			R3,R3,R2,LSR 31	// R3=R3+(R2<<31)
		LSL			R2,R2,1			// R2=(R2<<1) (now R3.R2=2*R1.R0)
		ADDS		R0,R0,R2		// R0=R0+R2 (least significant half)
		ADC			R1,R1,R3		// R1=R1+R3+carry (most significant half)
		BX			LR

		// uint32_t Div32X10(uint32_t dividend) ;
		.global		Div32X10
		.thumb_func
		.align
Div32X10:			// R0 = dividend
		LDR			R1,=3435973837	// constant = (2^35+2)/10 = 3435973837
		UMULL		R2,R1,R1,R0		// R1.R2 = (64-bit) R0*R1
		LSR			R0,R1,3			// R0=(R1>>3) to adjust the 2^35 effect
		BX			LR
		.end
