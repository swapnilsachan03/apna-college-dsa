#include <iostream>
#include <stack>
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

void zigZagTraversal (TreeNode* root) {
  stack<TreeNode*> currLevel;
  stack<TreeNode*> nextLevel;

  bool leftToRight = true;

  currLevel.push(root);

  while (!currLevel.empty()) {
    if (root == nullptr) return;

    TreeNode* temp = currLevel.top();
    currLevel.pop();

    if (temp) {
      cout << temp->data << " ";

      if (leftToRight) {
        if (temp->left) nextLevel.push(temp->left);
        if (temp->right) nextLevel.push(temp->right);
      }

      else {
        if (temp->right) nextLevel.push(temp->right);
        if (temp->left) nextLevel.push(temp->left);
      }
    }

    if (currLevel.empty()) {
      leftToRight = !leftToRight;
      swap(currLevel, nextLevel);
    }
  }
}

int main()
{
  TreeNode* root = new TreeNode(12);
  root->left = new TreeNode(9);
  root->right = new TreeNode(15);
  root->left->left = new TreeNode(5);
  root->left->right = new TreeNode(10);

  zigZagTraversal(root);
  cout << endl;

  return 0;
}
