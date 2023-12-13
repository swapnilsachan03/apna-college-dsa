#include <iostream>
#include <vector>
using namespace std;

void computeNumber (vector<int> arr, int k) {
  pair<int, int> ans;
  int sum = 0;

  for (int i = 0; i < k; i++) {
    sum += arr[i];
  }

  bool found = false;

  if (sum % 3 == 0) {
    ans = make_pair(0, k-1);
    found = true;
  }

  for (int i = k; i < arr.size(); i++) {
    if (found) break;

    sum += arr[i] - arr[i - k];

    if (sum % 3 == 0) {
      ans = make_pair(i - k + 1, i);
      found = true;
    }
  }

  if (!found) {
    cout << "No such subarray exists" << endl;
  }

  else {
    for (int i = ans.first; i <= ans.second; i++) {
      cout << arr[i];
    }

    cout << endl;
  }
}

int main()
{
  int k = 4;
  vector<int> arr = {8,23,45,12,56,4};

  computeNumber(arr, k);

  return 0;
}
