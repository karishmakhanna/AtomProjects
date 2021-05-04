/*
#include <iostream>
using namespace std;

int main() {
int gg, Gg, GG;
char m1, m2, p1, p2;

gg = 0;
Gg = 0;
GG = 0;

cout<<"Enter m1 in terms of G or g: "<<endl;
cin>>m1;

cout<<"Enter m2 in terms of G or g: "<<endl;
cin>>m2;

cout<<"Enter p1 in terms of G or g: "<<endl;
cin>>p1;

cout<<"Enter p2 in terms of G or g: "<<endl;
cin>>p2;


if ((m1=='G') and (p1=='G')){
    GG = GG+.25;
} else if (((m1 == 'G') and (p1 == 'g')) or ((m1 == 'g') and (p1 == 'G'))) {
    Gg = Gg+.25;
} else if ((m1 == 'g') and (p1 == 'g')) {
    gg = gg+.25;
} if ((m2=='G') and (p1=='G')) {
    GG = GG+.25;
} else if (((m2 == 'G') and (p1 == 'g')) or ((m2 == 'g') and (p1 == 'G'))) {
    Gg = Gg+.25;
} else if m2 == 'g' and p1 == 'g':
    gg = gg+.25;
if m1=='G' and p2=='G':
    GG = GG+.25;
else if (m1 == 'G' and p2 == 'g') or (m1 == 'g' and p2 == 'G'):
    Gg = Gg+.25;
else if m1 == 'g' and p2 == 'g':
    gg = gg+.25;
if m2=='G' and p2=='G':
    GG = GG+.25;
else if (m2 == 'G' and p2 == 'g') or (m2 == 'g' and p2 == 'G'):
    Gg = Gg+.25;
else if m2 == 'g' and p2 == 'g':
    gg = gg+.25;

cout<<"Chance of GG: "<<GG<<endl;
cout<<"Chance of Gg: "<<Gg<<endl;
cout<<"Chance of gg: "<<gg<<endl;


return 0;
}
*/

#include <iostream>
#include <string>
using namespace std;
int main() {

  string parent1;
  string parent2;

  cout<<"Enter parent 1's genotype in terms of GG, Gg, or gg: "<<endl;
  cin>>parent1;

  cout<<"Enter parent 2's genotype in terms of GG, Gg, or gg: "<<endl;
  cin>>parent2;

  if ((parent1 == "GG" && parent2 == "gg") || (parent2 == "GG" && parent1 == "gg")) {
    cout<<"Probability of GG is 0"<<endl;
    cout<<"Probablitly of gg is 0"<<endl;
    cout<<"Probability of Gg is 1"<<endl;
  } else if ((parent1 == "GG" && parent2 == "Gg") || (parent2 == "GG" && parent1 == "Gg")) {
    cout<<"Probability of GG is .5"<<endl;
    cout<<"Probablitly of gg is 0"<<endl;
    cout<<"Probability of Gg is .5"<<endl;
  } else if ((parent1 == "Gg" && parent2 == "gg") || (parent2 == "Gg" && parent1 == "gg")) {
    cout<<"Probability of GG is .5"<<endl;
    cout<<"Probablitly of gg is .5"<<endl;
    cout<<"Probability of Gg is 0"<<endl;
  } else if (parent1 == "GG" && parent2 == "GG") {
    cout<<"Probability of GG is 1"<<endl;
    cout<<"Probablitly of gg is 0"<<endl;
    cout<<"Probability of Gg is 0"<<endl;
  } else if (parent1 == "gg" && parent2 == "gg") {
    cout<<"Probability of GG is 0"<<endl;
    cout<<"Probablitly of gg is 1"<<endl;
    cout<<"Probability of Gg is 0"<<endl;
  } else if (parent1 == "Gg" && parent2 == "Gg") {
    cout<<"Probability of GG is .25"<<endl;
    cout<<"Probablitly of gg is .25"<<endl;
    cout<<"Probability of Gg is .5"<<endl;
  }

  return 0;
}
