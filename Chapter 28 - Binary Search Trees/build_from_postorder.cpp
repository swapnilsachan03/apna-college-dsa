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

void printPostorder (TreeNode* root) {
  if (root == nullptr) return;

  printPostorder(root->left);
  printPostorder(root->right);
  cout << root->data << " ";
}

// Time complexity = O(n)

TreeNode* constructBST (int postorder[], int* postorderIdx, int key, int min, int max) {
  if (*postorderIdx < 0) return nullptr;

  TreeNode* root = nullptr;

  if (key > min && key < max) {
    root = new TreeNode(key);
    *postorderIdx = *postorderIdx - 1;

    if (*postorderIdx >= 0) {
      root->right = constructBST(postorder, postorderIdx, postorder[*postorderIdx], key, max);
    }

    if (*postorderIdx >= 0) {
      root->left = constructBST(postorder, postorderIdx, postorder[*postorderIdx], min, key);
    }
  }

  return root;
}

int main()
{
  int postorder[] = {1, 7, 5, 50, 40, 10};
  int postorderIdx = sizeof(postorder) / sizeof(int) - 1;

  TreeNode* root = constructBST(postorder, &postorderIdx, postorder[postorderIdx], INT32_MIN, INT32_MAX);

  printPostorder(root);
  cout << endl;

  printInorder(root);
  cout << endl;

  return 0;
}
