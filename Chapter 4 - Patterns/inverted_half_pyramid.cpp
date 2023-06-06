#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  cout << endl;

  while (n > 0)
  {
    for(int i = n; i > 0; i--) {
      cout << "* ";
    }

    cout << endl;
    n--;
  }
  
  return 0;
}