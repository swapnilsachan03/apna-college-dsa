// Output sum of all possible subarrays of a given array

#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;

  int arr[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for(int i = 0; i < n; i++) {
    int sum = 0;

    for(int j = i; j < n; j++) {
      sum += arr[j];
      cout << sum << " ";
    }
    cout << endl;
  }

  return 0;
}