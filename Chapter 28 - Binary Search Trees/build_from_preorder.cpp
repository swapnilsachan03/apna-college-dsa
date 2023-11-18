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

void printPreorder (TreeNode* root) {
  if (root == nullptr) return;

  cout << root->data << " ";
  printPreorder(root->left);
  printPreorder(root->right);
}

// Time complexity = O(n)

TreeNode* constructBST (int preorder[], int* preorderIdx, int n, int key, int min, int max) {
  if (*preorderIdx >= n) return nullptr;

  TreeNode* root = nullptr;

  if (key > min && key < max) {
    root = new TreeNode(key);
    *preorderIdx = *preorderIdx + 1;

    if (*preorderIdx < n) {
      root->left = constructBST(preorder, preorderIdx, n, preorder[*preorderIdx], min, key);
    }

    if (*preorderIdx < n) {
      root->right = constructBST(preorder, preorderIdx, n, preorder[*preorderIdx], key, max);
    }
  }

  return root;
}

int main()
{
  int preorder[] = {7, 5, 4, 6, 8, 9};
  int preorderIdx = 0;

  TreeNode* root = constructBST(preorder, &preorderIdx, sizeof(preorder) / sizeof(int), preorder[0], INT32_MIN, INT32_MAX);

  printPreorder(root);
  cout << endl;

  printInorder(root);
  cout << endl;

  return 0;
}
