#include "Problem3Orange.h"

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

Orange::Orange(): Fruit(), Food() {
  cout<<"Default constructor for Orange called"<<endl;
}

Orange::Orange(time_t r): Fruit(r, "Orange"), Food("Orange") {
  cout<<"Named constructor for Orange called for "<<Fruit::getName()<<endl;
}

void Orange::prepare() {
  cout<<"Peel the "<<Fruit::getName()<<endl;
}
