


#include <iostream>
#include <string>
using namespace std;

string substring(string s, int i, int l);
int findindex(string protein, string dna);

int findindex(string protein, string dna) {
  int a=-1;
  for (int m=0; m<=(dna.length()-protein.length()); m++) {
    if (substring(dna, m, protein.length())==protein) {
      a=m;
      return a;
    }
  }
  return a;
}

string substring(string s, int i, int l) {
  string t="";
  for (int k=i; k<i+l; k++) {
    t+=s[k];
  }
  return t;
}

int main() {
  string dna, protein;
  cout<<endl;
  cout<<"This program will print out the index (one less than the position) of the start of the first match of a given protein string in a given DNA string."<<endl;
  cout<<endl;
  cout<<"Please enter a DNA string composed of the characters A, T, C, and G: ";
  cin>>dna;
  string check=dna;
  cout<<endl;
  for (int i=0; i<dna.length(); i++) {
    if (dna[i]!='A' && dna[i]!='T' && dna[i]!='C' && dna[i]!='G') {
      check="invalid";
    }
  }
  if (check=="invalid") {
    cout<<"Please make sure your DNA string does not have any non-ATCG characters!"<<endl;
    cout<<endl;
  } else if (check==dna) {
      cout<<"Please enter the protein string you are looking for: ";
      cin>>protein;
      cout<<endl;
      for (int i=0; i<protein.length(); i++) {
        if (protein[i]!='A' && protein[i]!='T' && protein[i]!='C' && protein[i]!='G') {
          check="invalid";
        }
      }
      if (check=="invalid") {
        cout<<"You cannot search for a protein string with non-ATCG characters!"<<endl;
        cout<<endl;
      } else if (check==dna) {
          if(findindex(protein, dna)<0 || findindex(protein, dna)>(dna.length()-1)) {
            cout<<"This protein string was not found in the DNA string."<<endl;
            cout<<endl;
          } else {
              cout<<"The index of the start of the first match of the given protein string in the given DNA string is: "<<findindex(protein, dna)<<endl;
              cout<<endl;
          }
        }
    }
  return 0;
}
