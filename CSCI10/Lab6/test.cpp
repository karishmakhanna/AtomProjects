#include <iostream>
using namespace std;
bool f2(int a[], int n, int target, int& index);

int main(){
    int arr[5];
    int target;
    int index = 0;

    cout << " Enter array elements: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << " x[" << i << "]: ";
        cin >> arr[i];
    }

    cout << " Enter target to search for : ";
    cin >> target;

    if (f2(arr, 5, target, index))
        cout << " Target " << target << " found in index " << index << endl;
    else
        cout << " NOT found ! " << endl;

    return 0;
}

bool f2(int a[], int N, int target, int& index){

    int j = 0;
    while (j < N)
    {
        if (target == a[j]) {
            index = j;
            cout << "list[" << j << "]" << endl;
            return true;
        }
        j++;
    }
    return false;
}
