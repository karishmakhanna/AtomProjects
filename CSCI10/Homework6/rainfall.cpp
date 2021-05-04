/*
rainfall.cpp
csci10- section01-hw6

Created by Karishma Khanna on 10/30/18.

Using the inputs of rainfall (in inches) for each month in the year, this program will calculate and display the total rainfall for the year, the average monthly rainfall, and the months with the highest and lowest amounts of rainfall.

*/

#include <iostream>
#include <string>
using namespace std;

// declare all the functions used in this code
// four functions: find the total, finding the average, finding the month with highest rainfall, finding the month with lowest rainfall
double total(double a[], int size);
double avgrain(double a[], int size);
void highest(double a[], string months[], int size);
void lowest(double a[], string months[], int size);

// the total function will use formal parameters of the array of rainfall values, and the size of the array, so that we don't have to hardcode the size.
// setting a variable total to 0, we run the array through a for loop, and add the value at each cell to the total.
// return the total.
double total(double a[], int size) {
  double total=0;
  for (int i=0; i<size; i++) {
    total=total+a[i];
  }
  return total;
}

// the average function will use formal parameters of the array of rainfall values, and the size of the array, so that we don't have to hardcode the size.
// we can use the total function above to find the average.
// call the total function with the appropriate parameters, then define a variable average to be the total divided by the size, or number of elements in the array (12 months).
// return the average.
double avgrain(double a[], int size) {
  double sum=total(a, size);
  double average=sum/size;
  return average;
}

// the highest function will be a void funtion which doesn't return any value, but rather prints out the month(s) with the highest rainfall value.
// use formal parameters of the rainfall array, the months array, and the size of the arrays.
// set a value called highest as the first element of the rainfall array.
// using a for loop, check the rest of the elements in the array and if any of them are higher than highest, set highest to that value in the array.
// use another for loop to print the months which hold the highest value, even if there are more than one.
// to do this, check to see if highest equals each value in the rainfall array, and if it does, print out the element of the months array with the same index, along with highest.
void highest(double a[], string months[], int size) {
  double highest=a[0];
  for (int i=0; i<size; i++) {
    if (a[i]>=highest) {
      highest=a[i];
    }
  }
  for (int k=0; k<size; k++) {
    if (a[k]==highest) {
      cout<<months[k]<<" ("<<highest<<" inches)... ";
    }
  }
}

// the lowest function will be a void funtion which doesn't return any value, but rather prints out the month(s) with the lowest rainfall value.
// use formal parameters of the rainfall array, the months array, and the size of the arrays.
// set a value called lowest as the first element of the rainfall array.
// using a for loop, check the rest of the elements in the array and if any of them are lower than lowest, set lowest to that value in the array.
// use another for loop to print the months which hold the lowest value, even if there are more than one.
// to do this, check to see if lowest equals each value in the rainfall array, and if it does, print out the element of the months array with the same index, along with lowest.
void lowest(double a[], string months[], int size) {
  double lowest=a[0];
  for (int i=0; i<size; i++) {
    if (a[i]<=lowest) {
      lowest=a[i];
    }
  }
  for (int k=0; k<size; k++) {
    if (a[k]==lowest) {
      cout<<months[k]<<" ("<<lowest<<" inches)... ";
    }
  }
}

// this will be the main function to call the other functions
// declare an integer size equal to 12 (12 months).
// create a string array of all the months.
// declare a double array for rainfall with an index equal to the variable size.
// describe the program
// using a for loop, ask the user to enter 12 values into the rainfall array.
// proceed to call each of the four functions above.
// cout total and avgrain, and call the highest and lowest void functions on new lines.
int main() {
  int size=12;
  string months[]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  double rainfall[size];
  cout<<endl;
  cout<<"Using the inputs of rainfall (in inches) for each month in the year, this program will calculate and display the total rainfall for the year, the average monthly rainfall, and the months with the highest and lowest amounts of rainfall."<<endl;
  cout<<endl;
  for (int i=0; i<size; i++) {
    cout<<"Please enter the amount of rainfall for "<<months[i]<<" (in inches): ";
    cin>>rainfall[i];
  }
  cout<<endl;
  cout<<"Total Rainfall: "<<total(rainfall, size)<<" inches"<<endl;
  cout<<"Average monthly rainfall: "<<avgrain(rainfall, size)<<" inches/month"<<endl;
  cout<<"Highest rainfall: ";
  highest(rainfall, months, size);
  cout<<endl;
  cout<<"Lowest rainfall: ";
  lowest(rainfall, months, size);
  cout<<endl;
  cout<<endl;
  return 0;
}
