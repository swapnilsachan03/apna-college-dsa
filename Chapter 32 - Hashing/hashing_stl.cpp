// Maps are internally implemented using red-black trees & unordered maps using hash tables

/*
  For maps:
    TC (accessing) = O(log n)
    TC (insertion) = O(log n) + rebalancing
    TC (deletion) = O(log n) + rebalancing
  
  For unordered maps:
    TC (accessing) = O(1) on average & O(n) in worst case
    TC (insertion) = same as search / access
    TC (deletion) = same as search / access
*/

#include <iostream>
#include <map>
using namespace std;

int main()
{
  map<int, int> mp;

  mp[8] = 2;
  cout << mp[8] << endl;

  return 0;
}
