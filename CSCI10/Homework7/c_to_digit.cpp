// Part B

#include <iostream>
#include <string>
using namespace std;

bool isdigit(char c);
int c_to_digit(char c);

bool isdigit(char c) {
  string digits="0123456789";
  for (int i=0; i<digits.length(); i++) {
    if (c==digits[i]) {
      return true;
    }
  }
  return false;
}

int c_to_digit(char c) {
  if (isdigit(c)) {
    return c-'0';
  } else {
    return -1;
    }
}

int main() {
  char c;
  cout<<endl;
  cout<<"The function in this program will return the number version of a character if it is a digit and -1 if it isn't."<<endl;
  cout<<endl;
  cout<<"Please enter a character: ";
  cin>>c;
  cout<<endl;
  cout<<"Return: "<<c_to_digit(c)<<endl;
  cout<<endl;
  return 0;
}
