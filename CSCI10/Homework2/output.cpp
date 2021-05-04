/*

csci10- section 01-hw2

Created by Karishma Khanna on 10/02/18.

The output is NO because a is not less than b,
and a is not less than c, since 5 is not less than 4 and
4  is not less than 3. The next line will print a + 1,
which is 5 + 1=6. 1 is the remainder of 4 divided by 3.

The final result will be:
NO and 6. */

#include <iostream>
using namespace std;

int main() {
int a = 5, b = 4, c = 3;

if (a < b || (a < c && b > c))
cout << "YES" << endl;
else
cout << "NO" << endl;
cout << a + b % c << endl;
return 0;
}
