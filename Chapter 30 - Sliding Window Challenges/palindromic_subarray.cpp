#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPalindrome (int x) {
  int temp = x, num = 0;

  while (temp > 0) {
    num = num * 10 + temp % 10;
    temp = temp / 10;
  }

  if (num == x) return true;
  return false;
}

int palindromicSubarray (vector<int> arr, int k) {
  int num = 0;

  for (int i = 0; i < k; i++) {
    num = num * 10 + arr[i];
  }

  if (isPalindrome(num)) return 0;

  for (int i = k; i < arr.size(); i++) {
    num = (num % (int) pow(10, k-1)) * 10 + arr[i];

    if (isPalindrome(num)) {
      return i-k+1;
    }
  }

  return -1;
}

int main()
{
  vector<int> arr = {2,3,5,1,1,5};
  int k = 4;

  int ans = palindromicSubarray(arr, k);

  if (ans == -1) cout << "No such subarray exists" << endl;

  else {
    for (int i = ans; i < ans + k; i++) {
      cout << arr[i] << " ";
    }

    cout << endl;
  }

  return 0;
}
