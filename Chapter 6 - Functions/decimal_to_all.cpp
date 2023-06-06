#include <iostream>
using namespace std;

int decimalToBinary(int n) {
  int x = 1, ans = 0;

  while(x <= n) {
    x *= 2;
  }

  x /= 2;   // because at last iteration, x would've exceeded n.

  while(x > 0) {
    
  }
}

int main()
{
  int n;
  cin >> n;

  cout << decimalToBinary(n) << endl;

  return 0;
}