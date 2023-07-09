// https://www.geeksforgeeks.org/count-set-bits-in-an-integer/

#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;

  int count = 0;
  while(n) {
    n = n & n-1;
    count++;
  }

  cout << count <<endl;

  return 0;
}