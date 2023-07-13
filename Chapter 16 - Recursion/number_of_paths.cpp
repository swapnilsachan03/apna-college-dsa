// https://www.youtube.com/watch?v=9rt-hFcXd0M

#include <iostream>
using namespace std;

int countPaths (int s, int e) {
  if(e == s) {
    return 1;
  }

  if(s > e) {
    return 0;
  }

  int count = 0;
  for(int i = 1; i <= 6; i++) {
    count += countPaths(s+i, e);
  }

  return count;
}

int main()
{
  int a, b;
  cin >> a >> b;

  cout << countPaths(a, b) << endl;

  return 0;
}