#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int n, sum = 0;
  cin >> n;

  int original = n;

  while(n > 0) {
    int last = n % 10;
    sum += round(pow(last, 3));
    n /= 10;
  }

  if(sum == original) {
    cout << "Number is an Armstrong number." << endl;
  } else {
    cout << "Not an Armstrong number." << endl;
  }

  return 0;
}