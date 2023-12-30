// You are given n files with their computation times in an array. We have  to choose any two files, add their computation times and append it to the list of computation times (cost = sum of computation times). Do this until we are left with only one file in the array. We have to do this operation such that we get minimum final cost.

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin >> n;
  
  vector<int> files(n);
  for (int i = 0; i < n; i++) {
    cin >> files[i];
  }

  priority_queue<int, vector<int>, greater<int>> mh; 
  for (int i = 0; i < n; i++) {
    mh.push(files[i]);
  }

  int ans = 0;

  while (mh.size() > 1) {
    int f1 = mh.top();
    mh.pop();
    int f2 = mh.top();
    mh.pop();

    ans += f1 + f2;
    mh.push(f1 + f2);
  }

  cout << "Minimum cost for merging files: " << ans << endl;
  return 0;
}