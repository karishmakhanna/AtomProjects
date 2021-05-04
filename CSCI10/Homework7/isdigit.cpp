// Part A

#include <iostream>
#include <string>
using namespace std;

bool isdigit(char c) {
  string digits="0123456789";
  for (int i=0; i<digits.length(); i++) {
    if (c==digits[i]) {
      return true;
    }
  }
  return false;
}

int main() {
  char c;
  cout<<endl;
  cout<<"The function in this program will test if a character is a digit or not."<<endl;
  cout<<endl;
  cout<<"Please enter a character: ";
  cin>>c;
  cout<<endl;
  if (isdigit(c)) {
    cout<<"The character "<<c<<" is a digit!"<<endl;
  } else {
    cout<<"The character "<<c<<" is NOT a digit!"<<endl;
  }
  cout<<endl;
  return 0;
}
