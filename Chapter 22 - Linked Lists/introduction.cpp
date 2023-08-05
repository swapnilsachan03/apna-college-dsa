#include <iostream>
using namespace std;

class node {
  public:
    int data;
    node* next;

    node(int val) {
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

void insertAtHead (node* &head, int val) {
  node* n = new node(val);
  n->next = head;
  head = n;
}

void deleteNode (node* &head, int val) {
  if(head == nullptr) {
    return;
  }

  node* temp = head;

  if(head->data == val || head->next == nullptr) {
    head = head->next;

    delete temp;
    return;
  }

  while(temp->next->data != val) {
    temp = temp->next;
  }

  node* toDelete = temp->next;
  temp->next = temp->next->next;

  delete toDelete;
}

void deleteAtHead (node* &head) {
  node* toDelete = head;
  head = head->next;

  delete toDelete;
}

bool searchList (node* head, int key) {
  node* temp = head;

  while(temp != nullptr) {
    if(temp->data == key) {
      return true;
    }

    temp = temp->next;
  }

  return false;
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
  insertAtTail(head, 2);
  insertAtTail(head, 1);
  insertAtTail(head, 4);
  insertAtTail(head, 5);
  insertAtHead(head, 12);

  printList(head);
  cout << searchList(head, 3) << endl;

  deleteNode(head, 4);
  printList(head);

  return 0;
}
