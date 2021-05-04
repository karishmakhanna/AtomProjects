#include <iostream>
using namespace std;

int min(int number[], int a) {
  int min=number[0];
  for(int i=0; i<a; i++) {
    if (number[i]<min) {
      min=number[i];
    }
  }
  return min;
}

int main() {
  int size;
  cout<<endl;
  cout<<"This program will find the minimum integer in your array."<<endl;
  cout<<"Please enter the size of your array: ";
  cin>>size;
  int number[size];
  cout<<endl;
  cout<<"Enter "<<size<<" integers: "<<endl;
  for (int i=0; i<size; i++) {
    cin>>number[i];
  }
  cout<<endl;
  cout<<"The minimum value is: "<<min(number, size)<<endl;
  cout<<endl;
  return 0;
}
