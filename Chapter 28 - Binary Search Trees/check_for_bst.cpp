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

// Two approaches, first is to compare each node with the minimum value from its right subtree and maximum value from its left subtree. In this case, we'll have to traverse the tree again and again. Its optimization is in code below. TC for below approach = O(n)

bool isBST (TreeNode* root, TreeNode* min = nullptr, TreeNode* max = nullptr) {
  if (root == nullptr) return true;

  if (min != nullptr && root->data <= min->data) {
    return false;
  }

  if (max != nullptr && root->data >= max->data) {
    return false;
  }

  bool leftValid = isBST(root->left, min, root);
  bool rightValid = isBST(root->right, root, max);

  return leftValid && rightValid;
}

int main()
{
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  TreeNode* validRoot = new TreeNode(5);
  validRoot->left = new TreeNode(2);
  validRoot->right = new TreeNode(8);

  if(isBST(root)) {
    cout << "Valid BST" << endl;
  } else {
    cout << "Invalid BST" << endl;
  }

  if(isBST(validRoot)) {
    cout << "Valid BST" << endl;
  } else {
    cout << "Invalid BST" << endl;
  }

  return 0;
}
