/* Algorithm:

-> Start from end of postorder & pick an element to create a node
-> Decrement postorder index
-> Search the picked element's position in inorder
-> Call to build right subtree from inorder's position + 1 to n
-> Call to build left subtree from inorder's 0 to position - 1
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

TreeNode* buildTree (int postorder[], int inorder[], int st, int end) {
  static int idx = end;

  if(st > end) return nullptr;

  int curr = postorder[idx];
  idx -= 1;

  TreeNode* node = new TreeNode(curr);

  if(st == end) {
    return node;
  }

  int pos = search(inorder, st, end, curr);
  node->right = buildTree(postorder, inorder, pos + 1, end);
  node->left = buildTree(postorder, inorder, st, pos - 1);

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
  int postorder[] = {4,2,5,3,1};
  int inorder[] = {4,2,1,5,3};

  TreeNode* root = buildTree(postorder, inorder, 0, 4);
  printInorder(root);

  cout << endl;

  return 0;
}
