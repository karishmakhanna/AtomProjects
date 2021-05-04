
/*
fraction.cpp
csci10- section01-hw8

Created by Karishma Khanna on 11/09/18.

PART A, first function:  This function will print a fraction.
PART B, second function: This function will multiply two fractions.
PART C, second function: This function will add two fractions.

The individual parts are listed below the blended code and are commented out.

*/


#include <iostream>
#include <string>
using namespace std;

// create a fraction structure with a numerator and a denominator
struct Fraction {
  int numerator;
  int denominator;
};

// declare functions being used in the program
void printFraction(Fraction f);
Fraction mult(Fraction f1, Fraction f2);
Fraction add(Fraction f1, Fraction f2);

// PART A: print function
// formal parameters: Fraction type variable
// prints the numerator/denominator
void printFraction(Fraction f) {
  cout<<f.numerator<<"/"<<f.denominator<<endl;
}

// PART B: multiply two fractions
// formal parameters: two Fraction type variables
// declare a new fraction variable to store the result
// multiplies the numerators of the fractions, becomes new fraction's numerator
// multiplies the denominators of the fractions, becomes new fraction's denominator
// return the newfraction variable
Fraction mult(Fraction f1, Fraction f2) {
  Fraction newfraction;
  newfraction.numerator=f1.numerator*f2.numerator;
  newfraction.denominator=f1.denominator*f2.denominator;
  return newfraction;
}

// PART C: add two fractions
// formal parameters: two Fraction type variables
// declare a new fraction variable to store the result
// cross multiplies the numerator of one fraction with the denominator of the other, add the results to become the new fraction's numerator
// multiplies the denominators of the fractions, becomes new fraction's denominator (unsimplified common denominator)
// return the newfraction variable
Fraction add(Fraction f1, Fraction f2) {
  Fraction newfraction;
  newfraction.numerator=(f1.numerator*f2.denominator)+(f2.numerator*f1.denominator);
  newfraction.denominator=f1.denominator*f2.denominator;
  return newfraction;
}

// main function to call parts A, B, and C
int main() {
  // declare variables being used
  Fraction f, f1, f2, f3, f4;
  cout<<endl;
  // state purpose of the program
  cout<<"This program will execute three functions: printing, multiplying, and adding fractions."<<endl;
  cout<<endl;
  // PART A: print fractions
  cout<<"The first program will execute a function to print a fraction."<<endl;
  cout<<endl;
  // user inputs
  cout<<"Enter the numerator of the fraction: ";
  cin>>f.numerator;
  cout<<"Enter the denominator of the fraction: ";
  cin>>f.denominator;
  // print result, call printFraction function
  cout<<"The fraction is: ";
  printFraction(f);
  cout<<endl;
  // PART B: multiply fractions
  cout<<"The second program will multiply two fractions and print the result."<<endl;
  cout<<endl;
  // user inputs
  cout<<"Enter the numerator of the first fraction: ";
  cin>>f1.numerator;
  cout<<"Enter the denominator of the first fraction: ";
  cin>>f1.denominator;
  cout<<"Enter the numerator of the second fraction: ";
  cin>>f2.numerator;
  cout<<"Enter the denominator of the second fraction: ";
  cin>>f2.denominator;
  // print result, call mult function
  cout<<"The multiplied fraction is: "<<mult(f1, f2).numerator<<"/"<<mult(f1, f2).denominator<<endl;
  cout<<endl;
  // PART C: add fractions
  cout<<"The third program will add two fractions and print the result."<<endl;
  cout<<endl;
  // user inputs
  cout<<"Enter the numerator of the first fraction: ";
  cin>>f3.numerator;
  cout<<"Enter the denominator of the first fraction: ";
  cin>>f3.denominator;
  cout<<"Enter the numerator of the second fraction: ";
  cin>>f4.numerator;
  cout<<"Enter the denominator of the second fraction: ";
  cin>>f4.denominator;
  // print result, call add function
  cout<<"The added fraction is: "<<add(f3, f4).numerator<<"/"<<add(f3, f4).denominator<<endl;
  cout<<endl;
  return 0;
}

/*
// PART A

#include <iostream>
#include <string>
using namespace std;

struct Fraction {
  int numerator;
  int denominator;
};

void printFraction(Fraction f) {
  cout<<f.numerator<<"/"<<f.denominator<<endl;
}

int main() {
  Fraction f;
  cout<<endl;
  cout<<"This program will execute a function to print a fraction."<<endl;
  cout<<endl;
  cout<<"Enter the numerator of the fraction: ";
  cin>>f.numerator;
  cout<<endl;
  cout<<"Enter the denominator of the fraction: ";
  cin>>f.denominator;
  cout<<endl;
  cout<<"The fraction is: ";
  printFraction(f);
  cout<<endl;
  return 0;
}

// PART B

#include <iostream>
#include <string>
using namespace std;

struct Fraction {
  int numerator;
  int denominator;
};

Fraction mult(Fraction f1, Fraction f2) {
  Fraction newfraction;
  newfraction.numerator=f1.numerator*f2.numerator;
  newfraction.denominator=f1.denominator*f2.denominator;
  return newfraction;
}

int main() {
  Fraction f1, f2;
  cout<<endl;
  cout<<"This program will multiply two fractions and print the result."<<endl;
  cout<<endl;
  cout<<"Enter the numerator of the first fraction: ";
  cin>>f1.numerator;
  cout<<"Enter the denominator of the first fraction: ";
  cin>>f1.denominator;
  cout<<endl;
  cout<<"Enter the numerator of the second fraction: ";
  cin>>f2.numerator;
  cout<<"Enter the denominator of the second fraction: ";
  cin>>f2.denominator;
  cout<<endl;
  cout<<"The multiplied fraction is: "<<mult(f1, f2).numerator<<"/"<<mult(f1, f2).denominator<<endl;
  cout<<endl;
  return 0;
}

// PART C

#include <iostream>
#include <string>
using namespace std;

struct Fraction {
  int numerator;
  int denominator;
};

Fraction add(Fraction f1, Fraction f2) {
  Fraction newfraction;

  newfraction.numerator=(f1.numerator*f2.denominator)+(f2.numerator*f1.denominator);
  newfraction.denominator=f1.denominator*f2.denominator;
  return newfraction;
}

int main() {
  Fraction f1, f2;
  cout<<endl;
  cout<<"This program will add two fractions and print the result."<<endl;
  cout<<endl;
  cout<<"Enter the numerator of the first fraction: ";
  cin>>f1.numerator;
  cout<<"Enter the denominator of the first fraction: ";
  cin>>f1.denominator;
  cout<<endl;
  cout<<"Enter the numerator of the second fraction: ";
  cin>>f2.numerator;
  cout<<"Enter the denominator of the second fraction: ";
  cin>>f2.denominator;
  cout<<endl;
  cout<<"The added fraction is: "<<add(f1, f2).numerator<<"/"<<add(f1, f2).denominator<<endl;
  cout<<endl;
  return 0;
}
*/
