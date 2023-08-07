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

void insertAtTail (node* &head, int val) {
  node* n = new node(val);

  if(head == nullptr) {
    head = n;
    return;
  }

  node* temp = head;
  while(temp->next != nullptr) {
    temp = temp->next;
  }

  temp->next = n;
}

void printList (node* head) {
  node* temp = head;

  while(temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }

  cout << endl;
}

void makeCycle (node* head, int pos) {
  node* temp = head;
  node* startNode;

  int count = 1;
  while(temp->next != nullptr) {
    if(count == pos) {
      startNode = temp;
    }

    temp = temp->next;
    count++;
  }

  temp->next = startNode;
}

bool detectCycle (node* &head) {
  node* slow = head;
  node* fast = head;

  while(fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast) {
      return true;
    }
  }
}

void removeCycle (node* &head) {
  node* slow = head;
  node* fast = head;

  do {
    slow = slow->next;
    fast = fast->next->next;
  } while (slow != fast);

  fast = head;

  while(slow->next != fast->next) {
    slow = slow->next;
    fast = fast->next;
  }

  slow->next = nullptr;
}

int main()
{
  node* head = new node(1);
  insertAtTail(head, 2);
  insertAtTail(head, 3);
  insertAtTail(head, 4);
  insertAtTail(head, 5);
  insertAtTail(head, 6);
  insertAtTail(head, 7);

  cout << detectCycle(head) << endl;
  makeCycle(head, 4);
  cout << detectCycle(head) << endl;

  removeCycle(head);
  cout << detectCycle(head) << endl;
  printList(head);

  return 0;
}
