#include <iostream>
using namespace std;

void fillArray(int a[], int size, int& numberUsed);
void sort(int a[], int numberUsed);
void swapValues(int& v1, int& v2);
int indexOfSmallest(const int a[], int startIndex, int numberUsed);


int main () {
  int numused=0;
  int a[50];
  fillArray(a, 50, numused);
  cout<<endl;
  sort(a, numused);
  cout<<endl;
  int i=0, count, current, j;
  cout<<"N"<<"  "<<"Count"<<endl;
  while(i<numused) {
    count=0;
    current=a[i];
    j=i;
    while(a[j]==current&&(j<numused)) {
      count++;
      j++;
    }
    cout<<a[i]<<"  "<<count<<endl;
    i=i+count;
  }
  cout<<endl;
  return 0;
}


void fillArray(int a[], int size, int& numberUsed) {
  cout << "Enter fewer than " << size << " nonnegative whole numbers.\n" << "Mark the end of the list with a negative number.\n";
  int next, index = 0;
  cin >> next;
  while ((next >= 0) && (index < size)) {
    a[index] = next;
    index++;
    cin >> next;
  }
    numberUsed=index;
}

void swapValues(int& v1, int& v2) {
  int temp;
  temp = v1;
  v1 = v2;
  v2 = temp;
}

int indexOfSmallest(const int a[], int startIndex, int numberUsed) {
   int min = a[startIndex];
   int indexOfMin = startIndex;
   for (int index = startIndex + 1; index < numberUsed; index++) {
      if (a[index] < min) {
          min = a[index];
          indexOfMin = index;
          //min is the smallest of a[startIndex] through a[index]
      }
    }
    return indexOfMin;
 }

void sort(int a[], int numberUsed) {
  int indexOfNextSmallest;
  for (int i = 0; i < numberUsed-1; i++) {//Place the correct value in a[index]:
    indexOfNextSmallest = indexOfSmallest(a, i, numberUsed);
    swapValues(a[i], a[indexOfNextSmallest]);
  //a[0] <= a[1] <= ... <= a[index] are the smallest of the //original array elements. The rest of the
  //elements are in the remaining positions.
  }
}
