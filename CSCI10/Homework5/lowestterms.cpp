
/*
lowestterms.cpp
csci10- section01-hw5

Created by Karishma Khanna on 10/20/18.

The program below reduces positive fractions to their lowest terms.
*/

#include <iostream>
using namespace std;

// declare functions, one for checking denominator equal to zero, and one for converting to lowest terms
bool dividebyzero(int denominator);
void ConvertToLowestTerms(int &numerator, int &denominator);

// main function
int main() {
  // declare variables, numerator, denominator, and "good" to hold T/F
  int num, den;
  bool good;
  cout<<endl;
  // display program description
  cout<<"This program will simplify a positive fraction into its lowest terms."<<endl;
  // display user prompts to enter a numerator and a denominator
  cout<<"Please enter a positive numerator and a positive denominator for your fraction."<<endl;
  cout<<endl;
  cout<<"NUMERATOR: ";
  cin>>num;
  cout<<"DENOMINATOR: ";
  cin>>den;
  cout<<endl;
  // call the function dividebyzero to prevent the denominator from equalling zero (see function)
  good=dividebyzero(den);
  // if the denominator equals zero, and good is false, the function will stop
  // if the denominator does not equal zero, and good is true, it will run the lowest terms function and display the result (see function)
  if (good) {
    ConvertToLowestTerms(num, den);
    cout<<"The lowest terms for reducing the fraction are: "<<num<<"/"<<den<<endl;
  }
  cout<<endl;
  return(0);
}

// this function returns false and a statement if the denominator equals zero, and true if it does not
bool dividebyzero(int denominator) {
  if (denominator==0) {
    cout<<"The denominator cannot equal zero. Please run the program again with a valid denominator."<<endl;
    return false; // false means the function will end
  } else {
    return true; // true means the function will continue
  }
}

// this function converts fraction to their lowest terms
// it checks to see if both numbers can be divided by any integer the smaller integer to 1 in the fraction
// it uses call by reference (CBR) to change the numerator and denominator in the main function once simplified here
void ConvertToLowestTerms(int &numerator, int &denominator) {
  int lower, higher;
  // determine if the numerator or the denominator is the smaller integer
  if (numerator<denominator) {
    lower=numerator;
    higher=denominator;
  } else {
    lower=denominator;
    higher=numerator;
  }
  // test to see what integers from the smaller integer to 1 divide the numerator AND denominator BOTH
  // if there is an integer i that divides both, the numerator and denominator will be divided by i and be redeclared
  for (int i=lower; i>0; i--) {
    if (numerator%i==0 && denominator%i==0) {
      numerator=numerator/i;
      denominator=denominator/i;
    }
  }
}
