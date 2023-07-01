/* Problem links:
    https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387171
    https://www.geeksforgeeks.org/google-kick-round-d-question-2020/
*/

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

  int mx = INT16_MIN, ans = 0;
  for(int i = 0; i < n; i++) {
    if(arr[i] > mx && (arr[i] > arr[i+1] || i == n-1)) {
      ans++;
    }

    mx = max(mx, arr[i]);
  }

  cout << "Number of record breaking days: " << ans;

  return 0;
}