#include <iostream>
using namespace std;

#define n 25

class queue {
  int* arr;
  int front;
  int back;

  public:
    queue() {
      arr = new int[n];
      front = -1;
      back = -1;
    }

    void enqueue (int x) {
      if(back == n-1) {
        cout << "Queue overflow." << endl;
        return;
      }

      arr[++back] = x;
      if(front == -1) front++;
    }

    void dequeue() {
      if(front == -1 || front > back) {
        cout << "Queue enpty." << endl;
        return;
      }

      front++;
    }

    int peek() {
      if(front == -1 || front > back) {
        cout << "Queue empty." << endl;
        return INT32_MIN;
      }

      return arr[front];
    }

    bool isEmpty() {
      if(front == -1 || front > back) {
        return true;
      }

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
