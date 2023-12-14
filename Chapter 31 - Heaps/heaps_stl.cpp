/*  Push & pop: O(log n)
    Top & size: O(1)
*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
  priority_queue<int, vector<int>> pq;

  pq.push(3);
  pq.push(5);
  pq.push(2);
  pq.push(4);

  cout << pq.top() << " ";
  
  pq.pop();
  cout << pq.top() << endl;

  priority_queue<int, vector<int>, greater<int>> pqm;

  pqm.push(3);
  pqm.push(5);
  pqm.push(2);
  pqm.push(4);

  cout << pqm.top() << " ";
  
  pqm.pop();
  cout << pqm.top() << endl;

  return 0;
}
