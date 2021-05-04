#include "Problem3Fruit.h"

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

Fruit::Fruit(): Food() {
  ripe = 0;
  cout<<"Default constructor for Fruit called"<<endl;
}

Fruit::Fruit(time_t r, string n): Food(n) {
  ripe = r;
  cout<<"Named constructor for Fruit called for "<<Food::getName()<<endl;
}

void Fruit::ripeTime() {
  // format ripe time as MM/DD/YYYY HH:MM:SS
  tm *ltm = localtime(&ripe); // found on cpp reference
  cout<<"You can it eat it on "<< 1+ltm->tm_mon <<"/"<< ltm->tm_mday <<"/"<< 1900+ltm->tm_year
  <<" "<< 1+ltm->tm_hour <<":"<< 1+ltm->tm_min <<":"<< 1+ltm->tm_sec <<endl;
}
