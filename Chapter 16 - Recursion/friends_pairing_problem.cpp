// https://www.youtube.com/watch?v=VQVeAQVs1d8

#include <iostream>
using namespace std;

int friendsPairing (int n) {
  if(n == 0 || n == 1 || n == 2) {
    return n;
  }

  // We'll multiply the (n-2) function call with (n-1) because if two people are paired up, then there will be (n-1) people with whom a person can be paired up.

  return friendsPairing(n-1) + friendsPairing(n-2) * (n-1);
}

int main()
{
  int n;
  cin >> n;

  cout << friendsPairing(n);

  return 0;
}