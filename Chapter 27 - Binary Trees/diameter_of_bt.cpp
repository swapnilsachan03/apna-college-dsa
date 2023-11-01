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

int calcHeight (TreeNode* root) {
  if(root == nullptr) return 0;

  int lHeight = calcHeight(root->left);
  int rHeight = calcHeight(root->right);

  return max(lHeight, rHeight) + 1;
}

// Diameter can either pass through the root node or not. If it does, we'll include the root node and calculate the diameter by adding the left and right subtrees' heights, along with the root node, else we'll take the maximum of left or right subtrees' diameter.

int calcDiameter (TreeNode* root) {
  if(root == nullptr) return 0;

  int lHeight = calcHeight(root->left);
  int rHeight = calcHeight(root->right);
  int currDiameter = lHeight + rHeight + 1;

  int lDiameter = calcDiameter(root->left);
  int rDiameter = calcDiameter(root->right);

  return max(currDiameter, max(lDiameter, rDiameter));
}

int calcDiameterOpt (TreeNode* root, int* height) {
  if(root == nullptr) {
    *height = 0;
    return 0;
  }

  int lh = 0, rh = 0;
  int lDiameter = calcDiameterOpt(root->left, &lh);
  int rDiameter = calcDiameterOpt(root->right, &rh);

  int currDiameter = lh + rh + 1;
  *height = max(lh, rh) + 1;

  return max(currDiameter, max(lDiameter, rDiameter));
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

  int h = 0;

  cout << calcDiameter(n) << endl;
  cout << calcDiameterOpt(n, &h) << endl;
  
  return 0;
}
