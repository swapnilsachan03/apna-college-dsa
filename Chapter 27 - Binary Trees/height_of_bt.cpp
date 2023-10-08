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

int calcHeight (TreeNode* root) {
  if(root == nullptr) return 0;

  int lHeight = calcHeight(root->left);
  int rHeight = calcHeight(root->right);

  return max(lHeight, rHeight) + 1;
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

  cout << calcHeight(n) << endl;
  
  return 0;
}
