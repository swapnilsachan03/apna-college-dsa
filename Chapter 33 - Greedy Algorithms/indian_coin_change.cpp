// You are given an array of denominations and a value X. You need to find the minimum number of coins required to make value X. Assume that we have an infinite supply of each coin.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;

  vector<int> coins(n);
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  sort(coins.begin(), coins.end(), greater<int>());

  int ans = 0;
  for (int i = 0; i < coins.size(); i++) {
    int times = x / coins[i];
    ans += times;
    x -= times * coins[i];
  }

  cout << "Minimum number of coins: " << ans << endl;

  return 0;
}
