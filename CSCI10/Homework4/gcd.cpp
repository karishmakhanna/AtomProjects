

/*
gcd.cpp
csci10- section01-hw4

Created by Karishma Khanna on 10/16/18.

The program below computes the greatest common denominator/divisor (GCD) between any two integers.
*/

#include<iostream>
#include<cmath> // in order to use abs() function
using namespace std;

// void function to calculate gcd between any integers x and y
void gcd(int x, int y) {
  int GCD; // identifier declaration for GCD variable
  // 0 and 0 have no GCD
  if (x==0 && y==0) {
    cout<<"Undefined GCD. All integers besides 0 are common divisors of 0 and 0, so there is no greatest divisor."<<endl; // print GCD result
    cout<<endl;
    // the GCD of any y and 0 is y, since all integers divide 0
  } else if (x==0 && y!=0) {
    cout<<"The GCD of "<<x<<" and "<<y<<" is "<<y<<"."<<endl; // print GCD result
    cout<<endl;
    // the GCD of any x and 0 is x, since all integers divide 0
    } else if (x!=0 && y==0) {
      cout<<"The GCD of "<<x<<" and "<<y<<" is "<<x<<"."<<endl; // print GCD result
      cout<<endl;
      // calculates the GCD between any integers
      // negative integers still work - signs do not matter since if a is a factor of x, so is -a, yet a (the positive factor), will always be greater anyways
      } else if (x!=0 && y!=0) {
        for (int i=1; i<=abs(x) && i<=abs(y); i++) {
          if (x%i==0 && y%i==0) {
            GCD=i;
          }
        }
        cout<<"The GCD of "<<x<<" and "<<y<<" is "<<GCD<<"."<<endl; // print GCD result
        cout<<endl;
        }
}

// main function
int main() {
  // identifier declarations
  int n1, n2; // n1 is number 1 and n2 is number 2
  // user input prompts
  cout<<endl;
  cout<<"This program will calculate the GCD (greatest common divisor) of any two integers."<<endl;
  cout<<endl;
  cout<<"Enter the first number: "<<endl;
  cin>>n1;
  cout<<endl;
  cout<<"Enter the second number: "<<endl;
  cin>>n2;
  cout<<endl;
  // run the gcd() function and print its result
  gcd(n1, n2);
  return 0;
}
