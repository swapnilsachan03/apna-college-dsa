#include <iostream>
#include <queue>
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

void rightView (TreeNode* root) {
  if (root == nullptr) return;

  queue<TreeNode*> q;
  q.push(root);

  while(!q.empty()) {
    int n = q.size();

    for(int i = 0; i < n; i++) {
      TreeNode* curr = q.front();
      q.pop();

      if (i == n-1) cout << curr->data << " ";
      if (curr->left) q.push(curr->left);
      if (curr->right) q.push(curr->right);
    }
  }
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

  rightView(n);
  cout << endl;

  return 0;
}
