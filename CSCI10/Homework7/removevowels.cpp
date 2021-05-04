/*
removevowels.cpp
csci10- section01-hw7

Created by Karishma Khanna on 11/01/18.

This program will take a string, remove the vowels from it, and output the new string.

*/

#include <iostream>
#include <string>
using namespace std;

// declare the functions being used in this program.
string novowels(string input);

// define the function novowels.
// formal parameter will be input, the inputted string from main.
// declare an empty string variable output to hold the resulting string.
// write a for loop from index 0 to the last index of input.
// in the for loop, write an in statement to check for vowels.
// if the value of input at the current index is NOT a vowel, then add that value to the string output.
// return output.
string novowels(string input) {
  string output="";
  for (int i=0; i<input.length(); i++) {
    if (input[i] != 'a' && input[i] != 'e' && input[i] != 'i' && input[i] != 'o' && input[i] != 'u'
    && input[i] != 'A' && input[i] != 'E' && input[i] != 'I' && input[i] != 'O' && input[i] != 'U') {
        output+=input[i];
    }
  }
  return output;
}

// write the main function.
// declare a string s to hold the inputted string.
// decribe the purpose of the program.
// ask the user to input a string.
// input the string into s using getline so that it accepts a string even with spaces.
// Display the result with a statement followed by calling novowels using s.
int main() {
  string s;
  cout<<endl;
  cout<<"This program will take a string, remove the vowels from it (y is not a vowel here), and output the resulting string."<<endl;
  cout<<endl;
  cout<<"Please enter a string: ";
  getline(cin,s);
  cout<<endl;
  cout<<"The new string is: "<<novowels(s)<<endl;
  cout<<endl;
  return 0;
}
