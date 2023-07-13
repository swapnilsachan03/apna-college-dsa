// There's an STL trick for this too, see it online

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ans;

void permutations (vector<int> &arr, int idx) {
  if(idx == arr.size()) {
    ans.push_back(arr);
    return;
  }

  for(int i = idx; i < arr.size(); i++) {
    swap(arr[i], arr[idx]);
    permutations(arr, idx+1);
    swap(arr[i], arr[idx]);
  }

  return;
}

int main()
{
  int n;
  cin >> n;

  vector<int> arr(n);
  for(auto &i : arr) {
    cin >> i;
  }

  permutations(arr, 0);

  for(auto i : ans) {
    for(auto j : i) {
      cout << j << " ";
    }

    cout << endl;
  }

  return 0;
}
