// We are given n items with {weight, value} of each item and the capacity of knapsack W. We need to put these items in knapsack such that final value of items in knapsack is maximum.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare (pair<int, int> p1, pair<int, int> p2) {
  double v1 = (double) p1.first / p1.second;
  double v2 = (double) p2.first / p2.second;

  return v1 > v2;
}

int main()
{
  int n;
  cin >> n;

  vector<pair<int, int>> items(n);

  for (int i = 0; i < n; i++) {
    cin >> items[i].first >> items[i].second;
  }

  int w;
  cin >> w;

  sort(items.begin(), items.end(), compare);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (w >= items[i].second) {
      ans += items[i].first;
      w -= items[i].second;
    }

    else {
      double vw = (double) items[i].first / items[i].second;
      ans += vw * w;
      w = 0;  break;
    }
  }

  cout << "Maximum achievable value: " << ans << endl;

  return 0;
}
