/* Spanning Tree:

  Given an undirected and connected graph G(V, E), a spanning tree of the graph G is a tree that spans G (that is, it includes every vertex of G) and is a subgraph of G (every edge in the tree belongs to G).

  Cost of the spanning tree: The cost of the spanning tree is the sum of weights of all the edges in the tree.
  There can be many spanning trees for a graph.

  Minimum Spanning Tree: A MST is the spanning tree whose cost is minimum among all the spanning trees. There can be many MSTs for a graph.

  Kruskal's Algorithm for finding a MST in a graph:

  1. Sort the edges in the increasing order of their weights
  2. Iterate ove the sorted edges: if inclusion of ith edge leads to a cycle, then skip this edge, else, include this edge in the MST.

  Time Complexity: O(E log V)
  Space Complexity: O(E + V)
*/

#include <iostream>
#include <vector>
#include <algorithm>
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
  for (int i = 0; i < N; i++) {
    make_set(i);
  }

  int n, m;
  cin >> n >> m;

  vector<vector<int>> edges;

  for (int i = 0; i < m; i++) {
    int u, v, w;

    cin >> u >> v >> w;
    edges.push_back({ w, u, v });
  }

  sort(edges.begin(), edges.end());

  int cost = 0;

  for (auto it : edges) {
    int w = it[0], u = it[1], v = it[2];

    int x = find_set(u);
    int y = find_set(v);

    if (x != y) {
      union_sets(x, y);
      cout << u << " --> " << v << " = " << w << "\n";
      cost += w;
    }
  }

  cout << cost << endl;

  return 0;
}
