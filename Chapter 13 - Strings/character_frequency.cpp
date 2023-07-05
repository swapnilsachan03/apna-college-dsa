#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  string s = "ijfdvnsdlsdnvksd";

  int freq[26] = {0};

  for(int i = 0; i < s.length(); i++) {
    freq[s[i] - 'a']++;
  }

  char ans = 'a';
  int maxF = 0;

  for(int i = 0; i < 26; i++) {
    if(freq[i] > maxF) {
      maxF = freq[i];
      ans = i + 'a';
    }
  }

  cout << ans << " " << maxF << endl;

  return 0;
}