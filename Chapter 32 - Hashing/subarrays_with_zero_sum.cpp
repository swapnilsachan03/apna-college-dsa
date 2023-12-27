#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> nums (n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  map<int, int> count;
  int prefixSum = 0;

  for (int i = 0; i < n; i++) {
    prefixSum += nums[i];
    count[prefixSum] += 1;
  }

  int ans = 0;
  map<int, int> :: iterator it;

  for (it = count.begin(); it != count.end(); it++) {
    int c = it->second;
    ans += c * (c - 1) / 2;

    if (it->first == 0) {
      ans += it->second;
    }
  }

  cout << ans << endl;

  return 0;
}
