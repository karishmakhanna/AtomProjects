// testing

// 9.1

// #include<iostream>
// #include<fstream>
// using namespace std;
//
// int main() {
//   ofstream ofile;
//   ofile.open ("text.txt");
//   ofile << "We are in CS 10 class!" << endl;
//   cout << "Data written to file" << endl;
//   ofile.close();
//   return 0;
// }

// 9.2

#include<iostream>
#include<fstream>
using namespace std;
int main() {
  char data[100];
  ifstream ifile;
  //create a text file before executing.
  ifile.open ("text.txt");
  while ( !ifile.eof() )
  {
  ifile.getline (data, 100);
  cout << data << endl;
  }
  ifile.close();
  return 0;
}
