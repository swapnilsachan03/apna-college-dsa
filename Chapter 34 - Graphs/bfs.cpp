#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 1e5+2;
bool vis[N];
vector<int> adjl[N];

int main()
{
  for (int i = 0; i < N; i++) vis[i] = false;

  int nodes, edges;
  cin >> nodes >> edges;

  int x, y;
  for (int i = 0; i < edges; i++) {
    cin >> x >> y;

    adjl[x].push_back(y);
    adjl[y].push_back(x);     // Undirected graph
  }

  queue<int> q;
  q.push(1);
  vis[1] = true;

  cout << endl << "BFS of the given graph is: ";

  while (!q.empty()) {
    int node = q.front();

    q.pop();
    cout << node << " ";

    for (int i : adjl[node]) {
      if (!vis[i]) {
        vis[i] = true;
        q.push(i);
      }
    }
  }

  cout << endl << endl;

  return 0;
}
