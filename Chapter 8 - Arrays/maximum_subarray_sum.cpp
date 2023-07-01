// https://www.geeksforgeeks.org/print-the-maximum-subarray-sum/

#include <iostream>
using namespace std;

// Brute-force approach: Using the idea from previous problem, get the sum of all subarrays and print the maximum from it. We'll use cumulative sum approach O(n^2) for this problem.

int main()
{
  int n;
  cin >> n;

  int arr[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int currSum[n + 1];
  currSum[0] = 0;

  for(int i = 1; i <= n; i++) {
    currSum[i] = currSum[i-1] + arr[i-1];
  }

  int maxSum = INT16_MIN;
  for(int i = 1; i <= n; i++) {
    int sum = 0;

    for(int j = 0; j < i; j++) {
      sum = currSum[i] - currSum[j];
      maxSum = max(sum, maxSum);
    }
  }

  cout << maxSum << endl;

  return 0;
}

// Using Kadane's Algorithm

int main()
{
  int n;
  cin >> n;

  int arr[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int currSum = 0, maxSum = INT16_MIN;

  for(int i = 0; i < n; i++) {
    currSum += arr[i];
    if (currSum < 0) currSum = 0;
    maxSum = max(maxSum, currSum);
  }

  cout << maxSum << endl;

  return 0;
}