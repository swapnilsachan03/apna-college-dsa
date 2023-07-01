// https://www.geeksforgeeks.org/find-first-repeating-element-array-integers

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

  const int N = 1e6+2;
  int idx[N];

  for(int i = 0; i < N; i++) {
    idx[i] = -1;
  }

  int ans = INT16_MAX;

  for(int i = 0; i < n; i++) {
    if(idx[arr[i]] != -1) {
      ans = min(ans, idx[arr[i]]);
    } else {
      idx[arr[i]] = i;
    }
  }

  if(ans == INT16_MAX) {
    cout << "-1" << endl;
  } else {
    cout << ans + 1;
  }
  
  return 0;
}