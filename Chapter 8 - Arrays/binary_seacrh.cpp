#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
  int start = 0, end = n - 1;

  while(start <= end) {
    int mid = (start + end) / 2;

    if(key == arr[mid]) {
      return mid;
    } else if(key < arr[mid]) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  return -1;
}

int main()
{
  int n;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int key;
  cin >> key;

  if(binarySearch(arr, n, key) != -1) {
    cout << "Element found in array at position " << binarySearch(arr, n, key) + 1 << ".\n";
  } else {
    cout << "Element not found in the array." << endl;
  }

  return 0;
}