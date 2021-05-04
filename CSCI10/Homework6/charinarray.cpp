/*
charinarray.cpp
csci10- section01-hw6

Created by Karishma Khanna on 10/29/18.

This program will check to see if a certain character is present in a predetermined array of characters.

*/

#include <iostream>
using namespace std;

// declare the bool function search_char.
bool search_char(char characters[], int size, char c);

// define the bool function search_char.
// use the formal parameters of a characters array, the size of the array so that it doesn't have to be hardcoded into the function, and any single character c.
// we are checking to see if the character c is present in the character array.
// to check this, use a for loop to check each element of the characters array to see if it equals c.
// if it does equal c, as in c is present in the array, return 1 (true), and if not return 0 (false).
bool search_char(char characters[], int size, char c) {
  for (int i=0; i<size; i++) {
    if (characters[i]==c) {
      return 1;
    }
  }
  return 0;
}

// this is the main function where we will call the function search_char.
// declare an integer size, which can be any number you want.
// declare and populate an array of characters with the number of elements in it equal to size.
// declare a character variable c.
// describe the program.
// ask for user input for c, which is the character the program will check the array for.
// call the function search_char in an if statement.
// basically, if true (1), the program will print "The character is found!".
// if false (0), the program will print "The character is not found!".
int main() {
  int size=11;
  char characters[]={'f', 'n', 's', 't', 'l', 'k', 'b', 'x', 'o', 'q', 'm'};
  char c;
  cout<<endl;
  cout<<"This program will check to see if a certain character is present in a predetermined array of characters."<<endl;
  cout<<endl;
  cout<<"Please enter a character to check for: ";
  cin>>c;
  cout<<endl;
  if (search_char(characters, size, c)) {
    cout<<"The character "<<c<<" is found in the array!"<<endl;
  } else {
    cout<<"The character "<<c<<" is NOT found in the array!"<<endl;
  }
  cout<<endl;
  return 0;
}
