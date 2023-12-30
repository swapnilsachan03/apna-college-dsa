#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;

  vector<int> nums (n);

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int sum = 0, ans = INT32_MAX;
  for (int i = 0; i < k; i++) {
    sum += nums[i];
  }

  ans = min(ans, sum);
  for (int i = k; i < n; i++) {
    sum += nums[i] - nums[i - k];
    ans = min(sum, ans);
  }

  cout << ans << endl;

  return 0;
}
