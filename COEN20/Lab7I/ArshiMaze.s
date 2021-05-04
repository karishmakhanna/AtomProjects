			.syntax     unified
			.cpu        cortex-m4
			.text
			.global		GetNibble
			.thumb_func
			.align
			// uint32_t GetNibble(void *nibbles, uint32_t index) ;
GetNibble:
			LSRS		R1,R1,1
			ADD 		R0,R0,R1
			LDRB 		R3,[R0]

			//CS= carry set( unsigned>=), CC=carry clear(unsigne <)
			ITE 		CC
			UBFXCC 	R0,R3,0,4		//R0 <-SelectedBitfieldOf(R3),0
			UBFXCS 	R0,R3,4,4		//R0 <-SelectedBitfieldOf(R3),4

			BX 			LR

			// void PutNibble(void *nibbles, uint32_t index, uint32_t nibble) ;
			.global		PutNibble
			.thumb_func
			.align
PutNibble:
			LSRS		R1,R1,1
			ADD 		R0,R0,R1
			LDRB 		R3,[R0]

			//CS= carry set( unsigned>=), CC=carry clear(unsigned <)
			ITE 		CC
			BFICC 	R3,R2,0,4		//SelectedBitfieldOf(R3)<- LSBitsOf(R2), 0
			BFICS 	R3,R2,4,4		//SelectedBitfieldOf(R3)<- LSBitsOf(R2), 4

			STRB 		R3,[R0]

			BX			LR
			.end
