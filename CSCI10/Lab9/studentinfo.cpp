

#include <iostream>
#include <fstream>
using namespace std;

struct StudentInfo {
  string firstname;
  string lastname;
  string classlevel;
  double gpa;
};

int main() {
  StudentInfo Students[9];
  ifstream ifile;
  cout<<endl;
  cout<<"This program will input student info from a file (if the connection is successful) into an array, and display the inputs below to show that it was correctly entered."<<endl;
  ifile.open("/Users/alkhanna/Desktop/studentlist1.txt");
  if (ifile.fail()) {
    cout<<"Connection to input file failed."<<endl;
    cout<<endl;
    exit(1);
  }
  cout<<endl;
  for (int i=0; i<9; i++) {
    ifile>>Students[i].firstname>>Students[i].lastname>>Students[i].classlevel>>Students[i].gpa;
    cout<<Students[i].firstname<<endl;
    cout<<Students[i].lastname<<endl;
    cout<<Students[i].classlevel<<endl;
    cout<<Students[i].gpa<<endl;
  }
  cout<<endl;
  ifile.close();
  return 0;
}
