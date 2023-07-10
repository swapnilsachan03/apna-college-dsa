#include <iostream>
using namespace std;

string moveX (string s) {
  if(s.length() == 0) {
    return "";
  }

  char ch = s[0];
  string ans = moveX(s.substr(1));

  if(ch == 'x') {
    return ans + ch;
  } else {
    return ch + ans;
  }
}

int main()
{
  string str;
  cin >> str;

  cout << moveX(str) << endl;

  return 0;
}

// axxbdxcefxhix