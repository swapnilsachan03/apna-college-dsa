#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int n;
  cin >> n;

  bool flag = true;

  for(int i = 2; i < sqrt(n); i++) {
    if(n%i == 0) {
      cout << "Number is not prime." << endl;
      flag = false;
      break;
    }
  }

  if(flag == true) {
    cout << "Number is prime.";
  }

  return 0;
}