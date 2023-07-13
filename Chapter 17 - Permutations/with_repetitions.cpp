#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void helper (vector<int> arr, vector<vector <int>> &ans, int idx) {
  if(idx == arr.size()) {
    ans.push_back(arr);
    return;
  }

  for(int i = idx; i < arr.size(); i++) {
    if(i != idx && arr[i] == arr[idx]) {
      continue;
    }

    swap(arr[i], arr[idx]);
    helper(arr, ans, idx+1);
  }
}

vector <vector <int>> permutations (vector <int> arr) {
  sort(arr.begin(), arr.end());
  vector<vector <int>> ans;

  helper(arr, ans, 0);

  return ans;
}

int main()
{
  int n;
  cin >> n;

  vector<int> arr(n);
  for(auto &i : arr) {
    cin >> i;
  }

  vector<vector <int>> ans = permutations(arr);
  for(auto i : ans) {
    for(auto j : i) {
      cout << j << " ";
    }

    cout << endl;
  }

  return 0;
}
