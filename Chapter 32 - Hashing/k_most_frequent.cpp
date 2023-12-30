// We have to output elements in decreasing order of frequency till we reach (k+1)th distinct element

#include <iostream>
#include <algorithm>
#include <map>
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

  map<int, int> mp;

  for (int i = 0; i < n; i++) {
    if (mp[nums[i]] == 0 && mp.size() == k) break;
    mp[nums[i]] += 1;
  }

  vector<pair<int, int>> ans;
  map<int, int> :: iterator it;

  for (it = mp.begin(); it != mp.end(); it++) {
    if (it->second != 0) ans.push_back({ it->second, it->first });
  }

  sort(ans.begin(), ans.end(), greater<pair<int, int>>());
  vector<pair<int, int>> :: iterator pt;

  for (pt = ans.begin(); pt != ans.end(); pt++) {
    cout << pt->second << " -> " << pt->first << endl;
  }

  return 0;
}
