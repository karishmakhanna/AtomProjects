	// (𝑢𝑛𝑠𝑖𝑔𝑛𝑒𝑑) (𝑣𝑎𝑙𝑢𝑒 – 𝑚𝑖𝑛) ≤ (𝑢𝑛𝑠𝑖𝑔𝑛𝑒𝑑) (𝑚𝑎𝑥 – 𝑚𝑖𝑛)
	// If this is true, then max>value, but also value>min
	// If value<min, then value-min is negative, which is greater than max-min unsigned
	// Between returns true (1) if 𝑚𝑖𝑛 ≤ 𝑣𝑎𝑙𝑢𝑒 ≤ 𝑚𝑎𝑥, and false (0) otherwise
	// Count returns integer from 0-𝑛𝑢𝑚𝑏 that is #elements in 𝑐𝑒𝑙𝑙𝑠 whose content equals 𝑣𝑎𝑙𝑢𝑒

						.syntax				unified
						.cpu				cortex-m4
						.text

	// --------------------------------------------------------------------
	// int32_t Between(int32_t min, int32_t value, int32_t max);
	// --------------------------------------------------------------------

						.global				Between
						.thumb_func
						.align
	Between:	// R0 = op1, R1 = op2, R2 = op3
						SUB					R1,R1,R0			// R1 <- value-min
						SUB					R2,R2,R0			// R2 <- max-min
						CMP					R1,R2				// Compares R1 and R2
						ITE					LS					// R1(unsigned) <= R2(unsigned)?
						LDRLS				R0,=1				// If yes, return 1
						LDRHI				R0,=0				// If no, return 0
						BX					LR

	// --------------------------------------------------------------------
	// int32_t Count(int32_t cells[], int32_t numb, int32_t value);
	// --------------------------------------------------------------------

						.global				Count
						.thumb_func
						.align
	Count:		// R0 = op1, R1 = op2, R2 = op3
						LDR					R3,=0				// R3 holds count, initialize to 0
						ADD					R1,R0,R1,LSL 2		// R1 <- Address of cells[numb]
	L1:					CMP					R1,R0				// Compares R1 and R0 (R1=R0?)
						BEQ					Done				// If R1=R0, go to Done (reached end)
						LDR					R12,[R0],4			// R12 <- cells[R0] and R0=R0+4
						CMP					R12,R2				// Compares R12 and R2
						IT					EQ					// cells[R12]==value?
						ADDEQ				R3,R3,1				// If yes, count++
						B					L1					// Repeat the loop with next array position
	Done:				MOV					R0,R3				// Return the value in R3
						BX					LR
						.end
