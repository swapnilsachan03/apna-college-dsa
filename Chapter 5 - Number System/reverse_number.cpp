#include <iostream>
using namespace std;

int main()
{
  int n, rev = 0;
  cin >> n;

  while(n > 0) {
    int temp = n % 10;
    rev = rev * 10 + temp;
    n /= 10;
  }

  cout << "Reversed number is:" << rev << ".\n";

  return 0;
}