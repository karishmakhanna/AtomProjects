


#include <iostream>
#include <string>
using namespace std;

string encrypt(string in, int shift);
int location(char a, string b);

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
  string newstring=in;
  for(int i=0; i<in.length(); i++) {
        int position=location(in[i], alphabetlow);
        newstring[i]=alphabetlow[(position+shift)%26];
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
  cin>>in;
  cout<<endl;
  cout<<"Enter an integer shift value for the encryption: ";
  cin>>shift;
  cout<<endl;
  cout<<"Encrypted string: "<<encrypt(in, shift)<<endl;
  cout<<endl;
  return 0;
}
