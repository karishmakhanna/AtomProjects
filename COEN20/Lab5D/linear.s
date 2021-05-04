	// W = tire width in millimeters
	// A = aspect ratio (an integer less than 100)
	// R = rim diameter in inches

						.syntax				unified
						.cpu				cortex-m4
						.text

	// --------------------------------------------------------------------
	// uint64_t TireDiam(uint32_t W, uint32_t A, uint32_t R);
	// --------------------------------------------------------------------

						.global				TireDiam
						.thumb_func
						.align
	TireDiam:	// R0 = op1, R1 = op2, R2 = op3
						MUL					R0,R0,R1		// R0 <- A*W (dividend)
						LDR					R3,=1270		// R3 <- 1270 (divisor)
						UDIV				R1,R0,R3		// R1 <- (A*W)/1270 (quotient)
						MLS					R0,R1,R3,R0		// R0 <- A*W - [(A*W)/1270]*1270 (remainder)
						ADD					R1,R1,R2		// R1 <- (A*W)/1270 + R
						BX					LR				// R0 has remainder, R1 has integer part

	// --------------------------------------------------------------------
	// uint64_t TireCirc(uint32_t W, uint32_t A, uint32_t R);
	// --------------------------------------------------------------------

						.global				TireCirc
						.thumb_func
						.align
	TireCirc:	// R0 = op1, R1 = op2, R2 = op3
						PUSH				{LR}
						BL					TireDiam		// R0=remainder, R1=integer part, R2=R
						LDR					R3,=3927		// R3 <- 3927 (R0 multiplier)
						MUL					R0,R0,R3		// R0 <- remainder*3927
						LDR					R3,=4987290		// R3 <- 4987290 (R1 multiplier)
						MUL					R1,R1,R3		// R1 <- integer part*4987290
						ADD					R0,R0,R1		// R0 <- numerator (dividend)
						LDR					R3,=1587500		// R3 <- 1587500 (divisor)
						UDIV				R1,R0,R3		// R1 <- numerator/divisor (quotient)
						MLS					R0,R1,R3,R0		// R0 <- dividend - quotient*divisor (remainder)
						POP					{PC}			// R0 has remainder, R1 has integer part
						.end
