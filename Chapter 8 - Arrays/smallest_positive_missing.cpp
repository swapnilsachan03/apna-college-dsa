// https://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/

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

  bool present[n+1] = { false };

  for(int i = 0; i < n; i++) {
    if(arr[i] > 0 && arr[i] <= n) {
      present[arr[i]] = true;
    }
  }

  int ans = -1;

  for(int i = 1; i <= n; i++) {
    if(present[i] == false) {
      ans = i;
      break;
    }
  }

  cout << ans;

  return 0;
}