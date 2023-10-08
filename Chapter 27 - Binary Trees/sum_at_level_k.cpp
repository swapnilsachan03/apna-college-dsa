#include <iostream>
#include <queue>
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

int sumAtK (TreeNode* root, int k) {
  if(root == nullptr) return INT32_MIN;

  queue<TreeNode*> q;
  q.push(root);
  q.push(nullptr);

  int level = 0, sum = 0;
  while(!q.empty()) {
    TreeNode* node = q.front();
    q.pop();

    if(node != nullptr) {
      if(level == k) sum += node->data;
      if(node->left) q.push(node->left);
      if(node->right) q.push(node->right);
    }

    else if (!q.empty()) {
      q.push(nullptr);
      level++;
    }
  }

  return sum;
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

  cout << sumAtK(n, 2) << endl;

  return 0;
}
