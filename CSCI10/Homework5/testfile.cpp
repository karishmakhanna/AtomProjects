
// 5.1

#include <iostream>
using namespace std;
void Sum(int a, int b, int& c) {
a = b + c;
b = a + c;
c = a + b;
}
int main() {
int x = 2, y = 3;
cout << x << " " << y << endl;
Sum(x, y, y);
cout << x << " " << y << endl;
return 0;
}


// 5.2
/*
#include <iostream>
using namespace std;
void fun(int& x) {
x = 20;
}
int main() {
int x = 10;
fun(x);
cout << "New value of x is " << x << endl;
return 0;
}
*/

// 5.3
/*
#include <iostream>
using namespace std;
int global;
void f1(int);
void f2(int &);
void f1(int n) {
n += global;
}
void f2(int & n) {
n += global;
}
int main() {
cout << global++ << endl;
{
int global(100);
cout << ++global << endl;
}
cout << global << endl;
int local(10);
cout << local << endl;
{
int local(20);
cout << local + global << endl;
}
cout << local + global << endl;
f1(local);
cout << local << endl;
f1(global);
cout << global << endl;
f2(local);
cout << local << endl;
f2(global);
cout << global << endl;
return 0;
}
*/
