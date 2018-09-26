// 107. Binary Tree Level Order Traversal II

/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Actually it is the reversed version of level order traversal of binary tree.
// We can make use of deque to avoid reverse operation.

class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    deque<vector<int>> ans;
    dfs(root, 0, ans);
    return vector<vector<int>>{ans.begin(), ans.end()};
  }
private:
  void dfs(TreeNode *root, int level, deque<vector<int>>& ans) {
    if (!root) return;
    while (ans.size() <= level) 
      ans.push_front({});
    ans[ans.size()-level-1].push_back(root->val);
    dfs(root->left, level+1, ans);
    dfs(root->right, level+1, ans);
  }
};