// Q2
/*
#include <iostream>
#include <cmath>

using namespace std;

int main () {

  double x, g, y0, v, theta, y;
  g = 9.81;

cout<<"This calculation will display the (x,y) coordinates of your projectile for all integers x between 0 and 9. It will use g (gravitational acceleration) for Earth, where g = 9.81 m/s^2."<<endl;

cout<<"Enter the speed v at which the projectile is launched in m/s: "<<endl;
cin>>v;

cout<<"Enter the initial height y0 at which the projectile is launched in m: "<<endl;
cin>>y0;

cout<<"Enter the angle theta at which the projectile is launched in radians: "<<endl;
cin>>theta;

x=0;
while ((x>=0) && (x<=9)) {
  y = y0 + (x*tan(theta)) - ((g*x*x)/(2*v*cos(theta)*cos(theta)));
  cout<<"The (x,y) coordinates in meters of your projectile are "<<"("<<x<<","<<y<<")"<<endl;
  x++;
}

return 0;
}
*/

// Q4
/*
#include <iostream>
#include <cmath>

using namespace std;

int main () {

double x, g, y0, v, theta, y;
g = 9.81;

cout<<"This calculation will display the (x,y) coordinates of your projectile for all integers x between 0 and 9. It will use g (gravitational acceleration) for Earth, where g = 9.81 m/s^2."<<endl;

cout<<"Enter the speed v at which the projectile is launched in m/s: "<<endl;
cin>>v;

cout<<"Enter the initial height y0 at which the projectile is launched in m: "<<endl;
cin>>y0;

cout<<"Enter the angle theta at which the projectile is launched in radians: "<<endl;
cin>>theta;

for (x=0; x<10; x++) {
  y = y0 + (x*tan(theta)) - ((g*x*x)/(2*v*cos(theta)*cos(theta)));
  cout<<"The (x,y) coordinates in meters of your projectile are "<<"("<<x<<","<<y<<")"<<endl;
}

return 0;
}
*/

//Q6
/*
#include <iostream>
#include <cmath>

using namespace std;

int main () {

  double x, g, y0, v, theta, y;
  g = 9.81;

cout<<"This calculation will display the (x,y) coordinates of your projectile for all integers x between 0 and 9. It will use g (gravitational acceleration) for Earth, where g = 9.81 m/s^2."<<endl;

cout<<"Enter the speed v at which the projectile is launched in m/s: "<<endl;
cin>>v;

cout<<"Enter the initial height y0 at which the projectile is launched in m: "<<endl;
cin>>y0;

cout<<"Enter the angle theta at which the projectile is launched in radians: "<<endl;
cin>>theta;

x=0;
y = y0 + (x*tan(theta)) - ((g*x*x)/(2*v*cos(theta)*cos(theta)));
while ((y>=0) && (x>=0) && (x<=9)) {
  cout<<"The (x,y) coordinates in meters of your projectile are "<<"("<<x<<","<<y<<")"<<endl;
  ++x;
  y = y0 + (x*tan(theta)) - ((g*x*x)/(2*v*cos(theta)*cos(theta)));
}

return 0;
}
*/

// Q8

#include <iostream>
#include <cmath>

using namespace std;

int main () {

  double x, g, y0, v, theta, y;
  g = 9.81;

  cout<<"This calculation will display the (x,y) coordinates of your projectile for all integers x between 0 and 9. It will use g (gravitational acceleration) for Earth, where g = 9.81 m/s^2."<<endl;

  cout<<"Enter the speed v at which the projectile is launched in m/s: "<<endl;
  cin>>v;

  cout<<"Enter the initial height y0 at which the projectile is launched in m: "<<endl;
  cin>>y0;

  cout<<"Enter the angle theta at which the projectile is launched in radians: "<<endl;
  cin>>theta;

  for (x=0; x<10; x++) {
    y = y0 + (x*tan(theta)) - ((g*x*x)/(2*v*cos(theta)*cos(theta)));
    if (y>=0) {
      cout<<"The (x,y) coordinates in meters of your projectile are "<<"("<<x<<","<<y<<")"<<endl;
    }
  }

  return 0;
}
