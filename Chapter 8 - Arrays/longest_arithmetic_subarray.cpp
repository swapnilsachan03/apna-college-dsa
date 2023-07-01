/* Problem links:
    https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff47/00000000003bf4ed
    https://www.geeksforgeeks.org/longest-subarray-forming-an-arithmetic-progression-ap/
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

  int pd = arr[1] - arr[0], curr = 2, mx = 2; 

  for(int i = 2; i < n; i++) {
    if(arr[i] - arr[i-1] == pd) {
      curr++;
    } else {
      curr = 2;
      pd = arr[i] - arr[i-1];
    }

    mx = max(mx, curr);
  }

  cout << "Maximum arithmetic subarray length: " << mx << endl;

  return 0;
}