#include <iostream>
#include <queue>
using namespace std;

class stack {
  int n;
  queue<int> q1;
  queue<int> q2;

  public:
    stack() {
      n = 0;
    }

    void push (int val) {
      q2.push(val);
      n++;

      while(!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
      }

      queue<int> temp = q1;
      q1 = q2;
      q2 = temp;
    }

    void pop() {
      if(n == 0 || q1.empty()) {
        cout << "Stack underflow ";
        return;
      }

      q1.pop();
      n--;
    }

    int top() {
      if(n == 0 || q1.empty()) {
        cout << "Stack underflow ";
        return INT32_MIN;
      }

      return q1.front();
    }

    int size() {
      return n;
    }
};

int main()
{
  stack st;

  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  
  cout << st.top() << endl;
  st.pop();

  cout << st.top() << endl;
  st.pop();
  cout << st.top() << endl;
  st.pop();
    cout << st.top() << endl;
  st.pop();

  cout << st.size() << endl;

  return 0;
}
