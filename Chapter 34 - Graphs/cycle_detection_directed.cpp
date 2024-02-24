/* Cycle detection in an undirected graph:

-> Mark the current node as visited and also mark the index in recursion stack
-> Find all the vertices which are not visited and are adjacent to the current node
-> If the adjacent vertices are already marked in the recursion stack then a cycle is found  */

#include <iostream>
#include <vector>
using namespace std;

bool isCycle (int src, vector<vector<int>> &adj_list, vector<bool> &visited, vector<bool> &stack) {
  stack[src] = true;

  if (!visited[src]) {
    visited[src] = true;

    for (auto i : adj_list[src]) {
      if (!visited[i] && isCycle(i, adj_list, visited, stack)) return true;
      if (stack[i]) return true;
    }
  }

  stack[src] = false;
  return false;
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
  }

  bool cycle = false;

  vector<bool> stack (nodes, 0);
  vector<bool> visited (nodes, false);

  for (int i = 0; i < nodes; i++) {
    if (!visited[i] && isCycle(i, adj_list, visited, stack)) {
      cycle = true;
      break;
    }
  }

  if (cycle) cout << endl << "Cycle is found" << endl;
  else cout << endl << "Cycle is not present" << endl;

  return 0;
}
