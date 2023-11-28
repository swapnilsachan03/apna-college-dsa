// 2 nodes of a BST are swapped. Our task is to restore / correct the BST.

#include <iostream>
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

void printInorder (TreeNode* root) {
  if (root == nullptr) return;

  printInorder(root->left);
  cout << root->data << " ";
  printInorder(root->right);
}

void swap (int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void calcPointers (TreeNode* root, TreeNode **first, TreeNode **mid, TreeNode **last, TreeNode **prev) {
  if (root == nullptr) return;

  calcPointers(root->left, first, mid, last, prev);
  
  if (*prev && root->data < (*prev)->data) {
    if (!*first) {
      *first = *prev;
      *mid = root;
    }

    else {
      *last = root;
    }
  }

  *prev = root;
  calcPointers(root->right, first, mid, last, prev);
}

void restoreBST (TreeNode* root) {
  if (root == nullptr) return;

  TreeNode *first, *mid, *last;
  TreeNode *prev;
  first = mid = last = prev = nullptr;

  calcPointers(root, &first, &mid, &last, &prev);

  if (first && last) {    // Case 1 -> out of order nodes are not adjacent
    swap(&(first->data), &(last->data));
  }

  else if (first && mid) {    // Case 2 -> out of order nodes are adjacent
    swap(&(first->data), &(mid->data));
  }
}

int main()
{
  /*
        6
       / \
      9   3
     / \   \
    1   4  13
  */

  TreeNode* root = new TreeNode(6);
  root->left = new TreeNode(9);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(13);

  printInorder(root);
  cout << endl;

  restoreBST(root);

  printInorder(root);
  cout << endl;

  return 0;
}
