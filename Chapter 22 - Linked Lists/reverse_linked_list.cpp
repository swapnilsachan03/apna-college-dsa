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

node* reverseList (node* head) {
  node* prev = nullptr;
  node* curr = head;
  node* next;

  while(curr != nullptr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}

node* reverseListRecursive (node* head) {
  if(head->next == nullptr || head == nullptr) {
    return head;
  }

  node* newHead = reverseListRecursive(head->next);
  head->next->next = head;
  head->next = nullptr;

  return newHead;
}

int main()
{
  node* head = new node(1);
  insertAtTail(head, 2);
  insertAtTail(head, 3);
  insertAtTail(head, 4);

  head = reverseList(head);
  printList(head);

  head = reverseListRecursive(head);
  printList(head);

  return 0;
}
