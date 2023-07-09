#include <iostream>
using namespace std;

int getBit (int n, int pos) {
  return (n & (1 << pos)) != 0;
}

int setBit (int n, int pos) {
  return n | (1 << pos);
}

int clearBit (int n, int pos) {
  int mask = ~(1 << pos);
  return (n & mask);
}

int updateBit (int n, int pos, int bit) {
  int mask = ~(1 << pos);
  n = (n & mask);

  return n | (bit << pos);
}

int toggleBit (int n, int pos) {
  return (n xor (1 << pos));
}

int main()
{
  int n, pos;
  cin >> n >> pos;

  cout << getBit(n, pos) << endl;
  cout << setBit(n, pos) << endl;
  cout << clearBit(n, pos) << endl;
  cout << updateBit(n, pos, 1) << endl;
  cout << toggleBit(n, pos) << endl;

  return 0;
}