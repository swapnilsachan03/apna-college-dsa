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

int listLength (node* head) {
  int len = 0;
  node* temp = head;

  while(temp != nullptr) {
    len++;
    temp = temp->next;
  }

  return len;
}

node* kAppend (node* &head, int k) {
  node* newHead;
  node* newTail;
  node* tail = head;

  int len = listLength(head);
  k = k % len;
  int curr = 1;

  while(tail->next != nullptr) {
    if(curr == len - k) {
      newTail = tail;
      newHead = tail->next;
    }

    tail = tail->next;
    curr++;
  }

  newTail->next = nullptr;
  tail->next = head;

  return newHead;
}

int main()
{
  node* head = nullptr;

  int arr[] = {1,2,3,4,5,6,7};
  for(int i = 0; i < 7; i++) {
    insertAtTail(head, arr[i]);
  }

  printList(head);

  node* appended = kAppend(head, 5);
  printList(appended);

  return 0;
}
