#include <iostream>
using namespace std;

class TreeNode {
  public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
      data = val;
      left = nullptr;
      right = nullptr;
    }
};

void printInorder (TreeNode* root) {
  if(root == nullptr) return;

  printInorder(root->left);
  cout << root->data << " ";
  printInorder(root->right);
}

void sumReplace (TreeNode* root) {
  if(root == nullptr) return;

  sumReplace(root->left);
  sumReplace(root->right);

  if(root->left != nullptr) {
    root->data += root->left->data;
  }

  if(root->right != nullptr) {
    root->data += root->right->data;
  }
}

int main()
{
  TreeNode* n = new TreeNode(1);
  n->left = new TreeNode(2);
  n->right = new TreeNode(3);
  n->left->left = new TreeNode(4);
  n->left->right = new TreeNode(5);
  n->right->left = new TreeNode(6);
  n->right->right = new TreeNode(7);

  printInorder(n);
  cout << endl;

  sumReplace(n);

  printInorder(n);
  cout << endl;

  return 0;
}
