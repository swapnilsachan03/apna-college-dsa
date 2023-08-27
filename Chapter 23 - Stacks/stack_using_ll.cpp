#include <iostream>
using namespace std;

class node {
  public:
    int data;
    node *next;

    node(int val)
    {
      data = val;
      next = NULL;
    }
};

// We're inserting the elements at the head of the linked list to implement stacks, because then it will be easier to access the next element when popping.

class stack {
  node *top;

  public:
    stack() {
      top = NULL;
    }

    void push(int x) {
      node *n = new node(x);
      n->next = top;
      top = n;
    }

    void pop() {
      if (top == NULL) {
        cout << "Stack underflow" << endl;
        return;
      }

      node *toDelete = top;
      top = top->next;

      delete toDelete;
    }

    int peek() {
      if (top == NULL) {
        cout << "Stack empty" << endl;
        return -1;
      }

      return top->data;
    }

    bool isEmpty() {
      return top == NULL;
    }
};

int main()
{
  stack st;
  st.push(1);
  st.push(2);
  st.push(3);

  cout << st.peek() << endl;
  st.pop();
  cout << st.peek() << endl;
  st.pop();
  st.pop();
  st.pop();

  cout << st.isEmpty() << endl;

  return 0;
}
