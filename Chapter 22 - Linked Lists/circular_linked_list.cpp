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

void insertAtHead (node* &head, int val) {
  node* n = new node(val);
  node* temp = head;

  if(head == nullptr) {
    head = n;
    n->next = n;
    return;
  }

  while(temp->next != head) {
    temp = temp->next;
  }

  temp->next = n;
  n->next = head;
  head = n;
}

void insertAtTail (node* &head, int val) {
  if(head == nullptr) {
    insertAtHead(head, val);
    return;
  }

  node* n = new node(val);
  node* temp = head;

  while(temp->next != head) {
    temp = temp->next;
  }

  temp->next = n;
  n->next = head;
}

void deleteAtHead (node* &head) {
  node* temp = head;

  while(temp->next != head) {
    temp = temp->next;
  }

  node* toDelete = head;
  temp->next = head->next;
  head = head->next;

  delete toDelete;
}

void deleteNode (node* &head, int pos) {
  if(pos == 1) {
    deleteAtHead(head);
    return;
  }

  node* temp = head;
  int curr = 1;

  while(curr != pos-1) {
    temp = temp->next;
    curr++;
  }

  node* toDelete = temp->next;
  temp->next = toDelete->next;

  delete toDelete;
}

void printList (node* head) {
  node* temp = head;

  do {
    cout << temp->data << " ";
    temp = temp->next;
  } while(temp != head);

  cout << endl;
}

int main()
{
  node* head = nullptr;

  insertAtTail(head, 1);
  insertAtTail(head, 2);
  insertAtTail(head, 3);
  insertAtTail(head, 4);
  printList(head);

  insertAtHead(head, 5);
  printList(head);

  deleteNode(head, 1);
  printList(head);

  return 0;
}
