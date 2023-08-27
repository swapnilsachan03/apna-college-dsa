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

void evenAfterOdd (node* &head) {
  node* odd = head;
  node* even = head->next;
  node* evenStart = head->next;

  while(odd->next != nullptr && even->next != nullptr) {
    odd->next = even->next;
    odd = odd->next;
    even->next = odd->next;
    even = even->next;
  }

  odd->next = evenStart;
  if(odd->next == nullptr) {
    even->next = nullptr;
  }
}

int main()
{
  node* head = nullptr;

  int arr[] = {1,2,3,4,5,6,7};
  for (int i = 0; i < 7; i++)
  {
    insertAtTail(head, arr[i]);
  }

  printList(head);
  evenAfterOdd(head);
  printList(head);

  return 0;
}
