#include <iostream>
#include <string>
using namespace std;

int main() {
  const int size=5;
  string spanish[size]={"gato", "perro", "uno", "dos", "tres"};
  string english[size]={"cat", "dog", "one", "two", "three"};
  string answer;
  int score[size]={0,0,0,0,0};
  int correct=0;
  int attempts=0;
  while(correct<10) {
    int index=rand()%5;
    if(score[index]<2) {
      cout<<"What is the English of "<<spanish[index]<<": ";
      cin>>answer;
      if(answer==english[index]) {
        correct=correct+1;
        score[index]=score[index]+1;
      } else {
        cout<<"The right answer is: "<<english[index]<<endl;
      }
      attempts=attempts+1;
    }
  }
  cout<<"Attempts: "<<attempts<<endl;
  return 0;
}
