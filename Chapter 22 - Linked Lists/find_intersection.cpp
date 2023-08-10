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

void intersect (node* &head1, node* &head2, int pos) {
  node* temp1 = head1;
  pos--;

  while(pos--) {
    temp1 = temp1->next;
  }

  node* temp2 = head2;
  while(temp2->next != nullptr) {
    temp2 = temp2->next;
  }

  temp2->next = temp1;
}

int intersection (node* &head1, node* &head2) {
  int l1 = listLength(head1);
  int l2 = listLength(head2);
  int d = 0;

  node* ptr1;
  node* ptr2;

  if(l1 > l2) {
    d = l1 - l2;
    ptr1 = head1;
    ptr2 = head2;
  } else {
    d = l2 - l1;
    ptr1 = head2;
    ptr2 = head1;
  }

  while(d && ptr1) {
    ptr1 = ptr1->next;
    if(ptr1 == nullptr) return -1;
    d--;
  }

  while(ptr1 != nullptr && ptr2 != nullptr) {
    if(ptr1 == ptr2) return ptr1->data;

    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

  return -1;
}

int main()
{
  node* head1 = nullptr;
  node* head2 = nullptr;

  insertAtTail(head1, 1);
  insertAtTail(head1, 2);
  insertAtTail(head1, 3);
  insertAtTail(head1, 4);
  insertAtTail(head1, 5);
  insertAtTail(head1, 6);
  insertAtTail(head2, 9);
  insertAtTail(head2, 10);

  intersect(head1, head2, 4);
  printList(head1);
  printList(head2);

  cout << intersection(head1, head2);

  return 0;
}
