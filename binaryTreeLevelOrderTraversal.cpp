// 102. Binary Tree Level Order Traversal

/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
*/

class Solution {
public:
  vector<vector<int>> levelOrder_BFS(TreeNode *root) {
    return bfs(root);
  }

  vector<vector<int>> levelOrder_DFS(TreeNode *root) {
    vector<vector<int>> ans;
    dfs(root, 0, ans);
    return ans;
  }
private:
  vector<vector<int>> bfs(TreeNode *root) {
    if (!root) return {};
    vector<vector<int>> ans;
    vector<TreeNode *> curr, next;
    curr.push_back(root);
    while (!curr.empty()) {
      ans.push_back({});
      for (TreeNode *node : curr) {
        ans.back().push_back(node->val);
        if (node->left) next.push_back(node->left);
        if (node->right) next.push_back(node->right);
      }
      curr.swap(next);
      next.clear();
    }
    return ans;
  }

  void dfs(TreeNode *root, int level, vector<vector<int>>& ans) {
    if (!root) return;
    while (ans.size() <= level) 
      ans.push_back({});
    ans[level].push_back(root->val);
    dfs(root->left, level+1, ans);
    dfs(root->right, level+1, ans);
  }
}
