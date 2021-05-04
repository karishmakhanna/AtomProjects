		.syntax     unified
		.cpu        cortex-m4
		.text

		// void UseLDRB(void *dst, void *src) ;
		.global		UseLDRB
		.thumb_func
		.align
UseLDRB:
		.rept 512
		LDRB R2, [R1], 1  // R2 <- dereference of src move to next byte
		STRB R2, [R0],1		// R2 contents-> dereference of dst
		.endr
		BX LR

		// void UseLDRH(void *dst, void *src) ;
		.global		UseLDRH
		.thumb_func
		.align
UseLDRH:
		.rept 256
		LDRH R2, [R1] ,2  //R2 <- dereference of src move to 2 bytes
		STRH R2, [R0] ,2  // R2 contents-> dereference of dst
		.endr
		BX LR
		// void UseLDR(void *dst, void *src) ;
		.global		UseLDR
		.thumb_func
		.align
UseLDR:
		.rept 128
		LDR R2, [R1] ,4  //R2 <-dereference src and move to next 4 bytes
		STR R2, [R0] ,4  // R2 contents ->dereference of dst
		.endr
		BX LR

		// void UseLDRD(void *dst, void *src) ;

		.global		UseLDRD
		.thumb_func
		.align
UseLDRD:
		.rept 64
		LDRD R2, [R1] ,8  //R2<- dereference of src, move to next 8 bytes
		STRD R2, [R0] ,8 // R2 contents-> dereference of dst
		.endr
		BX LR

		// void UseLDMIA(void *dst, void *src) ;
		.global		UseLDM
		.thumb_func
		.align
UseLDM:
		PUSH {R4-R11}
		.rept 16
		LDMIA R0!,{R4-R11}   //copying R1 into R4-R11
		STMIA R1!,{R4-R11}   //storing R2-R4 to dereference of R0 increment
		.endr
		POP {R4-R11}
		BX LR
		.end
