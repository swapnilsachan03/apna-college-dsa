#include <iostream>
#include <vector>
using namespace std;

int N = 1e5+6;

vector<int> parent(N);
vector<int> size(N);

void make_set (int v) {
  parent[v] = v;
  size[v] = 1;
}

int find_set (int v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets (int a, int b) {
  a = find_set(a);
  b = find_set(b);

  if (a != b) {
    if (size[a] < size[b]) swap(a, b);

    parent[b] = a;
    size[a] += size[b];
  }
}

int main()
{
  for (int i = 0; i < N; i++) make_set(i);

  int n;
  cin >> n;

  vector<vector<int>> edges;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;

    edges.push_back({ x, y });
  }

  bool cycle = false;

  for (auto it : edges) {
    int u = it[0];
    int v = it[1];

    if (find_set(u) == find_set(v)) {
      cycle = true;
      break;
    }

    else union_sets(u, v);
  }

  if (cycle) cout << "Graph contains a cycle" << endl;
  else cout << "Graph does not contain a cycle" << endl;

  return 0;
}
