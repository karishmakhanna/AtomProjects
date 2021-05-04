

#include <iostream>
#include <fstream>
using namespace std;

double average(double arr[], int size){
 double total=0;
 for(int i=0; i<size; i++){
 total=total+arr[i];
 }
 return total/size;
}

int main() {
  ifstream ifile;
  double scores[150];
  cout<<endl;
  cout<<"This program will read in scores from a file (if the connection is successful), then print out the average score and number of scores."<<endl;
  cout<<endl;
  ifile.open("/Users/alkhanna/Desktop/psych-round2-scores2.txt");
  if (ifile.fail()) {
    cout<<"Connection to input file failed."<<endl;
    cout<<endl;
    exit(1);
  }
  int count=0;
  while (!ifile.eof()) {
    ifile>>scores[count];
    count++;
  }
  cout<<"Average: "<<average(scores, count)<<endl;
  cout<<"Number of scores: "<<count<<endl;
  cout<<endl;
  ifile.close();
  return 0;
}
