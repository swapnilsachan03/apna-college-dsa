/* For each node, store the following information:

-> size of the subtree
-> min value in its subtree
-> max value in its subtree
-> size of larget BST
-> isBST

Strategy: Recursively, traverse the tree in a bottom-up manner and find out the size of the largest BST.

*/

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

struct info {
  int size;
  int max;
  int min;
  int ans;
  bool isBST;
};

info largestBST (TreeNode* root) {
  if (root == nullptr) {
    return { 0, INT32_MIN, INT32_MAX, 0, true };
  }

  if (root->left == nullptr && root->right == nullptr) {
    return { 1, root->data, root->data, 1, true };
  }

  info left = largestBST(root->left);
  info right = largestBST(root->right);

  info curr;

  curr.size = 1 + left.size + right.size;

  if (left.isBST && right.isBST && left.max < root->data && right.min > root->data) {
    curr.max = max(root->data, max(left.max, right.max));
    curr.min = min(root->data, min(left.min, right.min));

    curr.isBST = true;
    curr.ans = curr.size;
  }

  else {
    curr.ans = max(left.ans, right.ans);
    curr.isBST = false;
  }

  return curr;
}

int main()
{
  TreeNode* root = new TreeNode(15);
  root->left = new TreeNode(10);
  root->right = new TreeNode(30);
  root->left->left = new TreeNode(5);

  cout << "Largest BST in given tree: " << largestBST(root).ans << endl;

  return 0;
}
