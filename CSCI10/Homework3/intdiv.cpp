

/*
intdiv.cpp
csci10- section01-hw3

Created by Karishma Khanna on 10/08/18.

The program below divides integers a and b as a/b without using regular division or modular arithmetic. a MUST be an integer, but the divisor can be a decimal number if a is an integer.
*/



#include <iostream>
using namespace std;

int main() {

  int dividend, divisor, a, d=0; // the dividend is the number you are dividing, the divisor is the number you are dividing by, and d is the number of times the divisor goes into the dividend

  // display prompts and get user inputs
  cout<<endl;
  cout<<"Enter the dividend, or the integer you wish to divide (make sure it is an integer!): "<<endl;
  cin>>dividend;
  a=dividend; // a is included to take the place of the dividend once it changes

  cout<<endl;
  cout<<"Enter the divisor you wish to divide by (will truncate to lower integer): "<<endl;
  cin>>divisor;
  cout<<endl;

  // if the size of the divisor is greater than the size of the dividend, then the integer division will equal 0
  if (((a*a)<(divisor*divisor)) && a!=0) {
    cout<<a<<" / "<<divisor<<" = 0"<<endl;
  }
  // if the dividend and divisor are both nonzero
  if (dividend!=0 && divisor!=0) {
    // if both are negative or both are positive where the size of the divisor is less than the size of the dividend
    if ((a>=divisor && a>0 && divisor>0) || (a<=divisor && a<0 && divisor<0)) {
      while ((dividend>=divisor && dividend>0 && divisor>0) || (dividend<=divisor && dividend<0 && divisor<0)) {
        dividend=dividend-divisor;
        d++;
      }
      cout<<a<<" / "<<divisor<<" = "<<d<<endl; //display d, the times it divided
    // if one or the other is negative where the size of the divisor is less than the size of the dividend
    } else if ((a>=divisor && a>0 && divisor<0) || (a<=divisor && a<0 && divisor>0)) {
        while ((dividend>=divisor && dividend>0 && divisor<0) || (dividend<=divisor && dividend<0 && divisor>0)) {
          dividend=dividend+divisor;
          d++;
      }
      cout<<a<<" / "<<divisor<<" = "<<"-"<<d<<endl; // display d, the times it divided
      }
  // if the numerator is 0, the answer is 0
  } else if (a==0 && divisor!=0) {
      cout<<a<<" / "<<divisor<<" = 0"<<endl;
  // if the denominator is 0
  } else if (divisor==0 ) {
      cout<<"The divisor cannot equal a non-numerical value, nor 0, as division by 0 is undefined."<<endl;
  } else {
  // this part isn't really ever displayed, but it is there just in case
      cout<<"Please enter an integer."<<endl;
  }
  cout<<endl;
  return 0;
}
