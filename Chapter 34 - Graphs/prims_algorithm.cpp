/* Idea:

  -> Select an arbitrary vertex S to start the tree from
  -> Follow steps 3 to 5 till there are vertices that are not included in the MST (known as fringe vertex)
  -> Find edges connecting any tree vertex with the fringe vertices
  -> Find the minimum among these edges
  -> Add the chosen edge to the MST if it does not form any cycle
  -> Return the MST and exit
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int primsMST (int n, vector<pair<int, int>> adj[]) {
  vector<bool> visited(n, false);

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({ 0, 0 });    // assuming graph includes vertex 0

  int cost = 0;

  while (!pq.empty()) {
    auto p = pq.top();
    pq.pop();

    int wt = p.first;
    int u = p.second;

    if (visited[u] == true) continue;

    cost += wt;
    visited[u] = true;

    for (auto v : adj[u]) {
      if (visited[v.first] == false) pq.push({ v.second, v.first });
    }
  }

  return cost;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> adj[n + 1];

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back({ v, w });
    adj[v].push_back({ u, w });
  }

  int ans = primsMST(n, adj);
  cout << endl << "Cost of MST is: " << ans << endl;

  return 0;
}
