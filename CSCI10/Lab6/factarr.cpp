#include <iostream>
using namespace std;

bool isfact(int n){
 bool is=false;
 int fact=1;
 for(int i=1; i<n+1; i++){
 fact=fact*i;
 if(fact==n)
 is=true;
 }
 return is;
}

void factarr(int a[], bool fact[], int size) {
  for (int k=0; k<size; k++) {
    fact[k]=isfact(a[k]);
  }
  for (int j=0; j<size; j++) {
    cout<<a[j];
  }
  cout<<endl;
  for (int l=0; l<size; l++) {
    cout<<fact[l];
  }
}

int main() {
  int size=6;
  int a[6] = {1,2,3,4,5,6};
  cout<<endl;
  cout<<"This program will print one list containing values 1 to "<<size<<" and another list which will print 1 if the number above from the first list is a factorial, and 0 if not."<<endl;
  cout<<endl;
  bool fact[size];
  factarr(a, fact, size);
  cout<<endl;
  cout<<endl;
  return 0;
}
