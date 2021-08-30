// 663. Equal Tree Partition
//
/* Given the root of a binary tree, return true if you can partition the tree
 * into two trees with equal sums of values after removing exactly one edge on the original tree.
 */

class Solution {
public:
  bool checkEqualTree(TreeNode *root) {
    if (!root) return false;
    int totalSum = treeSum(root);
    if (totalSum % 2 != 0) return false;

    bool ans = false;
    checkEqualTree(root, root, totalSum, ans);
    return ans;
  }
private:
  int treeSum(TreeNode *root) {
    if (!root) return 0;
    return root->val + treeSum(root->left) + treeSum(root->right);
  }

  int checkEqualTree(TreeNode *root, TreeNode *tree_root, int totalSum, bool& ans) {
    if (!root) return 0;

    int left = checkEqualTree(root->left, tree_root, totalSum, ans);
    int right = checkEqualTree(root->right, tree_root, totalSum, ans);
    if (left == totalSum / 2 && root->left) ans = true;
    if (right == totalSum / 2 && root->right) ans = true;
    if (root->val + left + right == totalSum / 2 && root != tree_root) ans = true;
    return root->val + left + right;
  }
};
