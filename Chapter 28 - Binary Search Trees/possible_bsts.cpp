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

void printPreorder (TreeNode* root) {
  if (root == nullptr) return;

  cout << root->data << " ";
  printPreorder(root->left);
  printPreorder(root->right);
}

vector<TreeNode*> constructTrees (int start, int end) {
  vector<TreeNode*> trees;

  if (start > end) {
    trees.push_back(nullptr);
    return trees;
  }

  for (int i = start; i <= end; i++) {
    vector<TreeNode*> leftSubtrees = constructTrees(start, i-1);
    vector<TreeNode*> rightSubtrees = constructTrees(i+1, end);

    for (int j = 0; j < leftSubtrees.size(); j++) {
      TreeNode* left = leftSubtrees[j];

      for (int k = 0; k < rightSubtrees.size(); k++) {
        TreeNode* right = rightSubtrees[k];
        TreeNode* node = new TreeNode(i);
        node->left = left;
        node->right = right;

        trees.push_back(node);
      }
    }
  }

  return trees;
}

int main()
{
  vector<TreeNode*> trees = constructTrees(1, 4);

  for (int i = 0; i < trees.size(); i++) {
    cout << "Tree " << i+1 << ": ";
    printPreorder(trees[i]);
    cout << endl;
  }

  return 0;
}
