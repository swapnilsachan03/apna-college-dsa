/* Bipartite graphs:

-> Its vertices can be divided into two disjoint and independent sets U and V such that every edge connects a vertex in U to one in V
-> The graph does not any odd - length cycles
-> The graph is two colorable

How to check for a bipartite graph?

-> Traverse the graph
-> If the current node is of red colour, paint its neighbours as blue

If you are able to color the graph successfully without any recoloring of nodes, then the graph is bipartite.

*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void color (vector<vector<int>> &adj_list, vector<bool> &visited, vector<int> &colors, int i, int toColor, bool &bipartite) {
  if (colors[i] != -1 && colors[i] != toColor) {
    bipartite = false;
    return;
  }

  colors[i] = toColor;

  if (visited[i]) return;
  visited[i] = true;

  for (auto it : adj_list[i]) {
    color(adj_list, visited, colors, it, toColor ^ 1, bipartite);
  }
}

int main()
{
  int nodes, edges;
  cin >> nodes >> edges;

  vector<vector<int>> adj_list (nodes);

  for (int i = 0; i < edges; i++) {
    int x, y;
    cin >> x >> y;

    adj_list[x].push_back(y);
    adj_list[y].push_back(x);
  }

  vector<bool> visited (nodes, false);
  vector<int> colors (nodes, -1);

  bool bipartite = true;

  for (int i = 0; i < nodes; i++) {
    if (!visited[i]) {
      color(adj_list, visited, colors, i, 0, bipartite);
    }
  }

  if (bipartite == true) cout << endl << "Given graph is bipartite" << endl;
  else cout << endl << "Given graph is not bipartite" << endl;

  return 0;
}
