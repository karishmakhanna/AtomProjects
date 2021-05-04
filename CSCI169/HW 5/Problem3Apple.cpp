#include "Problem3Apple.h"

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

Apple::Apple(): Fruit(), Food() {
  cout<<"Default constructor for Apple called"<<endl;
}

Apple::Apple(time_t r): Fruit(r, "Apple"), Food("Apple") {
  cout<<"Named constructor for Apple called for "<<Fruit::getName()<<endl;
}

void Apple::prepare() {
  cout<<"Core the "<<Fruit::getName()<<endl;
}
