/*
mergefiles.cpp
csci10- section01-hw9

Created by Karishma Khanna on 11/24/18.

This program will merge the contents of two files into a new file.

*/

#include <iostream>
#include <stream>
using namespace std;

int main() {
  // declare variables being used
  // two input files, one output file
  // a character to read each character from the input files and store it into two different strings (character arrays)
  ifstream file1, file2;
  ofstream newfile;
  char c;
  string str1, str2;
  cout<<endl;
  // state the purpose of the program
  cout<<"This program will merge the contents of two files into a new file."<<endl;
  cout<<endl;
  // open/create connections between ifstream/ofstream variables and the files
  // the files should be in the same folder/directory as the .cpp file for the program
  file1.open("data1.txt");
  file2.open("data2.txt");
  newfile.open("data.txt");
  // fail check, exit if the connection to any file fails
  if (file1.fail() || file2.fail() || newfile.fail()) {
    cout<<"Connection to one of the files failed."<<endl;
    cout<<endl;
    exit(1);
  }
  // read each character from file1 until the end of the file, and store the characters into a string str1
  while (!file1.eof()) {
    file1.get(c);
    str1+=c;
  }
  // read each character from file2 until the end of the file, and store the characters into a string str2
  while (!file2.eof()) {
    file2.get(c);
    str2+=c;
  }
  // put each character from the string str1 into the new file, except the last trailing /n character from the string
  for (int i=0; i<str1.length()-1; i++) {
    newfile.put(str1[i]);
  }
  // put each character from the string str2 into the new file, except the last trailing /n character from the string
  for (int j=0; j<str2.length()-1; j++) {
    newfile.put(str2[j]);
  }
  // statement to indicate the goal was completed
  cout<<"New file created."<<endl;
  cout<<endl;
  // close connections between ifstream/ofstream variables and the files
  file1.close();
  file2.close();
  newfile.close();
  return 0;
}
