
//Arshi Saxena
//October 15, 2020
//Lab2a

.syntax     unified
.cpu        cortex-m4
.text

// int32_t Add(int32_t a, int32_t b) ;
.global		Add
.thumb_func
.align

Add:				//R0=a,R1=b
		ADD			R0,R0,R1
		BX			LR


// int32_t Less1(int32_t a) ;
.global		Less1
.thumb_func
.align

Less1: 			//R0=a
		SUB 		R0,R0,1 	//R0=a-1
		BX			LR

// int32_t Square2x(int32_t x) ;
.global		Square2x
.thumb_func
.align

Square2x:
		ADD			R0,R0,R0 //R0=2x
		B			Square 		//square (x+x)

// int32_t Last(int32_t x) ;
.global		Last
.thumb_func
.align

Last:
		PUSH		{R4,LR}		//preserve R1-R3, LR
		MOV			R4,R0			//R4 copy of x
		BL			SquareRoot		//Sqrt(x)
		ADD			R0,R4,R0		//R3=x+Sqrt(x)
		POP			{R4,PC}
		.end
