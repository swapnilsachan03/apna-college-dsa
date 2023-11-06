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

// Case 1: Finding target nodes in the node's subtree

void printSubtreeNodes (TreeNode* root, int k) {
  if (root == nullptr || k < 0) return;

  if (k == 0) {
    cout << root->data << " ";
    return;
  }

  printSubtreeNodes(root->left, k-1);
  printSubtreeNodes(root->right, k-1);
}

// Case 2: Finding nodes moving towards ancestors and from down there

int printNodesAtK (TreeNode* root, TreeNode* target, int k) {
  if (root == nullptr) return -1;

  if (root == target) {
    printSubtreeNodes(root, k);
    return 0;
  }

  int dl = printNodesAtK(root->left, target, k);
  if (dl != -1) {
    if (dl + 1 == k) cout << root->data << " ";
    else printSubtreeNodes(root->right, k - dl - 2);
    
    return dl + 1;
  }

  int dr = printNodesAtK(root->right, target, k);
  if (dr != -1) {
    if (dr + 1 == k) cout << root->data << " ";
    else printSubtreeNodes(root->left, k - dr - 2);

    return dr + 1;
  }

  return -1;
}

int main()
{
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(5);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(6);
  root->right->left = new TreeNode(3);
  root->right->right = new TreeNode(4);
  root->left->left->right = new TreeNode(7);
  root->left->left->right->left = new TreeNode(8);
  root->left->left->right->right = new TreeNode(9);

  printNodesAtK(root, root->left, 3);
  cout << endl;
  
  return 0;
}
