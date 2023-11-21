#include <iostream>
using namespace std;

class TreeNode {
  public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode (int val) {
      data = val;
      left = nullptr;
      right = nullptr;
    }
};

void printPreorder (TreeNode* root) {
  if (root == nullptr) return;

  cout << root->data << " ";
  printPreorder(root->left);
  printPreorder(root->right);
}

TreeNode* sortedArrayToBST (int arr[], int st, int end) {
  if (st > end) return nullptr;

  int mid = (st + end) / 2;

  TreeNode* root = new TreeNode(arr[mid]);
  root->left = sortedArrayToBST(arr, st, mid - 1);
  root->right = sortedArrayToBST(arr, mid + 1, end);

  return root;
}

int main()
{
  int arr[] = {1,2,3,4,5,6,7,8};

  TreeNode* root = sortedArrayToBST(arr, 0, 7);
  printPreorder(root);

  cout << endl;

  return 0;
}
