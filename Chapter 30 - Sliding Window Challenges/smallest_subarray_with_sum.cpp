#include <iostream>
using namespace std;

int smallestSubarray (int n, int arr[], int x) {
  int ans = n + 1;
  int sum = 0, start = 0;

  for (int i = 0; i < n; i++) {
    sum += arr[i];

    while (sum > x && start < n) {
      ans = min(ans, i - start + 1);
      sum -= arr[start];
      start += 1;
    }
  }

  return ans;
}

int main()
{
  int n = 5;
  int arr[n] = { 1, 10, 3, 40, 18 };
  int x = 50;

  int ans = smallestSubarray(n, arr, x);

  if (ans == n + 1) cout << "No such subarray exists" << endl;
  else cout << "Size of smallest subarray with sum > " << x << ": " << ans << endl;

  return 0;
}
