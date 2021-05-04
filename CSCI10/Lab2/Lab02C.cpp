#include <iostream>
#include <string>
using namespace std;

int main() {
  char grade;
  cout<<"Enter a grade: "<<endl;
  cin>>grade;
  switch (grade) {
    case 'A':
    cout<<"Amazing job!";
    break;
    case 'B':
    cout<<"Great work!";
    break;
    case 'C':
    cout<<"You pass, good job.";
    break;
    case 'D':
    cout<<"You pass, but barely.";
    break;
    case 'F':
    cout<<"You need to improve!!";
    break;
    default:
    cout<<"That is not a valid grade.";
    break;
  }
  return 0;
}
