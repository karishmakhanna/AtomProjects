#include <iostream>
#include <string>
using namespace std;


string substring(string s, int i, int l) {
  string t="";
  for (int k=i; k<(i+l); k++) {
    t+=s[k];
  }
  return t;
}

int main() {
  int position, length;
  string str;
  cout<<endl;
  cout<<"This program will extract and display a substring from a string, given inputs for where to start and how long to make the substring."<<endl;
  cout<<endl;
  cout<<"Please enter a string of characters: ";
  cin>>str;
  cout<<endl;
  cout<<"Please enter the position index (from the string) which you want your substring to start from (the first character is in position index 0). Enter a starting position less than "<<str.length()<<": ";
  cin>>position;
  cout<<endl;
  if (position>=str.length()) {
    cout<<"Please enter a valid position."<<endl;
  } else {
    cout<<"Please enter the length you wish your substring to be. Please enter a length less than or equal to "<<str.length()-position<<": ";
    cin>>length;
    cout<<endl;
    if ((position+length)<=str.length()) {
    cout<<"Resulting substring: "<<substring(str, position, length)<<endl;
    } else {
      cout<<"Your substring cannot be longer than your string! Please decrease the substring length value, or start from a lower position."<<endl;
    }
  }
  cout<<endl;
  return 0;
}
