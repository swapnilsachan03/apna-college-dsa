#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  cout << endl;

  for(int i = 1; i <= n; i++) {
    int idx = 1;

    for(int j = i; j <= n; j++) {
      cout << idx << " ";
      idx++;
    }

    cout << endl;
  }

  return 0;
}

// One more approach to this question is that instead of taking a variable for counting each row, we can initiate j with one and print till (n-i+1).