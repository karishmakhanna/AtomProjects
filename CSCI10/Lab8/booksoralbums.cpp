
#include <iostream>
#include <string>
using namespace std;

struct Date {
  int day;
  int month;
  int year;
};

struct Item {
  string name;
  string creator;
  double price;
  int titlesize;
  string titles[100];
  Date releaseDate;
};

void initializeItem(Item& it);
void printItem(Item it);

int main() {
  Item it;
  cout<<endl;
  cout<<"This program will read in information about a book or music album from the user, then display the inputted information on the screen."<<endl;
  cout<<endl;
  initializeItem(it);
  cout<<endl;
  printItem(it);
  cout<<endl;
  return 0;
}

void printItem(Item it) {
  cout<<"RESULTS:"<<endl;
  cout<<"The name of the item is: "<<it.name<<endl;
  cout<<"The name of the author/artist is: "<<it.creator<<endl;
	cout<<"The price of the item is: $"<<it.price<<endl;
	cout<<"The list of chapters/tracks from the item are: "<<endl;
  for (int i=0; i<it.titlesize; i++) {
    cout<<"Chapter/Track "<<i+1<<": "<<it.titles[i]<<endl;
  }
	cout<<"The release date of the item (DD/MM/YYYY) is: "<<it.releaseDate.day<<"/"<<it.releaseDate.month<<"/"<<it.releaseDate.year<<endl;
}

void initializeItem(Item& it) {
  cout<<"Enter the name of the book or music album: ";
  getline(cin, it.name);
  cout<<"Enter the name of the author/artist: ";
  getline(cin, it.creator);
	cout<<"Enter the price of the book or music album: $";
  cin>>it.price;
  cout<<"Enter how many chapters or tracks are in your book or music album: ";
  cin>>it.titlesize;
	cout<<"Enter the list of chapters/tracks."<<endl;
  cin.ignore();
  for (int i=0; i<it.titlesize; i++) {
    cout<<"Chapter/Track "<<i+1<<": ";
    getline(cin, it.titles[i]);
  }
	cout<<"Enter the release date of the book or music album."<<endl;
  cout<<"Date(DD): ";
  cin>>it.releaseDate.day;
  cout<<"Month(MM): ";
  cin>>it.releaseDate.month;
  cout<<"Year(YYYY): ";
  cin>>it.releaseDate.year;
}
