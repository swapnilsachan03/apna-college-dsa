#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int, int>

using namespace std;

int main()
{
  int k;
  cin >> k;

  vector<vector<int>> nums (k);

  for (int i = 0; i < k; i++) {
    int size;
    cin >> size;

    nums[i] = vector<int> (size);

    for (int j = 0; j < size; j++) {
      cin >> nums[i][j];
    }
  }

  vector<int> idx (k, 0);
  priority_queue<pii, vector<pii>, greater<pii>> pq;

  for (int i = 0; i < k; i++) {
    pq.push({ nums[i][0], i });
  }

  vector<int> ans;

  while (!pq.empty()) {
    pii x = pq.top();
    pq.pop();

    ans.push_back(x.first);

    if (idx[x.second] + 1 < nums[x.second].size()) {
      pq.push({ nums[x.second][idx[x.second] + 1], x.second });
    }

    idx[x.second] += 1;
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  cout << endl;

  return 0;
}
