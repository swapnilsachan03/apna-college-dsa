#include <iostream>
#include <set>
using namespace std;

int main()
{
  set<int> st;

  st.insert(1);
  st.insert(2);
  st.insert(2);
  st.insert(3);
  
  for (auto i : st) {
    cout << i << " ";
  }

  cout << endl;
  cout << st.size() << endl;

  st.erase(2);

  for (auto i : st) {
    cout << i << " ";
  }

  cout << endl;
  cout << st.size() << endl << endl;
  
  multiset<int> mst;

  mst.insert(1);
  mst.insert(3);
  mst.insert(3);
  mst.insert(3);
  mst.insert(5);
  
  for (auto i : mst) {
    cout << i << " ";
  }

  cout << endl;
  cout << mst.size() << endl;

  // mst.erase(3); will erase all occurences of 3 from the multiset

  mst.erase(mst.find(3));
  for (auto i : mst) {
    cout << i << " ";
  }

  cout << endl;
  cout << mst.size() << endl;

  return 0;
}
