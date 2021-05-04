

/*
reverse.cpp
csci10- section01-hw4

Created by Karishma Khanna on 10/16/18.

The program below reverses digits in their parameter and returns the result.
*/

#include <iostream>
using namespace std;

// function declaration for the reverse function
int reverse(int n);

// main function
int main() {
  int n; // n is the integer whose digits the program will reverse
  cout<<endl;
  // describe problem
  cout<<"This program will take any nonnegative integer and print its digits in reverse. It will run this function for 10 numbers total."<<endl;
  cout<<endl;
  // for loop to enter 10 integers and display the reverse of each of them
  for (int i=0; i<10; i++) {
    cout<<"Enter a nonnegative integer (max 9 digits): "<<endl;
    cin>>n;
    // make sure the number inputted is not negative
    while (n<0) {
      cout<<endl;
      cout<<"Enter a nonnegative integer (max 9 digits): "<<endl;
      cin>>n;
    }
    cout<<endl;
    // call reverse function for each inputted n, display results from this function
    cout<<"The reverse of this integer is: "<<reverse(n)<<endl;
    cout<<endl;
  }
  return 0;
}

// reverse function, return the reverse integer
int reverse(int n) {
  int rev=0; // initializing rev to 0 allows rev to be 0 when n equals 0, and for the while loop to end at the correct spot
  while (n>0) {
    rev=rev*10+n%10; // we multiply rev by 10 to create a 0 placeholder at the end of the number, where we then add the digit (0-9, which is why we divide by mod 10) we are starting with from n to rev
    n=n/10; // dividing n by 10 truncates the last digit off of n since this is integer division - it lets us repeat the modular division of n to add the ones place digit to an added placeholder in rev
  }
  return rev; // this process ends up listing the digits of n in reverse order as desired
}
