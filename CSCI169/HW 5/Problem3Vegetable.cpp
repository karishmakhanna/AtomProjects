#include "Problem3Vegetable.h"

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

Vegetable::Vegetable(): Food() {
  expiration = 0;
  cout<<"Default constructor for Vegetable called"<<endl;
}

Vegetable::Vegetable(time_t e, string n): Food(n) {
  expiration = e;
  cout<<"Named constructor called for Vegetable for "<<Food::getName()<<endl;
}

time_t Vegetable::expireTime() {
  return expiration; // can't format because it is not a void function
}
