#include "Problem3Fruit.h"
#include "Problem3Vegetable.h"
#ifndef TOMATO_H
#define TOMATO_H

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Tomato: public Fruit, public Vegetable { // diamond problem
public:
  Tomato();
  Tomato(time_t e, time_t r, string n);
};

#endif
