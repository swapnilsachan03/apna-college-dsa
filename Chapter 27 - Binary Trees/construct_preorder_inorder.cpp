/* Algorithm:

-> Pick element from preorder & create a node
-> Increment preorder index
-> Search the picked element's position in inorder
-> Call to build left subtree from inorder's 0 to position - 1
-> Call to build right subtree from inorder's position + 1 to n
-> Return the node  */

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

int search(int inorder[], int st, int end, int curr) {
  for(int i = st; i <= end; i++) {
    if(inorder[i] == curr) {
      return i;
    }
  }

  return -1;
}

TreeNode* buildTree (int preorder[], int inorder[], int st, int end) {
  static int idx = 0;

  if(st > end) return nullptr;

  int curr = preorder[idx];
  idx += 1;

  TreeNode* node = new TreeNode(curr);

  if(st == end) {
    return node;
  }

  int pos = search(inorder, st, end, curr);
  node->left = buildTree(preorder, inorder, st, pos - 1);
  node->right = buildTree(preorder, inorder, pos + 1, end);

  return node;
}

void printInorder (TreeNode* root) {
  if(root == nullptr) return;

  printInorder(root->left);
  cout << root->data << " ";
  printInorder(root->right);
}

int main()
{
  int preorder[] = {1,2,4,3,5};
  int inorder[] = {4,2,1,5,3};

  TreeNode* root = buildTree(preorder, inorder, 0, 4);
  printInorder(root);

  cout << endl;

  return 0;
}
