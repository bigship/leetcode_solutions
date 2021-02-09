// 1430. Check If a String is a valid sequence from root to leaves path in a Binary Tree
/*
 * Given a binary tree where each path going from the root to any leaf form a valid sequence,
 * check if a given string is a valid sequence in such binary tree.

We get the given string from the concatenation of an array of integers arr and the concatenation
of all values of the nodes along a path results in a sequence in the given binary tree.
*/

class Solution {
public:
  bool isValidSequence(TreeNode *root, vector<int>& arr) {
    bool ans = false;
    vector<int> path;
    helper(root, path, arr, ans);
    return ans;
  }
private:
  void helper(TreeNode *root, vector<int>& path, vector<int>& arr, bool& ans) {
    if (!root) return;
    if (!root->left && !root->right) {
      path.push_back(root->val);
      if (isMatch(path, arr))
        ans = true;
      return ;
    }
    path.push_back(root->val);
    if (root->left) {
      helper(root->left, path, arr, ans);
      path.pop_back();
    }
    if (root->right) {
      helper(root->right, path, arr, ans);
      path.pop_back();
    }
  }
};
