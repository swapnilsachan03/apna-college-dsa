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

void printInorder (TreeNode* root) {
  if (root == nullptr) return;

  printInorder(root->left);
  cout << root->data << " ";
  printInorder(root->right);
}

TreeNode* insertBST (TreeNode* root, int val) {
  if (root == nullptr) {
    return new TreeNode(val);
  }

  if (val < root->data) root->left = insertBST(root->left, val);
  else root->right = insertBST(root->right, val);

  return root;
}

// As height of the tree is log(n+1), hence the time complexity will be O(log n). At each level, we discard one subtree, or, reduce the search space by half

bool searchInBST (TreeNode* root, int key) {
  if (root == nullptr) return false;
  if (root->data == key) return true;

  if (key < root->data) {
    cout << "Left -> ";
    return searchInBST(root->left, key);
  }
  
  else {
    cout << "Right -> ";
    return searchInBST(root->right, key);
  }
}

TreeNode* inorderSuccessor (TreeNode* root) {
  TreeNode* curr = root;

  while (curr && curr->left != nullptr) {
    curr = curr->left;
  }

  return curr;
}

// Visualization is the most important thing here!

TreeNode* deleteInBST (TreeNode* root, int key) {
  if (key < root->data) {
    root->left = deleteInBST(root->left, key);
  }
  
  else if (key > root->data) {
    root->right = deleteInBST(root->right, key);
  }

  else {
    if (root->left == nullptr) {
      TreeNode* temp = root->right;
      free(root);
      return temp;
    }

    else if (root->right == nullptr) {
      TreeNode* temp = root->left;
      free(root);
      return temp;
    }

    TreeNode* temp = inorderSuccessor(root->right);
    root->data = temp->data;
    root->right = deleteInBST(root->right, temp->data);
  }

  return root;
}

int main()
{
  int arr[] = {3,2,1,7,5,4,6,8};

  TreeNode* root = nullptr;
  for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    root = insertBST(root, arr[i]);
  }

  int key;
  cin >> key;

  bool found = searchInBST(root, key);

  if (found) cout << "Element found" << endl;
  else cout << "Element not found" << endl;

  printInorder(root);
  cout << endl;

  root = deleteInBST(root, key);
  printInorder(root);

  return 0;
}
