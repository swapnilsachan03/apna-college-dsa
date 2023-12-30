// You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that they can only work on a single activity at a time.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<pair<int, int>> act(n);
  for (int i = 0; i < n; i++) {
    cin >> act[i].first >> act[i].second;
  }

  // The below custom comparator will sort the activities in ascending order of their ending times

  sort(act.begin(), act.end(), [&](pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
  });

  int take = 1;
  int end = act[0].second;

  for (int i = 1; i < n; i++) {
    if (act[i].first >= end) {
      take += 1;
      end = act[i].second;
    }
  }

  cout << "Maximum number of activities: " << take << endl;

  return 0;
}
