#include "Problem3Food.h"
#ifndef VEGETABLE_H
#define VEGETABLE_H

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Vegetable: virtual public Food { // virtual so Food constructor is only called once
public:
  Vegetable();
  Vegetable(time_t e, string n);
  string getName() const{return Food::getName();}
  time_t expireTime();
private:
  time_t expiration;
};

#endif
