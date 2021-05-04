#include "Problem3Fruit.h"
#ifndef ORANGE_H
#define ORANGE_H

#include <iostream>
#include <string>
#include <ctime>
using namespace std;


class Orange: public Fruit {
public:
  Orange();
  Orange(time_t r);
  void prepare();
};

#endif
