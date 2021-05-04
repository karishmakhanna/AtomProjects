
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
  ofstream ofile;
  double scores[150];
  cout<<endl;
  cout<<"This program will read in scores from a file (if the connection is successful), then output the average score and scores higher than the average onto a new file (outputscores.txt)."<<endl;
  ifile.open("/Users/alkhanna/Desktop/psych-round2-scores2.txt");
  ofile.open("/Users/alkhanna/Desktop/outputscores.txt");
  if (ifile.fail()) {
    cout<<"Connection to input file failed."<<endl;
    cout<<endl;
    exit(1);
  }
  if (ofile.fail()) {
    cout<<"Connection to output file failed."<<endl;
    cout<<endl;
    exit(1);
  }
  int count=0;
  while (!ifile.eof()) {
    ifile>>scores[count];
    count++;
  }
  double avg=average(scores, count);
  ofile<<"Average: "<<avg<<endl;
  ofile<<"Scores higher than the average:"<<endl;
  for (int i=0; i<count; i++) {
    if (scores[i]>avg) {
      ofile<<scores[i]<<endl;
    }
  }
  cout<<endl;
  ifile.close();
  ofile.close();
  return 0;
}
