/* Cycle detection in an undirected graph:

-> Keep on traversing the graph
-> If you find an edge pointing to an already visited node (except the parent node), a cycle is found  */

#include <iostream>
#include <vector>
using namespace std;

bool isCycle (int src, vector<vector<int>> &adj_list, vector<bool> &visited, int parent) {
  visited[src] = true;

  for (auto i : adj_list[src]) {
    if (i != parent) {
      if (visited[i]) return true;
      if (!visited[i] && isCycle(i, adj_list, visited, src)) return true;
    }
  }

  return false;
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

  bool cycle = false;
  vector<bool> visited (nodes, false);

  for (int i = 0; i < nodes; i++) {
    if (!visited[i] && isCycle(i, adj_list, visited, -1)) {
      cycle = true;
      break;
    }
  }

  if (cycle) cout << endl << "Cycle is present" << endl;
  else cout << "Cycle is not present" << endl;

  return 0;
}
