

#include <iostream>
#include <string>
using namespace std;

string encrypt(string in, int shift);
bool contains(string in, int i, string s);
int location(char a, string b);


bool contains(string in, int i, string s) {
  for (int k=0; k<s.length(); k++) {
    if (s[k]==in[i]) {
      return true;
    }
  }
  return false;
}

int location(char a, string b) {
  int index=-1;
  for (int i=0; i<b.length(); i++) {
    if (b[i]==a) {
      index=i;
    }
  }
  return index;
}

string encrypt(string in, int shift) {
  string alphabetlow="abcdefghijklmnopqrstuvwxyz";
  string alphabetupp="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string digits="0123456789";
  string newstring=in;
  for(int i=0; i<in.length(); i++) {
      if (contains(in, i, alphabetlow)==true) {
        int change=shift;
        int position=location(in[i], alphabetlow);
        while (change<0) {
          change=change+26;
        }
        newstring[i]=alphabetlow[(position+(change%26))%26];
      } else if (contains(in, i, alphabetupp)==true) {
          int change=shift;
          int position=location(in[i], alphabetupp);
          while (change<0) {
            change=change+26;
          }
          newstring[i]=alphabetupp[(position+(change%26))%26];
        } else if (contains(in, i, digits)==true) {
            int change=shift;
            int position=location(in[i], digits);
            while (change<0) {
              change=change+10;
            }
            newstring[i]=digits[(position+(change%10))%10];
          } else if (in[i]==' ') {
            newstring[i]=' ';
          } else {
            newstring[i]=in[i];
          }
  }
  return newstring;
}

int main() {
  int shift;
  string in;
  cout<<endl;
  cout<<"This program will encrypt a given string of characters using a user-inputted shift along the standard alphabet and 0-9 digits."<<endl;
  cout<<endl;
  cout<<"Enter the string you would like to encrypt: ";
  getline(cin, in);
  cout<<endl;
  cout<<"Enter an integer shift value for the encryption: ";
  cin>>shift;
  cout<<endl;
  cout<<"Encrypted string: "<<encrypt(in, shift)<<endl;
  cout<<endl;
  return 0;
}
