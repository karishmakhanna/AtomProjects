#include "Problem3Food.h"

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

Food::Food() {
  name = "default";
  cout<<"Default constructor for Food called"<<endl;
}

Food::Food(string n) {
  name = n;
  cout<<"Named constructor for Food called for "<<name<<endl;
}

void Food::prepare() {
  cout<<"Prepare the "<<name<<endl;
}
