/* Applications of Catalan numbers:

-> Possible BSTs
-> Paranthesius / bracket combinations
-> Possible forests
-> Ways of triangulations
-> Possible paths in a matrix
-> Dividing a circle using n chords
-> Dyck words of given length & much more

Read more about catalan numbers and the expression for nth catalan number.

*/

#include <iostream>
using namespace std;

// The time complexity for this program is very high. We can optimize this code to O(n) complexity by using dynamic programming.

int catalan (int n) {
  if (n <= 1) return 1;

  int res = 0;
  for (int i = 0; i < n; i++) {
    res += catalan(i) * catalan(n-1-i);
  }

  return res;
}

int main()
{
  cout << "First 10 Catalan numbers are: ";

  for (int i = 0; i < 10; i++) {
    cout << catalan(i) << " ";
  }

  cout << endl;

  return 0;
}
