#include <iostream>
using namespace std;

void factors(int n, int facts[]) {
  facts[0]=0;
  for (int i=1; i<n+1; i++) {
    if ((n%i)==0) {
      facts[i-1]=1;
    }
    else {
      facts[i-1]=0;
    }
  }
  for (int k=0; k<n; k++) {
    cout<<"Spot: "<<k+1<<" Value: "<<facts[k]<<endl;
  }
}

int main() {
  int a[50];
  int test=0;
  cout<<endl;
  cout<<"This program will input an integer (less than 50) and analyze the integers less than or equal to the input. It will display 1 if the number is a factor, and 0 if it is not a facor."<<endl;
  cout<<endl;
  cout<<"Enter an integer!"<<endl;
  cin>>test;
  cout<<endl;
  if (test>=50) {
    cout<<"Sorry! Can't test numbers that high!"<<endl;
    cout<<endl;
  } else {
    factors(test, a);
    cout<<endl;
  }
  return 0;
}
