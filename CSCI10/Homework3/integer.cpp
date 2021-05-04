
/*
integer.cpp
csci10- section01-hw3

Created by Karishma Khanna on 10/08/18.

The program below allows you to enter an unspecified number of integers, and terminates with the input 0. Then, it lists how many positive and
negative values have been entered, the maximum and minimum values, the total, and the average of the input values (not counting the final 0), after each integer input.
*/


#include <iostream>
#include <cmath>
using namespace std;

int main() {
  // identifier declarations
  int positives=0;
  int negatives=0;
  int total=0;
  int i;
  double average=0;
  int minimum=2147483647; // max value for variable type int, anything less will be min
  int maximum=-2147483648; // min value for variable type int, anything more will be max

  // display problem
  cout<<"This program allows you to enter an unspecified number of integers, and terminates with the input of 0. After each input, it lists how many positive and negative values have been entered, the maximum and minimum values, the total, and the average of the inputted values (not counting the final 0)."<<endl;
  cout<<endl;

  // display prompt to get an initial integer from the user, in case the first input is 0, so that the program won't list the answers to the problem, and will terminate straight away
  cout<<"Enter an integer: ";
  cin>>i;
  cout<<endl;

  // initialize counter variables at 0

  // use a while loop to repeat integer input so long as i does not equal 0
  while (i!=0) {
    if (i>0) {
      positives=positives+1; // positives counter
    } else if (i<0){
      negatives=negatives+1; // negatives counter
      }
    total=total+i; // total counter
    average= 1.0*total/(positives+negatives); // total divided by total terms
    if(i >= maximum) {
      maximum = i;
        }
    if(i <= minimum) {
      minimum = i;
    }

    cout<<"Positives: "<<positives<<endl; // display positives
    cout<<"Negatives: "<<negatives<<endl; // display negatives
    cout<<"Total: "<<total<<endl; // display total
    cout<<"Average: "<<average<<endl; // display average
    cout<<"Minimum: "<<minimum<<endl; // display minimum
    cout<<"Maximum: "<<maximum<<endl; // display maximum
    cout<<endl;

    cout<<"Enter an integer: "; // ask for an integer at the end of the loop again
    cin>>i;
    cout<<endl;
  }

  return 0;
}
