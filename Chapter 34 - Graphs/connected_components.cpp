/* A connected component is a subgraph in which any two vertices are connected to each other by paths, and which is connected to no additional vertices in the supergraph.

Idea:

-> Visit the nodes in a defth-first fashion
-> If the node is not visited, visit that node and its neighbours recursively

Every time an unvisited node is found, a new component will be found */

#include <iostream>
#include <vector>
using namespace std;

int getComponent (int src, vector<vector<int>> &adj_list, vector<bool> &visited) {
  if (visited[src]) return 0;

  visited[src] = true;
  int ans = 1;

  for (auto i : adj_list[src]) {
    if (!visited[i]) {
      ans += getComponent(i, adj_list, visited);
      visited[i] = true;
    }
  }

  return ans;
}

int main()
{
  int nodes, edges;
  cin >> nodes >> edges;

  vector<vector<int>> adj_list(nodes);

  for (int i = 0; i < edges; i++) {
    int x, y;
    cin >> x >> y;

    adj_list[x].push_back(y);
    adj_list[y].push_back(x);
  }

  vector<bool> visited (nodes, false);
  vector<int> components;

  for (int i = 0; i < nodes; i++) {
    if (!visited[i]) {
      components.push_back(getComponent(i, adj_list, visited));
    }
  }

  cout << endl << "Graph has " << components.size() << " connected components with size: ";

  for (auto i : components) {
    cout << i << " ";
  }

  return 0;
}
