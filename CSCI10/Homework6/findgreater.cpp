/*
findgreater.cpp
csci10- section01-hw6

Created by Karishma Khanna on 10/31/18.

Using any user inputted integer, this program will display all the values from a predetermined array of integers which are larger than that number.

*/

#include <iostream>
using namespace std;

// declare the find_greater function.
void find_greater(int a[], int size, int n);

// define the void find_greater function.
// use formal parameters of the array of integers, the size of the array so it doesn't need to be hardcoded inside the function, and the integer n being used for comparison.
// use a cout statement saying that the following integers are all higher than the integer being used for comparison.
// use a for loop to print these integers by checking each element in the numbers array to see if it is greater than n.
void find_greater(int a[], int size, int n) {
  cout<<"Numbers in the array greater than "<<n<<": ";
  for (int i=0; i<size; i++) {
    if (a[i]>n) {
      cout<<a[i]<<" ";
    }
  }
  cout<<endl;
}

// this is the main function, which will call find_greater.
// declare a variable size, and set it equal to any integer.
// declare a numbers array, and enter integer values into it (enter as many values as size).
// declare an integer n.
// decribe the program.
// ask for user input for n (n will be the integer for which elements of the array must be greater than).
// call the find_greater function, inputting the numbers array, size, and n.
int main() {
  int size=20;
  int numbers[]={47, 28, 62, 11, 29, 127, 31, 221, 6, 1002, 588, -1, -7, 7721, 4, 3, 99, 341, 755, 909};
  int n;
  cout<<endl;
  cout<<"Using any user inputted integer, this program will display all the values from a predetermined array of integers which are larger than that number."<<endl;
  cout<<endl;
  cout<<"Please enter any integer: ";
  cin>>n;
  cout<<endl;
  find_greater(numbers, size, n);
  cout<<endl;
  return 0;
}
