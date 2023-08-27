#include <iostream>
using namespace std;

#define n 100

class stack {
  int* arr;
  int top;

  public:
    stack() {
      arr = new int[n];
      top = -1;
    }

    void push (int x) {
      if(top == n-1) {
        cout << "Stack overflow" << endl;
        return;
      }

      top++;
      arr[top] = x;
    }

    void pop() {
      if(top == -1) {
        cout << "Stack underflow" << endl;
        return;
      }

      top--;
    }

    int peek() {
      if(top == -1) {
        cout << "Stack is empty" << endl;
        return -1;
      }

      return arr[top];
    }

    bool isEmpty() {
      return top == -1;
    }

    bool isFull() {
      return top == n-1;
    }
};

int main()
{
  stack st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);

  cout << st.peek() << endl;
  st.pop();

  cout << st.peek() << endl;
  st.pop();
  st.pop();
  st.pop();
  st.pop();

  cout << st.peek() << endl;

  return 0;
}