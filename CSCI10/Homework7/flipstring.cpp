/*
flipstring.cpp
csci10- section01-hw7

Created by Karishma Khanna on 11/01/18.

This program will take a string input and output the reverse of it.

*/


#include <iostream>
#include <string>
using namespace std;

// declare and define a string function reverse to flip a string.
// use formal parameter input, which will be the inputted string from main.
// inside the function, declare a variable output to hold the result.
// write a for loop from the last index of the input, decrementing to index 0.
// in the for loop, add the value of input at each index to output.
// return output.
string reverse(string input) {
  string output;
  for (int i=input.length()-1; i>=0; i--) {
    output+=input[i];
  }
  return output;
}

// write the main function
// declare a string s to hold an inputted string.
// decribe the purpose of the program.
// ask the user to enter a string.
// use getline to input the string, even if the string has spaces.
// output the result with a statement followed by calling the reverse function with s.
int main() {
  string s;
  cout<<endl;
  cout<<"This program will take a string input and output the reverse of it."<<endl;
  cout<<endl;
  cout<<"Please enter a string: ";
  getline(cin,s);
  cout<<endl;
  cout<<"The reverse of the string is: "<<reverse(s)<<endl;
  cout<<endl;
  return 0;
}
