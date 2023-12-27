#include <iostream>
#include <map>
#include <vector>
using namespace std;

class TreeNode {
  public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode (int val) {
      data = val;
      left = right = nullptr;
    }
};

void verticalOrderTraverse (map<int, vector<int>> &mp, TreeNode* root, int d) {
  if (root == nullptr) return;

  mp[d].push_back(root->data);
  verticalOrderTraverse(mp, root->left, d - 1);
  verticalOrderTraverse(mp, root->right, d + 1);
}

int main()
{
  TreeNode* root = new TreeNode(10);
  root->left = new TreeNode(7);
  root->right = new TreeNode(4);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(11);
  root->right->left = new TreeNode(14);
  root->right->right = new TreeNode(6);

  map<int, vector<int>> mp;
  verticalOrderTraverse(mp, root, 0);

  for (auto v : mp) {
    for (int i = 0; i < v.second.size(); i++) {
      cout << v.second[i] << " ";
    }

    cout << endl;
  }

  return 0;
}
