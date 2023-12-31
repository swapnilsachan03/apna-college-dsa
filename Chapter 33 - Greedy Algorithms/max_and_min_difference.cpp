// You are given an array, A, of n elements. You have to remove exactly n/2 elements from A and add it to another array B (initially empty). Find the maximum and minimum values of differences between those two arrays. We define the difference between the two arrays as sum(abs(A[i] - B[i])).

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  sort(nums.begin(), nums.end());
  long long mn = 0, mx = 0;

  for (int i = 0; i < n / 2; i++) {
    mx += abs(nums[i] - nums[n - i - 1]);
  }

  for (int i = 0; i < n - 1; i += 2) {
    mn += abs(nums[i] - nums[i + 1]);
  }

  /* Alternatively, a better approach:

  For obtaining maximum, we've to subtract sum of first n/2 elements from sum of last n/2, and for odd, we've to subtract sum of even - indexed elements from sum of odd - indexed elements.

  for (int i = 0; i < n / 2; i++) {
    mx += a[i + n/2] + a[i];
    mn += a[2*i + 1] - a[2*i];
  }

  */

  cout << mn << " " << mx << endl;

  return 0;
}
