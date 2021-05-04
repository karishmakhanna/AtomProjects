
/*
Series.cpp
csci10- section01-hw3

Created by Karishma Khanna on 10/08/18.

The two programs below calculate the sum of any arithmetic series in two different ways. The first one uses the arithmetic sum formula, whereas the second one uses looping. This program will tell the user to use the series 5 + 8 + 11 + ... + 50.
*/


#include <iostream>
#include <cmath>
using namespace std;

  int main() {
  //identifier declarations
    int n; // n and sumn are the terms and sum of the terms, respectively, in the case that the sum is adding the same number again and again
    double sumn, first, difference, last, sum, terms; //variables needed for arithmetic series calculation

    // display problem, prompts, and get inputs
    cout<<endl;
    cout<<"This program will calculate the sum between any two terms in any arithmetic series, inclusive of the first and last terms. For this problem, our arithmetic series will be 5+8+11+... and although any terms in the series can be your first and last, please use 5 as your first term 50 as your last term for the first calculation. The common difference will be 3."<<endl;
    cout<<endl;
    cout<<"Enter the first term of the series: "<<endl;
    cin>>first;
    cout<<endl;
    cout<<"Enter the last term of the series: "<<endl;
    cin>>last;
    cout<<endl;
    cout<<"Enter the common difference for the series (please enter either a whole number or .5): "<<endl;
    cin>>difference;
    cout<<endl;

    // if the first and last terms are the same, execute the following:
    if (last-first==0 && difference==0) {
      cout<<"How many terms are in your series? i.e. How many times does "<<first<<" repeat?"<<endl;
      cin>>n;
      cout<<endl; // n must be at least 1, and cannot be negative
      if (n>0) {
        sumn=first*n;
          cout<<"The sum of this series is "<<sumn<<"."<<endl; // display the sum result if the terms input was valid
      } else if (n<=0) {
          cout<<"Please rerun the code using ./a.out and make sure your terms value is greater than or equal to 1."<<endl; // otherwise, output an error message
        }
      } else if (abs(difference)<=abs(last-first) && fmod((last-first),difference)==0 && ((last-first)/difference)>0) {
          // first condition: the common difference cannot be greater than the distance between the first and last terms
          // second condition: fmod is a remainder function for double values (% was not working) and here we are making sure that the difference perfectly divides into the distance between the first and last terms of the series
          // third condition: we are also making sure that the difference has the same sign as the change between the last number minus the first number, by checking for a positive number when the change in the terms is divided by the difference

          // calculate the sum of the series, define "term" using the other variables in a formula
          // last=first+(terms-1)(difference)
          terms=((last-first)/(difference))+1;
          sum=1.0*(first+last)*(terms/2);
          cout<<"The sum of this series from "<<first<<" to "<<last<<" is "<<sum<<"."<<endl; // display the sum result
          cout<<endl;
        } else {
            cout<<"Please rerun the code using ./a.out and use a valid common difference."<<endl; // if there were any errors, it will be with the common difference, so we ask the user to run the code again and enter a valid common difference
          }
    return 0;
  }

// fix it so the common difference can be a fraction!!!

/*
ALTERNATE SOLUTION USING LOOPING

#include <iostream>
#include <cmath>
using namespace std;

int main() {

// identifier declarations
  double i, d, f, n, sum, t; // variables needed

// display prompts and get inputs
  cout<<endl;
  cout<<"This program will calculate the sum between any two terms in any arithmetic series, inclusive of the first and last terms. For this problem, our arithmetic series will be 5+8+11+... and although any terms in the series can be your first and last, please use 5 as your first term 50 as your last term for the first calculation. The common difference will be 3."<<endl;
  cout<<endl;
  cout<<"Enter the first term of the series: "<<endl;
  cin>>f;
  cout<<endl;
  cout<<"Enter the last term of the series: "<<endl;
  cin>>n;
  cout<<endl;
  cout<<"Enter the common difference for the series: "<<endl;
  cin>>d;
  cout<<endl;

// three different if statements for when the series is increasing, decreasing, and unchanging
// also included barriers to check for the validity of the common difference
// for each case, there is a calculation and the result is displayed
  sum=0;
  if (abs(d)<=abs(n-f) && n>f && abs(d)>0 && d>0) {
    for(i=f; i<=n; i+=d) {
      sum=sum+i; // for increasing function
    }
    cout<<"The sum of this series is "<<sum<<"."<<endl;
    cout<<endl;
  } else if (abs(d)<=abs(n-f) && f>n && abs(d)>0 && d<0) {
      for(i=f; i>=n; i+=d) {
        sum=sum+i; // for decreasing function
      }
      cout<<"The sum of this series is "<<sum<<"."<<endl;
      cout<<endl;
    } else if (n==f && d==0) {
      cout<<"How many terms are in your series? i.e. How many times does "<<f<<" repeat?"<<endl;
      cin>>t;
      cout<<endl;
      if (t>0) {
        sum=f*t; // for unchanging function
        cout<<"The sum of this series is "<<sum<<"."<<endl;
      } else if (t<=0) {
          cout<<"Please make sure your terms value is greater than or equal to 1."<<endl;
        }
      } else {
        cout<<"Please enter a valid common difference."<<endl;
        cout<<endl;
        }

    return 0;
  }
*/
