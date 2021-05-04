/*
	This code was written to support the book, "ARM Assembly for Embedded Applications",
	by Daniel W. Lewis. Permission is granted to freely share this software provided
	that this notice is not removed. This software is intended to be used with a run-time
    library adapted by the author from the STM Cube Library for the 32F429IDISCOVERY
    board and available for download from http://www.engr.scu.edu/~dlewis/book3.
*/
				.syntax     unified
				.cpu        cortex-m4
				.text

// ----------------------------------------------------------
// void OffBy0(void *dst, const void *src)
// ----------------------------------------------------------

				.global			OffBy0
				.thumb_func
				.align
OffBy0:	// R0 = op1, R1 = op2 (copy 1000 bits)
				.rept 250
				LDR 				R2,[R1],4  // load data in src ptr to R2, shift src by 4 bytes
				STR 				R2,[R0],4  // load data in R2 to dst ptr, shift dst by 4 bytes
				.endr
				BX				  LR


// ----------------------------------------------------------
// void OffBy1(void *dst, const void *src)
// ----------------------------------------------------------

				.global			OffBy1
				.thumb_func
				.align
OffBy1:	// R0 = op1, R1 = op2 (copy 3+996+1 bits)
				.rept 3
				LDRB 				R2,[R1],1  // load data in src ptr to R2, shift src by 1 byte
				STRB 				R2,[R0],1  // load data in R2 to dst ptr, shift dst by 1 byte
				.endr
				.rept 249
				LDR 				R2,[R1],4  // load data in src ptr to R2, shift src by 4 bytes
				STR 				R2,[R0],4  // load data in R2 to dst ptr, shift dst by 4 bytes
				.endr
				LDRB 				R2,[R1],1  // load data in src ptr to R2, shift src by 1 byte
				STRB 				R2,[R0],1  // load data in R2 to dst ptr, shift dst by 1 byte
				BX				  LR


// ----------------------------------------------------------
// void OffBy2(void *dst, const void *src)
// ----------------------------------------------------------

				.global			OffBy2
        .thumb_func
        .align
OffBy2:	// R0 = op1, R1 = op2 (copy 2+996+2 bits)
				.rept 2
				LDRB 				R2,[R1],1  // load data in src ptr to R2, shift src by 1 byte
				STRB 				R2,[R0],1  // load data in R2 to dst ptr, shift dst by 1 byte
				.endr
				.rept 249
				LDR 				R2,[R1],4  // load data in src ptr to R2, shift src by 4 bytes
				STR 				R2,[R0],4  // load data in R2 to dst ptr, shift dst by 4 bytes
				.endr
				.rept 2
				LDRB 				R2,[R1],1  // load data in src ptr to R2, shift src by 1 byte
				STRB 				R2,[R0],1  // load data in R2 to dst ptr, shift dst by 1 byte
				.endr
				BX				  LR

// ----------------------------------------------------------
// void OffBy3(void *dst, const void *src)
// ----------------------------------------------------------

				.global			OffBy3
				.thumb_func
				.align
OffBy3:	// R0 = op1, R1 = op2 (copy 1+996+3 bits)
				LDRB				R2,[R1],1  // load data in src ptr to R2, shift src by 1 byte
				STRB 				R2,[R0],1  // load data in R2 to dst ptr, shift dst by 1 byte
				.rept 249
				LDR 				R2,[R1],4  // load data in src ptr to R2, shift src by 4 bytes
				STR 				R2,[R0],4  // load data in R2 to dst ptr, shift dst by 4 bytes
				.endr
				.rept 3
				LDRB 				R2,[R1],1  // load data in src ptr to R2, shift src by 1 byte
				STRB 				R2,[R0],1  // load data in R2 to dst ptr, shift dst by 1 byte
				.endr
				.end
