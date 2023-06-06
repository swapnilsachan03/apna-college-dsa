#include <iostream>
using namespace std;

void selectionSort(int* arr, int n) {
  for(int i = 0; i < n-1; i++) {
    for(int j = i+1; j < n; j++) {
      if(arr[j] < arr[i]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main()
{
  int n;
  cin >> n;

  int* arr = new int[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << endl << "Sorted array: ";

  selectionSort(arr, n);
  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  
  return 0;
}