#include "Problem3Tomato.h"

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

Tomato::Tomato(): Fruit(), Vegetable(), Food() {
  cout<<"Default constructor for Tomato called"<<endl;
}

Tomato::Tomato(time_t e, time_t r, string n): Fruit(r, n), Vegetable(e, n), Food(n) {
  cout<<"Named constructor called for Tomato for "<<Food::getName()<<endl;
}
