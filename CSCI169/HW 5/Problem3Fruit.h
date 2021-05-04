#include "Problem3Food.h"
#ifndef FRUIT_H
#define FRUIT_H

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Fruit: virtual public Food { // virtual so Food constructor is only called once
public:
  Fruit();
  Fruit(time_t r, string n);
  string getName() const{return Food::getName();}
  void ripeTime();
private:
  time_t ripe;
};

#endif
