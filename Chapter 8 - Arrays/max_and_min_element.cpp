#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int arr[n];

  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int minNo = INT16_MAX, maxNo = INT16_MIN;

  for(int i = 0; i < n; i++) {
    minNo = min(minNo, arr[i]);
    maxNo = max(maxNo, arr[i]);
  }

  cout << "Minimum element: " << minNo << endl;
  cout << "Maximum element: " << maxNo << endl;

  return 0;
}