#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Food {
public:
  Food();
  Food(string n);
  void prepare();
  string getName() const{return name;}
private:
  string name;
};

#endif
