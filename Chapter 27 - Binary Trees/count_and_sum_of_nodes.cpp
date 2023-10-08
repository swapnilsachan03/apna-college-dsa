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

int countNodes (TreeNode* root) {
  if(root == nullptr) return 0;
  return countNodes(root->left) + countNodes(root->right) + 1;
}

int sumOfNodes (TreeNode* root) {
  if(root == nullptr) return 0;
  return sumOfNodes(root->left) + sumOfNodes(root->right) + root->data;
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
  
  cout << countNodes(n) << endl;
  cout << sumOfNodes(n) << endl;

  return 0;
}
