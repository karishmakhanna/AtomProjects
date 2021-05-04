#include <iostream>
using namespace std;

bool isperfect(int x);
void factors(int n, int facts[]);

bool isperfect(int x, int facts[]) {
  int sum=0;
  for (int i=0; i<x-1; i++) {
    if(facts[i]==1) {
      sum=sum+(i+1);
    }
  }
  if(sum==x) {
    return true;
  } else return false;
}

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
  int test = 0;
  cout<<"Enter a number!"<<endl;
  cin>>test;
  if(test>=50) {
      cout<<"Sorry! Can't test numbers that high!"<<endl;
  } else { //run function
    factors(test, a); // populates factors array with 1's/0's
    if(isperfect(test,a)) {
      cout<<"Perfect!"<<endl;
    } else {
      cout<<"Imperfect.  :("<<endl;
    }
  }
  return 0;
}
