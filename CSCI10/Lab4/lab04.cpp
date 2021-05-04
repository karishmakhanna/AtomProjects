
// A4

/*
#include <iostream>
using namespace std;

int main() {

int i, j;

  for (i=0; i<5; i++) {
    for (j=3; j>0; j--) {
      cout<<i*j<<" ";
    }
  }
  return 0;
}
*/

// B2

/*
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  int i, x, a;

  srand(time(0));

  while (true) {
    cout<<endl;
    cout<<"Enter the number of sides your die has: "<<endl;
    cin>>x;
    cout<<endl;
    a=rand()%x+1;
    cout<<"The random side chosen is side: "<<a<<endl;
  }

  cout<<endl;
  return 0;
}
*/

// B2 REVISED
/*
#include <iostream>
#include <cstdlib>
using namespace std;

int die(int n) {
  int a;
  srand(time(0));
  a=rand()%n+1;
return a;
}

int main() {
  int x;

    cout<<endl;
    cout<<"Enter the number of sides your die has: "<<endl;
    cin>>x;
    cout<<endl;
    cout<<"The random side chosen is side: "<<die(x)<<endl;
    cout<<endl;

  return 0;
}
*/


// B4
/*
#include <iostream>
using namespace std;

bool is_even(int n) {
  if (n%2==0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int a;

  cout<<endl;
  cout<<"Enter an integer to check if it is even: "<<endl;
  cin>>a;
  cout<<endl;
  cout<<a<<" is even (1 means true, 0 means false): "<<is_even(a)<<endl;
  cout<<endl;

  return 0;
}
*/

// B6

#include <iostream>
using namespace std;

bool is_even(int);
int evens_between(int, int);

int main() {
  int i, a, b, c, evens=0;
  cout<<endl;
  cout<<"This program will count the even numbers between a and b, inclusive of a and b."<<endl;
  cout<<endl;
  cout<<"Enter a value for a (lower bound): "<<endl;
  cin>>a;
  cout<<endl;
  cout<<"Enter a value for b (upper bound): "<<endl;
  cin>>b;
  cout<<endl;
  cout<<"There are "<<evens_between(a, b)<<" even numbers between "<<a<<" and "<<b<<"."<<endl;
  cout<<endl;
  return 0;
}

bool is_even(int n) {
  if (n%2==0) {
    return true;
  } else {
    return false;
  }
}

int evens_between(int a, int b) {
  int i, c, evens=0;
  for(i=a; i<=b; i++) {
    c=is_even(i);
    if (c==1) {
      evens=evens+1;
    } else evens=evens+0;
  }
  return evens;
}
