#include <iostream>
using namespace std;

void bubbleSort(int* arr, int n) {
  int counter = 1;

  while(counter < n) {
    for(int i = 0; i < n-counter; i++) {
      if(arr[i] > arr[i+1]) {
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
      }
    }

    counter++;
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

  bubbleSort(arr, n);
  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  
  return 0;
}