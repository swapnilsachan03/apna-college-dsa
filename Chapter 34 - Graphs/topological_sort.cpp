/*  A topological ordering is an ordering of nodes in a directed graph, where for each directed edge from node A to node B, node A appears before node B in the ordering.

Note:

-> Topological orderings are not unique, i.e. a graph can have multiple topological orderings.
-> Directed cyclic graphs cannot have a topological sort.
-> Only directed acyclic graphs (DAG) have a valid topological sort.

Terms:

Indegree -> The number of inward edges on a vertex in a directed graph.
Outdegree -> the number of outgoing edges from a vertex in a directed graph.

Algorithm:

While (all nodes are not visited)
  - Nodes with zero indegree can be added to the output array
  - All the nodes which are adjacent to the terminal nodes, get their indegree subtracted

*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
  int nodes, edges;
  cin >> nodes >> edges;

  vector<vector<int>> adj_list(nodes);
  vector<int> indegree (nodes, 0);

  for (int i = 0; i < edges; i++) {
    int x, y;
    cin >> x >> y;

    adj_list[x].push_back(y);
    indegree[y] += 1;
  }

  cout << endl << "Topological sort for the given graph is: \n" << endl;

  queue<int> q;
  for (int i = 0; i < nodes; i++) {
    if (indegree[i] == 0) q.push(i);
  }

  int count = 0;
  while (!q.empty()) {
    count += 1;

    int x = q.front();
    q.pop();

    cout << x << " ";

    for (auto it : adj_list[x]) {
      indegree[it] -= 1;
      if (indegree[it] == 0) q.push(it);
    }
  }

  return 0;
}
