// 113. Path Sum II

/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1

Return:

[
   [5,4,11,2],
   [5,8,4,5]
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

class Solution {
public:
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> ans;
    vector<int> a;
    if (!root) return ans;
    dfs(root, a, ans, sum);
    return ans;
  }
private:
  void dfs(TreeNode *node, vector<int>& a, vector<vector<int>>& ans, int sum) {
    if (!node) return ;
    
    // leaf node
    if (node->left == nullptr && node->right == nullptr) {
      if (node->val == sum) {
        ans.push_back(a);
        ans.back().push_back(node->val);
      }
      return ;
    }
    
    int newsum = sum - node->val;
    a.push_back(node->val);
    dfs(node->left, a, ans, newsum);
    dfs(node->right, a, ans, newsum);
    a.pop_back();
  }
};