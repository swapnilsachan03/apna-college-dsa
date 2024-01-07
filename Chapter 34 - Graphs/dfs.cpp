#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5+2;
bool vis[N];
vector<int> adjl[N];

void dfs (int node) {
  vis[node] = true;
  cout << node << " ";

  vector<int> :: iterator it;
  for (it = adjl[node].begin(); it != adjl[node].end(); it++) {
    if (!vis[*it]) dfs(*it);
  }
}

int main()
{
  int nodes, edges;
  cin >> nodes >> edges;

  for (int i = 0; i <= nodes; i++) vis[i] = false;

  int x, y;
  for (int i = 0; i < edges; i++) {
    cin >> x >> y;

    adjl[x].push_back(y);
    adjl[y].push_back(x);
  }

  dfs(1);

  return 0;
}
