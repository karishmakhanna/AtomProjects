// each array parameter holds an 8-bit binary number, 𝑏7𝑏6𝑏5𝑏4𝑏3𝑏2𝑏1𝑏0,
// where bits[7] = 𝑏7 and bits[0] = 𝑏0.
// range for signed 8-bit: -128 to 127
// range for unsigned 8-bit: 0 to 255

/*
	This code was written to support the book, "ARM Assembly for Embedded Applications",
	by Daniel W. Lewis. Permission is granted to freely share this software provided
	that this notice is not removed. This software is intended to be used with a run-time
	library adapted by the author from the STM Cube Library for the 32F429IDISCOVERY
	board and available for download from http://www.engr.scu.edu/~dlewis/book3.
*/

#include <stdint.h>

int32_t Bits2Signed(int8_t bits[8]) ; // Convert array of bits to signed int.
uint32_t Bits2Unsigned(int8_t bits[8]) ; // Convert array of bits to unsigned int
void Increment(int8_t bits[8]) ; // Add 1 to value represented by bit pattern
void Unsigned2Bits(uint32_t n, int8_t bits[8]) ; // Opposite of Bits2Unsigned

uint32_t Bits2Unsigned(int8_t bits[8]){
  // To be implemented by student
	// Input:	bits[0] = Least significant bit
	//        bits[7] = Most significant bit
	// Output:	0 <= return value < 255
  uint32_t value=0; // the running decimal sun to be returned at the end (initially 0)
	for(int i=7; i>=0; i--) { // traverse through bit array from right to left
    value=2*value+bits[i]; // way to compute a running decimal sum from binary (taken from lab sheet)
	}
	return value; // return unsigned decimal value
}

int32_t Bits2Signed(int8_t bits[8]){
  // To be implemented by student
	// Input:	bits[0] = Least significant bit
	//        bits[7] = Most significant bit
	// Output: -128 <= return value <= +127
	int32_t value=(int32_t)Bits2Unsigned(bits); // first return an unsigned decimal value
  // use typecast to return the correct type
  // that value will be between 0 to 255
  if(value>127) { // don't change values 0 to 127
    value=value-256; // want to shift 128 to 255 -> (-128) to (-1) to create a loop for signed numbers
  }
	return value ; // return signed decimal value
}

void Increment(int8_t bits[8]){
	// To be implemented by student
	// Adds 1 to the number represented by bits
	// Where:	bits[0] = Least significant bit
	//			bits[7] = Most significant bit
  // Note: [11111111]+1=[00000000]
	for(int i=0; i<=7; i++) { // traverse through bit array from left to right
			if(bits[i]==0) {
				bits[i]=1; // change the first most significant 0 seen to a 1
				break; // terminate the if-else function after this
			}
			else {
				bits[i]=0; // until the first most significant 0 is seen, flip all 1's to 0's
			}
	}
}

void Unsigned2Bits(uint32_t n, int8_t bits[8]){
	// To be implemented by student
	// Input:	0 <= n <= 255
	// Output:	Converts n to an array of bits
	// Where:	bits[0] = Least significant bit
	//        bits[7] = Most significant bit
	for(int i=0; i<=7; i++) { // traverse through bit array from left to right
		if(n%2==0) {
			bits[i]=0; // set the bit value to 0 if the remainder of n%2 is 0
		}
		else {
			bits[i]=1; // else, if the remainder of n%2 is 1, set the bit value to 1
		}
		n=n/2; // update the value of n with n/2 to analyze the next significant place value in the next iteration
	}
}
