#include <iostream>
#include <map>
using namespace std;

map<int, int> parent;
map<int, int> size;

// naive implementation -> O(n) -> long chains can be formed, leading to this complexity

void make (int v) {
  parent[v] = v;
}

int findSet (int v) {
  if (v == parent[v]) return v;
  return findSet(parent[v]);
}

void unionSets (int a, int b) {
  a = findSet(a);
  b = findSet(b);

  if (a != b) parent[b] = a;
}

// path compression -> O(log n)

int findSetPathCompression (int v) {
  if (v == parent[v]) return v;
  return parent[v] = findSet(parent[v]);
}

// union by size / rank -> O(α(n)) i.e. nearly O(1), α is inverse Ackermann function

void makeBySize (int v) {
  parent[v] = v;
  size[v] = 1;
}

void unionSetsBySize (int a, int b) {
  a = findSet(a);
  b = findSet(b);

  if (a != b) {
    if (size[a] < size[b]) swap(a, b);    // making a the larger set

    parent[b] = a;
    size[a] += size[b];
  }
}

// driver code

int main()
{
  cout << "This is union find" << endl;
  return 0;
}
