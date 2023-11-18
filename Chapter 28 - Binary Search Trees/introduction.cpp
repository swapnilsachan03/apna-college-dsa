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

void printInorder (TreeNode* root) {
  if (root == nullptr) return;

  printInorder(root->left);
  cout << root->data << " ";
  printInorder(root->right);
}

TreeNode* insertBST (TreeNode* root, int val) {
  if (root == nullptr) {
    return new TreeNode(val);
  }

  if (val < root->data) root->left = insertBST(root->left, val);
  else root->right = insertBST(root->right, val);

  return root;
}

int main()
{
  int n;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  TreeNode* root = nullptr;
  for (int i = 0; i < n; i++) {
    root = insertBST(root, arr[i]);
  }
  
  printInorder(root);
  cout << endl;

  return 0;
}
