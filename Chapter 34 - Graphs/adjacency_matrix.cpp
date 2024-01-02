#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int nodes, edges;
  cin >> nodes >> edges;

  vector<vector<int>> adjm(nodes + 1, vector<int> (nodes + 1, 0));
  for (int i = 0; i < edges; i++) {
    int x, y;
    cin >> x >> y;

    adjm[x][y] = 1;
    adjm[y][x] = 1;    // Undirected graph
  }

  cout << endl << "Adjacency matrix for the given undirected graph is: \n" << endl;

  for (int i = 1; i <= nodes; i++) {
    for (int j = 1; j <= nodes; j++) {
      cout << adjm[i][j] << " ";
    }

    cout << endl;
  }

  // We can check for an edge between two vertices in O(1) time using adjacency matrix

  if (adjm[3][7]) {
    cout << endl << "There exists an edge between 3 and 7" << endl;
  }

  return 0;
}
