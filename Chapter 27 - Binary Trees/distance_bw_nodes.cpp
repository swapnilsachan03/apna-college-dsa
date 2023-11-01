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

TreeNode* LCA (TreeNode* root, int n1, int n2) {
  if (root == nullptr) return nullptr;

  if (root->data == n1 || root->data == n2) {
    return root;
  }

  TreeNode* left = LCA(root->left, n1, n2);
  TreeNode* right = LCA(root->right, n1, n2);

  if (left != nullptr && right != nullptr) {
    return root;
  }

  if (left == nullptr && right == nullptr) {
    return nullptr;
  }

  if(left != nullptr) return LCA(root->left, n1, n2);
  return LCA(root->right, n1, n2);
}

int findDist (TreeNode* root, int k, int dist) {
  if (root == nullptr) return -1;
  if (root->data == k) return dist;

  int left = findDist(root->left, k, dist + 1);
  if (left != -1) return left;

  return findDist(root->right, k, dist + 1);
}

int distBtwNodes (TreeNode* root, int n1, int n2) {
  TreeNode* lca = LCA(root, n1, n2);

  int d1 = findDist(lca, n1, 0);
  int d2 = findDist(lca, n2, 0);

  return d1 + d2;
}

int main()
{
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->right = new TreeNode(5);

  cout << distBtwNodes(root, 4, 5) << endl;

  return 0;
}
