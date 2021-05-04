/*
digcharstr.cpp
csci10- section01-hw7

Created by Karishma Khanna on 11/01/18.

PART A, first function: The function in this program will test if a character is a digit or not.
PART B, second function: The function in this program will return the number version of a character if it is a digit and -1 if it isn't.
PART C, third function: The function in this program will return the number version of a string if it composed of digits and -1 if it isn't.

*/

// MAIN TO TEST EVERYTHING!

#include <iostream>
#include <string>
using namespace std;

// declare all the functions being used in this program.
int c_to_digit(char c);
bool isdigit(char c);
int pow(int n, int ex);
int s_to_digit(string s);

// define a function c_to_digit to change a character into a digit.
// formal parameter will be a character c.
// write an if statement calling isdigit(c) in the argument.
// if c is a digit, then return c-'0', else return -1 (directions for this function).
// since the retun type is int, it will return the ASCII integer of c, minus the ASCII integer of '0', which will "convert" a digit character into its integer digit.
int c_to_digit(char c) {
  if (isdigit(c)) {
    return c-'0'; // returns the digit using ASCII integer values
  } else {
    return -1; // returns -1 if not a digit
    }
}

// write a function isdigit to check if a character is a digit.
// formal parameter will be a character c.
// in the function, declare a string variable called digits to the digits "0123456789".
// write a for loop from index 0 to the last index of the digits string.
// at each location in digits, check to see if the character c is a digit.
// if the character c equals digit at some index in the for loop, return true within the loop.
// return false if there is no match.
bool isdigit(char c) {
  string digits="0123456789";
  for (int i=0; i<digits.length(); i++) {
    if (c==digits[i]) {
      return true; // true if the character is a digit at any point in the digit string
    }
  }
  return false; // false if true is never returned
}

// write a function pow, a power function, taken from the directions.
// formal parameters will be a base integer n and an exponent integer ex.
// set an integer ret, the return variable to 1.
// write a for loop from index 0 to less than ex that keeps resetting ret to ret*n.
// this multiplies n by itself ex times.
// if ex=0, and the program cannot enter the for loop, the answer will still be right since anything to thr 0th power equals 1.
// return ret.
int pow(int n, int ex) {
  int ret = 1;
  for(int i=0; i<ex; i++) {
    ret = ret*n; // multiplies n by itself ex times through repetition of this equation
  }
  return ret; // returns result
}

// write a function s_to_digit which changes a string of digits to its digit form.
// formal parameter will be string s.
// declare an integer number, the return variable, to 0, since it will hold partial sums from later operations.
// write a for loop from the length of s to 0, decrementing the index each time (starts from "ones value" and goes to the next higher "place value" in the digits string).
// in the argument of an if statment, call isdigit.
// if isdigit returns true, then proceed to construct the number.
// we first have to find the digit which s[i] corresponds to using ASCII integer subtraction (s[i]-'0'), which the program will recognize since number must equal an integer.
// multiply this digit result by the corresponding "place value" of 10, found using the power function pow with the inputs of 10 (base) and (s.length()-1-i) (exponent).
// s.length()-1-i means that the first place value at i-s.length()-1 will be exponent 0, or the "ones place", and as i decrememnts, this will increase to 1 ("tens place"), 2 ("hundreds place"), etc.
// add the result of the digit times the "place value" to number until the for loop is done.
// return number.
int s_to_digit(string s) {
  int number=0;
  for (int i=s.length()-1; i>=0; i--) {
    if(isdigit(s[i])) {
      number=number+((s[i]-'0')*pow(10, s.length()-1-i));
    } else {
        return -1; // returns -1 if false at any point (as per stated in the directions)
      }
  }
  return number; // returns result
}

// write the main function.
// declare two test character variables, c1 and c2, one for function 1, one for function 2.
// declare a test string variable for function 3.
// test each function.
// at the end, print end of program.
int main() {
  char c1;
  char c2;
  string s;
  cout<<endl;
  // state the purpose of the first program.
  // ask the user to enter a character.
  // enter the input into c1.
  // calling isdigit in the argument of an if statement, if isdigit returns true, then print a message saying c1 is a digit.
  // else, if isdigit returns false, then print a message saying c1 is not a digit.
  cout<<"The first function in this program will test if a character is a digit or not."<<endl;
  cout<<endl;
  cout<<"Please enter a SINGLE character: ";
  cin>>c1;
  cout<<endl;
  if (isdigit(c1)) {
    cout<<"The character "<<c1<<" is a digit!"<<endl;
  } else {
    cout<<"The character "<<c1<<" is NOT a digit!"<<endl;
  }
  cout<<endl;
  // state the purpose of the second program.
  // ask the user to enter a character.
  // enter the input into c2.
  // Print "Return: ", then call c_to_digit to print its result.
  // if c2 was a digit, it will print the digit, and if not, it will print -1.
  cout<<"The second function in this program will return the number version of a character if it is a digit and -1 if it isn't."<<endl;
  cout<<endl;
  cout<<"Please enter a SINGLE character: ";
  cin>>c2;
  cout<<endl;
  cout<<"Return: "<<c_to_digit(c2)<<endl;
  cout<<endl;
  // state the purpose of the third program,
  // ask the user to enter a string.
  // enter the input into s.
  // Print "Return: ", then call s_to_digit to print its result.
  // if s was a string of digits, it will print the digit version of s, and if not, it will print -1.
  cout<<"The third function in this program will return the number version of a string if it is composed of digits and -1 if it isn't."<<endl;
  cout<<endl;
  cout<<"Please enter a string: ";
  cin>>s;
  cout<<endl;
  cout<<"Return: "<<s_to_digit(s)<<endl;
  cout<<endl;
  cout<<"End of program."<<endl;
  cout<<endl;
  return 0;
}
