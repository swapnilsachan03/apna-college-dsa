#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  cout << endl;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= i; j++) {
      cout << i + 1 << " ";
    }

    cout << endl;
  }

  return 0;
}