/*
	This code was written to support the book, "ARM Assembly for Embedded Applications",
	by Daniel W. Lewis. Permission is granted to freely share this software provided
	that this notice is not removed. This software is intended to be used with a run-time
    library adapted by the author from the STM Cube Library for the 32F429IDISCOVERY
    board and available for download from http://www.engr.scu.edu/~dlewis/book3.
*/

#include <stdint.h>
//convert the array of bits to unsigned bit
uint32_t Bits2Unsigned(int8_t bits[8]){
		// To be implemented by student
		// Input:	bits[0] = Least significant bit
		//			bits[7] = Most significant bit
		// Output:	0 <= return value < 255
		int i, n;
		n=0;
		for(int i=7;i>=0;i--){//decrementing through the array
				n=2*n+bits[i];//calculation from bits to int
		}
		return n;// value of the converted Unsigned int
}
//convert the array of bits to a signed int
int32_t Bits2Signed(int8_t bits[8]){
		// To be implemented by student
		// Input:	bits[0] = Least significant bit
		//			bits[7] = Most significant bit
		// Output: -128 <= return value <= +127
		int32_t n= (int32_t)Bits2Unsigned(bits);//calling Bits2Unsigned function with 32bit conversion
		if(n>127){
			n=n-256;//calculation for signed int due to number range
		}
	return n;// return value of converted signed int
}

void Increment(int8_t bits[8]){
		// To be implemented by student
		// Adds 1 to the number represented by bits
		// Where:	bits[0] = Least significant bit
		//			bits[7] = Most significant bit
		int i;
		for(i=0;i<=7;i++){//Incrementing through the bit array
				if(bits[i]==0){
					bits[i]=1;//setting the bit to 1 if the bit is 0
					break;
				}
				else{
					bits[i]=0;// setting the bit 0 if the bit is 1				
				}
		}
}
//opposite of the first function
void Unsigned2Bits(uint32_t n, int8_t bits[8]){
		// To be implemented by student
		// Input:	0 <= n <= 255
		// Output:	Converts n to an array of bits
		// Where:	bits[0] = Least significant bit
		// 			bits[7] = Most significant bit
		int j;
		for(j=0;j<=7;j++){//incrementing through the array
				if(n%2==0){
					bits[j]=0;//setting the bit value to 0 if the remainder of n/2 is 0
				}
				else{
					bits[j]=1;//setting the bit value to 1
				}
				n=n/2;//updating the value of n again
		}
}
