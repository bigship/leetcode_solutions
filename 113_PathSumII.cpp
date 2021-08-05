// 113. Path Sum II
/*
 * Given the root of a binary tree and an integer targetSum,
 * return all root-to-leaf paths where each path's sum equals targetSum.

A leaf is a node with no children.
*/

class Solution {
public:
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> ans;
    vector<int> path;
    int cursum = 0;
    helper(ans, root, path, cursum, targetSum);
    return ans;
  }
private:
  void helper(vector<vector<int>>& ans, TreeNode *root,
              vector<int>& path, int& cursum, int targetSum) {
    if (!root) return ;

    path.push_back(root->val);
    cursum += root->val;
    if (!root->left && !root->right) {
      if (cursum == targetSum) {
        ans.push_back(path);
      }
      return ;
    }

    helper(ans, root->left, path, cursum, targetSum);
    if (root->left) {
      cursum -= root->left->val;
      path.pop_back();
    }

    helper(ans, root->right, path, cursum, targetSum);
    if (root->right) {
      cursum -= root->right->val;
      path.pop_back();
    }
  }
};


