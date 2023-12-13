#include <iostream>
#include <cmath>
using namespace std;

bool isPerfect (int x) {
  int sum = 1;

  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      if (i == x/i) sum += i;
      else sum += i + x/i;
    }
  }

  return x != 1 && sum == x;
}

int maxSum (int arr[], int n, int k) {
  if (n < k) {
    cout << "Invalid values" << endl;
    return -1;
  }

  int res = 0;
  for (int i = 0; i < k; i++) {
    res += arr[i];
  }

  int sum = res;
  for (int i = k; i < n; i++) {
    sum += arr[i] - arr[i-k];
    res = max(res, sum);
  }

  return res;
}

int maxPerfects (int arr[], int n, int k) {
  for (int i = 0; i < n; i++) {
    if (isPerfect(arr[i])) arr[i] = 1;
    else arr[i] = 0;
  }

  return maxSum(arr, n, k);
}

int main()
{
  int arr[] = { 28,2,3,6,496,99,8128,24 };
  int n = 8;
  int k = 4;

  cout << maxPerfects(arr, n, k);

  return 0;
}
