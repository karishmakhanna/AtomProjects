// Part C

#include <iostream>
#include <string>
using namespace std;

bool isdigit(char c);
int s_to_digit(string s);
int pow(int n, int ex);

bool isdigit(char c) {
  string digits="0123456789";
  for (int i=0; i<digits.length(); i++) {
    if (c==digits[i]) {
      return true;
    }
  }
  return false;
}

int pow(int n, int ex) {
  int ret = 1;
  for(int i=0; i<ex; i++) {
    ret = ret*n;
  }
  return ret;
}

int s_to_digit(string s) {
  int number=0;
  for (int i=s.length()-1; i>=0; i--) {
    if(isdigit(s[i])) {
      number=number+((s[i]-'0')*pow(10, s.length()-1-i));
    } else {
        return -1;
      }
  }
  return number;
}

int main() {
  string s;
  cout<<endl;
  cout<<"The function in this program will return the number version of a string if it is composed of digits and -1 if it isn't."<<endl;
  cout<<endl;
  cout<<"Please enter a string: ";
  cin>>s;
  cout<<endl;
  cout<<"Return: "<<s_to_digit(s)<<endl;
  cout<<endl;
  return 0;
}
