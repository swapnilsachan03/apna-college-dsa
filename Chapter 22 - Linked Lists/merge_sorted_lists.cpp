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

void printList (node* head) {
  node* temp = head;

  while(temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }

  cout << endl;
}

node* mergeLists (node* &head1, node* &head2) {
  node* dummyNode = new node(INT32_MIN);

  node* p1 = head1;
  node* p2 = head2;
  node* p3 = dummyNode;

  while(p1 != nullptr && p2 != nullptr) {
    if(p1->data < p2->data) {
      p3->next = p1;
      p1 = p1->next;
    }
    else {
      p3->next = p2;
      p2 = p2->next;
    }

    p3 = p3->next;
  }

  while(p1 != nullptr) {
    p3->next = p1;
    p1 = p1->next;
    p3 = p3->next;
  }

  while(p2 != nullptr) {
    p3->next = p2;
    p2 = p2->next;
    p3 = p3->next;
  }

  return dummyNode->next;
}

node* mergeListsRecursive (node* &head1, node* &head2) {
  if(head1 == nullptr) return head2;
  if(head2 == nullptr) return head1;
  
  node* result;

  if(head1->data < head2->data) {
    result = head1;
    result->next = mergeListsRecursive(head1->next, head2);
  } else {
    result = head2;
    result->next = mergeListsRecursive(head1, head2->next);
  }

  return result;
}

int main()
{
  node* head1 = nullptr;
  node* head2 = nullptr;

  int arr1[] = {1,4,5,7};
  int arr2[] = {2,3,6};

  for(int i = 0; i < 4; i++) {
    insertAtTail(head1, arr1[i]);
  }

  for(int i = 0; i < 3; i++) {
    insertAtTail(head2, arr2[i]);
  }

  printList(head1);
  printList(head2);

  node* mergedHead = mergeLists(head1, head2);
  printList(mergedHead);

  return 0;
}
