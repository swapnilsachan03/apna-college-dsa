#include <iostream>
using namespace std;

class node {
  public:
    int data;
    node* next;

    node (int val) {
      data = val;
      next = nullptr;
    }
};

class queue {
  node* front;
  node* back;

  public:
    queue() {
      front = nullptr;
      back = nullptr;
    }

    void enqueue (int x) {
      node* n = new node(x);

      if(front == nullptr) {
        back = n;
        front = n;
      }

      back->next = n;
      back = n;
    }

    void dequeue() {
      if(front == nullptr) {
        cout << "Queue underflow." << endl;
        return;
      }

      node* toDelete = front;
      front = front->next;

      delete toDelete;
    }

    int peek() {
      if(front == nullptr) {
        cout << "Queue empty." << endl;
        return INT32_MIN;
      }

      return front->data;
    }


    bool isEmpty() {
      if(front == nullptr) return true;
      return false;
    }
};

int main()
{
  queue q;

  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);

  while(!q.isEmpty()) {
    cout << q.peek() << " ";
    q.dequeue();
  }

  cout << endl << q.isEmpty() << endl;

  return 0;
}
