#include <iostream>
#include <vector>
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

bool getPath (TreeNode* root, int key, vector<int> &path) {
  if(root == nullptr) return false;
  
  path.push_back(root->data);

  if(root->data == key) return true;
  if(getPath(root->left, key, path) || getPath(root->right, key, path)) {
    return true;
  }

  path.pop_back();
  return false;
}

int LCA (TreeNode* root, int n1, int n2) {
  vector<int> p1, p2;

  if (!getPath(root, n1, p1) || !getPath(root, n2, p2)) {
    return -1;
  }

  int pc;   // where paths from root node change

  for(pc = 0; pc < p1.size() && p2.size(); pc++) {
    if (p1[pc] != p2[pc]) break;
  }

  return p1[pc-1];
}

TreeNode* LCAOptimal (TreeNode* root, int n1, int n2) {
  if (root == nullptr) return nullptr;

  if (root->data == n1 || root->data == n2) {
    return root;
  }

  TreeNode* leftLCA = LCAOptimal(root->left, n1, n2);
  TreeNode* rightLCA = LCAOptimal(root->right, n1, n2);

  if (leftLCA != nullptr && rightLCA != nullptr) {
    return root;
  }

  if (leftLCA != nullptr) return leftLCA;
  else return rightLCA;   // if this is also null, nullptr will be returned
}

int main()
{
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->right->left->left = new TreeNode(7);

  int n1 = 7, n2 = 3;
  int lca = LCA(root, n1, n2);
  TreeNode* lcaNode = LCAOptimal(root, n1, n2);

  if (lca == -1) cout << "LCA doesn't exist." << endl;
  else cout << "LCA: " << lca << endl;

  if (lcaNode == nullptr) cout << "LCA doesn't exist." << endl;
  else cout << "LCA: " << lca << endl;

  return 0;
}
