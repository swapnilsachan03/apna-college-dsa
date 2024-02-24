/* There are N friends numbered from 0 to N-1. You have to choose 2 people such that they are not related to each other. You are given information in the form of M pairs (x, y), i.e. there is a link between friend x and y.

Find out the number of ways in which two people from different groups can be chosen. */

#include <iostream>
#include <vector>
using namespace std;

int getComponent (int src, vector<vector<int>> &adj_list, vector<bool> &visited) {
  if (visited[src]) return 0;

  visited[src] = true;
  int ans = true;

  for (auto i : adj_list[src]) {
    if (!visited[i]) {
      ans += getComponent(i, adj_list, visited);
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

  long long ans = 0;

  for (auto i : components) {
    ans += i * (nodes - i);
  }

  cout << endl << "Number of ways to choose two unconnnected people: " << ans / 2;

  return 0;
}
