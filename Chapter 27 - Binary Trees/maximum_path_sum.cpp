/* For each node, compute the following:
  
  -> Node value
  -> Max path through the left child + node value
  -> Max path through the right child + node value
  -> Max path through the right child + max path through the right child + node value

  The maximum of these will be the max path sum passing throught the current node.
*/

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

int maxPathSumUtil (TreeNode* root, int &ans) {
  if (root == nullptr) return 0;

  int left = maxPathSumUtil(root->left, ans);
  int right = maxPathSumUtil(root->right, ans);

  int nodeMax = max(
    max(root->data, root->data + left + right),
    max(root->data + left, root->data + right)
  );

  ans = max(ans, nodeMax);
  
  int singlePathSum = max(
    root->data,
    max(root->data + left, root->data + right)
  );

  return singlePathSum;
}

int maxPathSum (TreeNode* root) {
  int ans = INT32_MIN;

  maxPathSumUtil(root, ans);
  return ans;
}

int main()
{
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(-12);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(-6);

  cout << maxPathSum(root);

  return 0;
}
