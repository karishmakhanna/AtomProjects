

/*
printpattern.cpp
csci10- section01-hw4

Created by Karishma Khanna on 10/16/18.

The program below prints a pyramid of n rows of any character c.
Example:       *
             * * *
           * * * * *
if n=3 and c=*
*/



#include <iostream>
using namespace std;

// void function called pyramid (declaration and function) which takes an input of n rows and a character c
void printPattern(int n, char c) {
  int s; // s is the number of spaces before c print on each row of the pyramid
  s=2+4*n; // this gurantees space for the next lines
  // outer for loop to deal with the number of rown in the pyramid
  for (int i=0; i<n; i++) {
    // first inner for loop which deals with the spaces s before printing out c
    for (int j=0; j<s; j++) {
      cout <<" ";
    }
    s = s - 2; // each subsequent line has one less space, since the base of the pyramid gets wider
    // second inner for loop which prints c where the number of prints equals the number of rows

    for (int k=0; k<(-1+2*(i+1)); k++ ) {
      cout<<c<<" "; // print c wiht a space after it
    }
    cout << endl; // create a new row
}
}

// main function
int main() {
  // identifier declarations, variables c for character and n for rows
  char c;
  int n;
  // user input prompts
  cout<<endl;
  cout<<"Enter the character you would like to construct a pyramid with: "<<endl;
  cin>>c;
  cout<<endl;
  cout<<"How many rows does your pyramid have? "<<endl;
  cin>>n;
  cout<<endl;
  // run the pyramid program to print the result
  printPattern(n,c);
  cout<<endl;
  return 0;
}
