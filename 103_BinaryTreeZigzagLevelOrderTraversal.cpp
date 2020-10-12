// 103. Binary Tree Zigzag Level Order Traversal
/*
 * Given a binary tree, return the zigzag level order traversal of its nodes' values.
 * (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]
*/

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (!root) return ans;
    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int n = q.size();
      vector<int> level;
      for (int i = 0; i < n; i++) {
        TreeNode *cur = q.front();
        q.pop();
        level.push_back(cur->val);
        if (cur->left)
          q.push(cur->left);
        if (cur->right)
          q.push(cur->right);
      }
      ans.push_back(level);
    }

    for (int i = 0; i < ans.size(); i++) {
      if (i & 1 == 1) {
        std::reverse(ans[i].begin(), ans[i].end());
      }
    }
    return ans;
  }
};

