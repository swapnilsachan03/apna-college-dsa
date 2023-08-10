#include <iostream>
using namespace std;

class node {
  public:
    int data;
    node* prev;
    node* next;

    node (int val) {
      data = val;
      prev = nullptr;
      next = nullptr;
    }
};

void insertAtHead (node* &head, int val) {
  node* n = new node(val);

  n->next = head;
  if(head != nullptr) head->prev = n;

  head = n;
}

void insertAtTail (node* &head, int val) {
  if(head == nullptr) {
    insertAtHead(head, val);
    return;
  }

  node* n = new node(val);
  node* temp = head;

  while(temp->next != nullptr) {
    temp = temp->next;
  }

  temp->next = n;
  n->prev = temp;
}

void deleteAtHead (node* &head) {
  node* toDelete = head;

  head = head->next;
  head->prev = nullptr;

  delete toDelete;
}

void deleteNode (node* &head, int pos) {
  if(pos == 1) {
    deleteAtHead(head);
    return;
  }

  node* temp = head;
  int count = 1;

  while(count != pos && temp != nullptr) {
    temp = temp->next;
    count++;
  }

  temp->prev->next = temp->next;
  if(temp->next != nullptr) temp->next->prev = temp->prev;

  delete temp;
}

void printList (node* head) {
  node* temp = head;

  while(temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }

  cout << endl;
}

int main()
{
  node* head = nullptr;

  insertAtTail(head, 1);
  insertAtTail(head, 2);
  insertAtTail(head, 3);
  insertAtTail(head, 4);
  insertAtHead(head, 5);

  printList(head);

  deleteNode(head, 3);
  deleteNode(head, 1);

  printList(head);

  return 0;
}
