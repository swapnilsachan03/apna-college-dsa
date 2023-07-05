#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  string str = "asdfghjklryu";

  // convert into uppercase

  for(int i = 0; i < str.length(); i++) {
    if(str[i] >= 'a' && str[i] <= 'z') {
      str[i] -= 32;
    }
  }

  // STL: transform(str.begin(), str.end(), str.begin(), ::toupper);
  cout << "Uppercase string: " << str << endl;

  // convert into lowercase

  for(int i = 0; i < str.length(); i++) {
    if(str[i] >= 'A' && str[i] <= 'Z') {
      str[i] += 32;
    }
  }

  // STL: transform(str.begin(), str.end(), str.begin(), ::tolower);
  cout << "Lowercase string: " << str << endl;

  return 0;
}