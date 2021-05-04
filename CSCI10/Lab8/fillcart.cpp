

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
  string titles[100];
  int titlesize;
  Date releaseDate;
  string status;
};

double fillCart(Item a[], int sz);

double fillCart(Item a[], int sz) {
  double total=0.0;
  for (int j=0; j<sz; j++) {
    if (a[j].status=="purchase") {
      total+=a[j].price;
    }
  }
  return total;
}


int main() {
  int size=8;
  string a;
  Item shopping[8]={
  {"Beyoncé", "Beyoncé", 11.99, {"Pretty Hurts", "Haunted", "Drunk in Love", "Blow", "No Angel", "Partition", "Jealous", "Rocket", "Mine", "XO", "Flawless", "Superpower", "Heaven", "Blue", "Ghost"}, 15,
  {13, 12, 2013}, "empty"},
  {"Harry Potter Book Series", "J. K. Rowling", 52.99, {"The Philosopher's Stone", "The Chamber of Secrets", "The Prisoner of Azkaban", "The Goblet of Fire", "The Order of the Phoenix", "The Half-Blood Prince", "The Deathly Hallows"}, 7, {21, 7, 2007}, "empty"},
  {"The Greatest Showman Soundtrack", "Joseph Trapanese and John Debney", 9.99, {"The Greatest Show", "A Million Dreams", "Come Alive", "The Other Side", "Never Enough", "This is Me", "Rewrite the Stars", "Tightrope", "From Now On"}, 9, {8, 12, 2017}, "empty"},
  {"Invasion of Privacy", "Cardi B", 7.99, {"Get Up 10", "Drip", "Bickenhead", "Bodak Yellow", "Be Careful [Explicit]", "Best Life", "I Like It [Explicit]", "Ring", "Money Bag", "Bartier Cardi (feat. 21 Savage)", "She Bad", "Thru Your Phone", "I Do"}, 13, {5, 4, 2018}, "empty"},
  {"Shrek: Motion Picture Soundtrack", "The Broadway Singers, Choir & Orchestra", 9.69, {"Stay Home", "I'm a Believer", "Like Wow!", "It Is You (I Have Loved)", "Best Years of Our Lives", "Bad Reputation", "My Beloved Monster", "You Belong to Me", "All Star", "Hallelujah", "I'm on My Way", "True Love's First Kiss"}, 12, {14, 5, 2001}, "empty"},
  {"Hannah Montana 2: Meet Miley Cyrus", "Miley Cyrus", 10.49, {"We Got the Party", "Nobody's Perfect", "Make Some Noise", "Rock Star", "Old Blue Jeans", "Life's What You Make It", "One in a Million", "Bigger Than Us", "You and Me Together", "True Friend", "See You Again", "East Northumberland High", "Let's Dance", "G.N.O. (Girl's Night Out)", "Right Here", "As I Am",
  "Start All Over", "Clear", "Good and Broken", "I Miss You"}, 20, {6, 26, 2007}, "empty"},
  {"Melodrama", "Lorde", 10.99, {"Green Light", "Sober [Explicit]", "Homemade Dynamite", "The Louvre", "Liability", "Hard Feelings/Loveless [Explicit]", "Sober II (Melodrama) [Explicit]", "Writer in the Dark", "Supercut", "Liability (reprise)", "Perfect Places [Explicit]"}, 11, {16, 6, 2017}, "empty"},
  {"Sweetener", "Ariana Grande", 11.79, {"raindrops (an angel cried)", "blazed (feat. Pharell Williams)", "The Light is Coming", "R.E.M", "God is a woman", "sweetener", "successful", "everytime", "breathin", "No Tears Left to Cry", "borderline (feat. Missy Elliot)", "better off", "goodnight n go", "pete davidson", "get well soon"}, 15,
  {13, 7, 2018}, "empty"}
  };
  cout<<endl;
  cout<<"This program will ask the user if they would like to buy a certain book or music album, and fill a virtual shopping cart according to their responses with the individual prices of each item they buy. Then, at the end, the user will see the total cost of their individual purchases displayed."<<endl;
  cout<<endl;
  for (int i=0; i<size; i++) {
    cout<<"Item "<<i+1<<": "<<shopping[i].name<<", by "<<shopping[i].creator<<", for $"<<shopping[i].price<<endl;
    cout<<"Would you like to 'purchase', see more 'details', or 'pass'?"<<endl;
    cin>>a;
    if (a=="purchase") {
			shopping[i].status="purchase";
      cout<<endl;
    }
    if (a=="pass") {
      cout<<"Item not purchased."<<endl;
      cout<<endl;
    }
    if (a!="purchase" && a!="details" && a!="pass") {
      cout<<"Please enter a valid response if you would like to fill the cart."<<endl;
      cout<<endl;
    }
    if (a=="details") {
      cout<<endl;
      cout<<"Name: "<<shopping[i].name<<endl;
      cout<<"By: "<<shopping[i].creator<<endl;
      cout<<"Price: "<<shopping[i].price<<endl;
      cout<<"Contents: ";
      for (int k=0; k<shopping[i].titlesize; k++) {
        cout<<shopping[i].titles[k]<<", ";
      }
      cout<<endl;
      cout<<"Released: "<<shopping[i].releaseDate.day<<"/"<<shopping[i].releaseDate.month<<"/"<<shopping[i].releaseDate.year<<endl;
      cout<<endl;
      cout<<"Would you like to 'purchase' or 'pass'?"<<endl;
      cin>>a;
      if (a=="pass") {
        cout<<"Item not purchased."<<endl;
        cout<<endl;
      }
      if (a=="purchase") {
  			shopping[i].status="purchase";
        cout<<endl;
      }
      if (a!="purchase" && a!="pass") {
        cout<<"Please enter a valid response if you would like to fill the cart."<<endl;
        cout<<endl;
      }
    }
  }
  cout<<"Items purchased: ";
  for (int h=0; h<size; h++) {
    if (shopping[h].status=="purchase") {
      cout<<shopping[h].name<<", ";
    }
  }
  cout<<endl;
  cout<<"Total cost: $"<<fillCart(shopping, size)<<endl;
  cout<<"Thank you for your purchases!"<<endl;
  cout<<endl;
  return 0;
}
