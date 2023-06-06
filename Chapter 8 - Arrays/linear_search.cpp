#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
  for(int i = 0; i < n; i++) {
    if(arr[i] == key) {
      return i;
    }
  }

  return -1;
}

int main()
{
  int n;
  cin >> n;

  int arr[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int key;
  cin >> key;

  if(linearSearch(arr, n, key) != -1) {
    cout << "Element found in array at position " << linearSearch(arr, n, key) + 1 << ".\n";
  } else {
    cout << "Element not found in the array." << endl;
  }

  return 0;
}