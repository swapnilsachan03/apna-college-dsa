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

void levelOrder (TreeNode* root) {
  if(root == nullptr) return;

  queue<TreeNode*> q;
  q.push(root);
  q.push(nullptr);

  while(!q.empty()) {
    TreeNode* node = q.front();
    q.pop();

    if(node != nullptr) {
      cout << node->data << " ";
      if(node->left) q.push(node->left);
      if(node->right) q.push(node->right);
    }

    else if (!q.empty()) {
      q.push(nullptr);
    }
  }

  cout << endl;
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

  levelOrder(n);

  return 0;
}
