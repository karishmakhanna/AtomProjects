// Vineet Joshi
// November 14, 2019
// zeller.s
// This is my starter code for Lab7a of COEN 20.

		.syntax		unified
		.cpu		cortex-m4
		.text
		
		.global		Zeller1
		.thumb_func
	// uint32_t Zeller1(uint32_t k, uint32_t m, uint32_t D, uint32_t C);
	// This function can use multiply and divide instructions.
	Zeller1:
		// TODO: Write your Assembly code for the 'Zeller1' function.
		
		.global		Zeller2
		.thumb_func
	// uint32_t Zeller2(uint32_t k, uint32_t m, uint32_t D, uint32_t C);
	// This function CANNOT use divide instructions (SDIV or UDIV).
	Zeller2:
		// TODO: Write your Assembly code for the 'Zeller2' function.
		
		.global		Zeller3
		.thumb_func
	// uint32_t Zeller3(uint32_t k, uint32_t m, uint32_t D, uint32_t C);
	// This function CANNOT use multiply instructions (MUL, MLS, etc.).
	Zeller3:
		// TODO: Write your Assembly code for the 'Zeller3' function.
		
		.end