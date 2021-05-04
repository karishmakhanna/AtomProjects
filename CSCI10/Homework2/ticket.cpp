/*
ticket.cpp
csci10- section 01 -hw2

Created by Karishma Khanna on 10/02/18.
Pseudocode:
1. Get customer's age from user input.
2. Check to see the range.
3. If age <=5, then the price is 0x, x being the original ticket price.
4. If age >5 and <=12, then the price is .5x.
5. If age >12 and <=26, then the price is .9x.
6. If age >60, then the price is .75x.
7. Any other age is the original price, so basically any age (26, 60].

The program below calculates the ticket price based on age.
*/


#include <iostream>
#include <string>
using namespace std;

int main() {
// identifier declarations, declaring variables
double age; //age of customer
double originalprice =10; // orginal price of ticket
double price; // final price after discounts, if apllied
string discount; // discount variable

// display prompts and get input
cout<<"Enter your age: "<<endl;
cin>>age;

// calculations using if-else conditions
if (age<=5) {// 100% discount
  price = 0;
  discount = "100 percent";

} else if ((age>5) && (age<=12)) {// 50% discount
  price = 0.5* originalprice;
  discount = "50 percent";

} else if ((age>12) && (age<=26)) {// 10% discount
  price = 0.9* originalprice;
  discount = "10 percent";

} else if (age>60) {// 25% discount
  price = 0.75* originalprice;

} else
price=originalprice;
discount = "0 percent";

// display results final ticket price
cout<< "Your discount is "<<discount<<". "<<"Your ticket is going to be $"<<price<<"."<<endl;

  return 0;
}
