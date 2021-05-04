
//PART A

#include <iostream>
using namespace std;
int fun(int c, int b);
int main(){
int a = 0, b= 5, c = 10;
cout<<"a is: "<<a<<" b is: "<<b<<" c is: "<<c<<endl;
b=fun(a, c);
cout<<"a is: "<<a<<" b is: "<<b<<" c is: "<<c<<endl;
while(b==21){
int a = 3;
b = a;
cout<<"a is: "<<a<<" b is: "<<b<<" c is: "<<c<<endl;
}
cout<<"a is: "<<a<<" b is: "<<b<<" c is: "<<c<<endl;
return 0;
}
int fun(int c, int b){
int a = 0;
b = 2*b;
c = b+1;
cout<<"a is: "<<a<<" b is: "<<b<<" c is: "<<c<<endl;
return c;
}


//PART B
/*
#include <iostream>
using namespace std;
void beans(int y, int& n, int size);
void spam(int& n, int& y);
int main(){
int m = 7;
int n = 4;
cout<<"m is "<<m<<" n is "<<n<<endl;
beans(n, m, 3);
cout<<"m is "<<m<<" n is "<<n<<endl;
spam(m, n);
cout<<"m is "<<m<<" n is "<<n<<endl;
spam(n, n);
cout<<"m is "<<m<<" n is "<<n<<endl;
//beans(m, 2, n);
cout<<"m is "<<m<<" n is "<<n<<endl;
return 0;
}
void beans(int y, int& n, int size){
y = n+size;
n = 7+n;
}
void spam(int& n, int& y){
int m = n+y;
y=n;
n=y+n;
}
*/

//PART C

/*
#include<iostream>
using namespace std;

double average(){
 double val = 0, total = 0, count = 0;
 cout<<endl;
 cout<<"Please enter a value, or -1 when you're done."<<endl;
 cin>>val;
 cout<<endl;
 while(val!=-1){
 total+=val;
 count++;
 cout<<"Please enter a value, or -1 when you're done."<<endl;
 cin>>val;
 cout<<endl;
 }
 return total/count;
}
double max(){
 double val = 0, max = -1;
 cout<<endl;
 cout<<"Please enter a value, or -1 when you're done."<<endl;
 cin>>val;
 cout<<endl;
 while(val!=-1){
 if(val>max)
 max = val;
 cout<<"Please enter a value, or -1 when you're done."<<endl;
 cin>>val;
 cout<<endl;
 }
 return max;
}

int main() {
  cout<<average();
  cout<<endl;
  cout<<max();
  cout<<endl;
  return 0;
}
*/

//NEW FUNCTION USING CBR FOR PART C
/*
#include<iostream>
using namespace std;

void maxavg(double& max, double& avg);

int main() {
  double avg=0;
  double max=-1;
  cout<<endl;
  cout<<"This program will display the maximum and average values from a set of positive user inputted numbers."<<endl;
  maxavg(max, avg);
  cout<<"MAX: "<<max<<endl;
  cout<<"AVERAGE: "<<avg<<endl;
  cout<<endl;
  return 0;
}

void maxavg(double& m, double& a) {
  double val = 0, total = 0, count = 0;
  cout<<endl;
  cout<<"Please enter a value, or -1 when you're done."<<endl;
  cin>>val;
  while(val!=-1) {
    total+=val;
    count++;
    if(val>m) {
      m = val;
    }
    cout<<"Please enter a value, or -1 when you're done."<<endl;
    cin>>val;
  }
  cout<<endl;
  a=total/count;
}
*/
