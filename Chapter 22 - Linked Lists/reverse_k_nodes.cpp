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

node* reverseKNodes (node* &head, int k) {
  node* prev = nullptr;
  node* curr = head;
  node* next;

  int count = 0;
  while(curr != nullptr && count < k) {
    next = curr->next;
    curr->next = prev;

    prev = curr;
    curr = next;
    count++;
  }

  if(next != nullptr) {
    head->next = reverseKNodes(next, k);
  }

  return prev;
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

  printList(head);
  node* newHead = reverseKNodes(head, 2);
  printList(newHead);

  return 0;
}
