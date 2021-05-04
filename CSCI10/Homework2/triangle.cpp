/*
triangle.cpp
csci10- section 01 -hw2

Created by Karishma Khanna on 10/02/18.
Pseudocode:
1. Get base and height from the user for the triangle.
2. Multiply the base and height.
3. Divide answer by 2.
4. Display area of triangle.


The program below calculates the area of a triangle.
*/

#include <iostream>
using namespace std;

int main() {
  // identifier declarations
  double h; //height
  double b; //base
  double area; //area

  //display prompts and get input
  cout<<"Enter the base: "<<endl;
  cin>>b;
  cout<<"Enter the height: "<<endl;
  cin>>h;

  //Calculate the area

  area= b*h*0.5; // The area of a triangle is 1/2 bh.

  //Display the area result
  cout<<"The area is "<<area<<" units squared."<<endl;

  return 0;
}
