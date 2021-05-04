#include "Problem3Fruit.h"
#ifndef APPLE_H
#define APPLE_H

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Apple: public Fruit {
public:
  Apple();
  Apple(time_t r);
  void prepare();
};

#endif
