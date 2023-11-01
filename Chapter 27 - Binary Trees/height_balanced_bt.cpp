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

int height (TreeNode* root) {
  if(root == nullptr) return 0;

  int lHeight = height(root->left);
  int rHeight = height(root->right);

  return max(lHeight, rHeight) + 1;
}

void printInorder (TreeNode* root) {
  if(root == nullptr) return;

  printInorder(root->left);
  cout << root->data << " ";
  printInorder(root->right);
}

bool isBalancedBrute (TreeNode* root) {
  if(root == nullptr) return true;

  if(isBalancedBrute(root->left) == false) return false;
  if(isBalancedBrute(root->right) == false) return false;

  int lh = height(root->left);
  int rh = height(root->right);

  if(abs(lh - rh) <= 1) return true;
  else return false;
}

bool isBalanced (TreeNode* root, int* h) {
  if(root == nullptr) {
    return true;
    *h = 0;
  }

  int lh = 0, rh = 0;

  if(isBalanced(root->left, &lh) == false) return false;
  if(isBalanced(root->right, &rh) == false) return false;

  *h = max(lh, rh) + 1;

  if(abs(lh - rh) <= 1) return true;
  else return false;
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

  int h = 0;

  if(isBalancedBrute(n)) cout << "Balanced tree" << endl;
  else cout << "Unbalanced tree" << endl;

  if(isBalanced(n, &h)) cout << "Balanced tree" << endl;
  else cout << "Unbalanced tree" << endl;

  return 0;
}
