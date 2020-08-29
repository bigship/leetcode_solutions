// 513. Find Bottom Left Tree Value
/*
 * Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:

Input:

    2
   / \
  1   3

Output:
1

Example 2:

Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7

Note: You may assume the tree (i.e., the given root node) is not NULL.
*/

class Solution {
public:
  // Level-order traversal
  // Time: O(n), Space: O(n)
  int findBottomLeftValue(TreeNode *root) {
    vector<vector<int>> levels;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      vector<int> level;
      for (int i = 0; i < n; i++) {
        TreeNode *cur = q.front();
        if (cur)
          level.push_back(cur->val);
        q.pop();
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
      }
      levels.push_back(level);
      vector<int>().swap(level);
    }
    return levels.back().front();
  }

  // Recursion.
  // Time: O(n), Space: O(n)
  int findBottomLeftValue_recursion(TreeNode *root) {
    if (!root) return 0;
    int ans = -1;
    int height = getTreeHeight(root);
    findBottomLeftValue_recursion(root, 1, height, ans);
    return ans;
  }

private:
  int getTreeHeight(TreeNode *root) {
    if (!root) return 0;
    return std::max(getTreeHeight(root->left) + 1, getTreeHeight(root->right) + 1);
  }

  void findBottomLeftValue_recursion(TreeNode *root, int cur, int height, int& ans) {
    if (!root) return;
    if (cur == height) {
      if (ans != -1) {
        ans = root->val;
        return ;
      } else {
        return ;
      }
    }
    findBottomLeftValue_recursion(root->left, cur+1, height, ans);
    findBottomLeftValue_recursion(root->right, cur+1, height, ans);
  }
};
