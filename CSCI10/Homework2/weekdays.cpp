/*
weekdays.cpp
csci10- section 01 -hw2

Created by Karishma Khanna on 10/02/18.
Pseudocode:
1. Get a number from 0 to 6 inclusive from the user, which represent the days of the week.
2. For each case, assign a day. 0 is Sunday, and 6 is Saturday.
3. Output the day based on the number.
4. If a number is entered outside 0-6, rint an error message.
5. Dsiplay result.


The program below displays the weekday based on an integer 0-6 inclusive.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
  //identifier declarations
  int day; //day of the week
  string weekday; // Name of the week's days
  //display prompts and get input
  cout << "Which day of the week is it, 0 through 6, Sunday through Saturday, respectively?"<<endl;
  cin>> day;

  //calculations
  switch(day) {
    case 0: {
      weekday = "Sunday"; // if 0, then print Sunday
      break;
    }
    case 1: {
      weekday = "Monday"; // if 1, then print Monday
      break;
    }
    case 2: {
      weekday = "Tuesday"; // if 2, then print Tuesday
      break;
    }
    case 3: {
      weekday = "Wednesday"; // if 3, then print Wednesday
      break;
    }
    case 4: {
      weekday = "Thursday"; // if 4, then print Thursday
      break;
    }
    case 5: {
      weekday = "Friday"; // if 5, then print Friday
      break;
    }
    case 6: {
      weekday = "Satuday"; // if 6, then print Saturday
      break;
  }
    default: {
      weekday = "not able to be displayed. Please print an integer between 0 and 6, inclusive"; // other values are Unknown
      break;
    }
}

cout<< "The day today is "<<weekday<<"."<<endl;

return 0;
}
