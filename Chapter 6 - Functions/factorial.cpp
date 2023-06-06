#include <iostream>
using namespace std;

int fact(int n) {
  int ans = 1;

  for(int i = 2; i <= n; i++) {
    ans *= i;
  }

  return ans;
}

int main()
{
  int n;
  cin >> n;

  cout << fact(n) << endl;

  return 0;
}