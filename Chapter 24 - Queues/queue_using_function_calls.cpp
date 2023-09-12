#include <iostream>
#include <stack>
using namespace std;

class queue {
  stack<int> s;
  stack<int> s2;

  public:
    void push (int x) {
      s.push(x);
    }

    int pop() {
      if(s.empty()) {
        cout << "Queue empty." << " ";
        return INT32_MIN;
      }

      int x = s.top();
      s.pop();

      if(s.empty()) return x;

      int item = pop();
      s.push(x);

      return item;
    }

    bool isEmpty() {
      if(s.empty()) return true;
      return false;
    }
};

int main()
{
  queue q;

  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);

  cout << q.pop() << endl;

  q.push(5);
  cout << q.pop() << endl;

  cout << q.pop() << endl;
  cout << q.pop() << endl;
  cout << q.pop() << endl;
  cout << q.pop() << endl;

  return 0;
}
