#include <iostream>
using namespace std;

int binaryToDecimal(int n) {
  int ans = 0, x = 1;

  while(n > 0) {
    int y = n % 10;
    ans += x * y;
    x *= 2;
    n /= 10;
  }

  return ans;
}

int octalToDecimal(int n) {
  int ans = 0, x = 1;

  while(n > 0) {
    int y = n % 10;
    ans += x * y;
    x *= 8;
    n /= 10;
  }

  return ans;
}

int hexToDecimal(string n) {
  int ans = 0, x = 1;
  int s = n.size();

  for(int i = s-1; i >= 0; i--) {
    if(n[i] >= '0' && n[i] <= '9') {
      ans += x * (n[i] - '0');
    }

    else if(n[i] >= 'a' && n[i] <= 'f') {
      ans += x * (n[i] - 'a' + 10);
    }

    x *= 16;
  }

  return ans;
}

int main()
{
  int binary, octal;
  string hex;
  cin >> binary >> octal >> hex;

  cout << binaryToDecimal(binary) << endl;
  cout << octalToDecimal(octal) << endl;
  cout << hexToDecimal(hex) << endl;

  return 0;
}