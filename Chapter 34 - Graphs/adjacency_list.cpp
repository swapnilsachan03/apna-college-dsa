#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 2;
vector<int> adjl[N];      // Array of vectors

int main()
{
  int nodes, edges;
  cin >> nodes >> edges;

  for (int i = 0; i < edges; i++) {
    int x, y;
    cin >> x >> y;

    adjl[x].push_back(y);
    adjl[y].push_back(x);     // Undirected graph
  }

  cout << endl << "Adjacency list of the given graph is: " << endl << endl;

  for (int i = 1; i <= nodes; i++) {
    cout << i << " -> ";
    for (int x : adjl[i]) {
      cout << x << " ";
    }

    cout << endl;
  }

  return 0;
}
