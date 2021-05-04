#include "Problem3Orange.h"
#include "Problem3Apple.h"
#include "Problem3Tomato.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main() {
  time_t now = time(0);
  cout<<endl;
  cout<<"Test making an Apple..."<<endl;
  Apple app = Apple(now);
  app.prepare(); // should call Apple's overwritten prepare, core the Apple
  app.ripeTime(); // should call Fruit's ripeTime
  cout<<endl;

  cout<<"Test making an Orange..."<<endl;
  Orange ora = Orange(now);
  ora.prepare(); // should call Orange's overwritten prepare, peel the Orange
  ora.ripeTime(); // should call Fruit's ripeTime
  cout<<endl;

  cout<<"Test making a default Tomato and a Tomato w/ ripe and expire times..."<<endl;
  Tomato tom1 = Tomato(); // default
  Tomato tom2 = Tomato(now, now, "Tomato"); // input ripe & expiration time
  tom2.prepare(); // should call Food's inherited prepare
  tom2.ripeTime(); // should call Fruit's ripeTime
  time_t expire = tom2.expireTime(); // should call Vegetable's expireTime
  tm *ltm = localtime(&expire); // format the expiration date to print nicely
  cout<<"It will expire on "<< 1+ltm->tm_mon <<"/"<< ltm->tm_mday <<"/"<< 1900+ltm->tm_year
  <<" "<< 1+ltm->tm_hour <<":"<< 1+ltm->tm_min <<":"<< 1+ltm->tm_sec <<endl;
  cout<<endl;
}
