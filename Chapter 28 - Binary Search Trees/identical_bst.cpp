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

bool isIdentical (TreeNode* a, TreeNode* b) {
  if (a == nullptr && b == nullptr) return true;
  if (a == nullptr || b == nullptr) return false;
  if (a->data != b->data) return false;

  bool left = isIdentical(a->left, b->left);
  bool right = isIdentical(a->right, b->right);

  return left && right;
}

int main()
{
  TreeNode* a = new TreeNode(2);
  a->left = new TreeNode(1);
  a->right = new TreeNode(3);

  TreeNode* b = new TreeNode(2);
  b->right = new TreeNode(3);

  if (isIdentical(a, b)) cout << "Trees are identical" << endl;
  else cout << "Trees are not identical" << endl;

  return 0;
}
