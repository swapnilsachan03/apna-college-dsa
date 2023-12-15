#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;

  vector<int> nums (n);
  for (int i = 0; i < n ; i++) {
    cin >> nums[i];
  }

  priority_queue<int, vector<int>> pq;
  for (int i = 0; i < n; i++) {
    pq.push(nums[i]);
  }

  int sum = 0;
  int count = 0;

  while (!pq.empty()) {
    sum += pq.top();
    pq.pop();
    
    count += 1;

    if (sum >= k) break;
  }

  if (sum < k) {
    cout << "No such subsequnce exists";
  }

  else {
    cout << "Length of subsequence: " << count << endl;
  }

  return 0;
}
