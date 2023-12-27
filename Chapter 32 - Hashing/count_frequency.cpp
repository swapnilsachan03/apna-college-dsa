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

  map<int, int> freq;
  for (int i = 0; i < n; i++) {
    freq[nums[i]] += 1;
  }

  map<int, int> :: iterator it;
  for (it = freq.begin(); it != freq.end(); it++) {
    cout << it->first << " -> " << it->second << endl;
  } 

  return 0;
}
