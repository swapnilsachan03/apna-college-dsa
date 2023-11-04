// Given a binary tree, flatten it into a linked ist in-place. After flattening, left of each node should point to nullptr ans right should contain next node in preorder sequence. It's not allowed to use other data structures.

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

void flattenTree (TreeNode* root) {
  if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
    return;
  }

  if (root->left != nullptr) {
    flattenTree(root->left);

    TreeNode* temp = root->right;
    root->right = root->left;
    root->left = nullptr;

    TreeNode* t = root->right;
    while (t->right != nullptr) {
      t = t->right;
    }

    t->right = temp;
  }

  flattenTree(root->right);
}

void printInorder (TreeNode* root) {
  if (root == nullptr) return;

  printInorder(root->left);
  cout << root->data << " ";
  printInorder(root->right);
}

int main()
{
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(9);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->right = new TreeNode(6);

  flattenTree(root);
  printInorder(root);
  cout << endl;

  return 0;
}
