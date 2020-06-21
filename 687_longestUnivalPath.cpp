// 687. Longest Univalue Path
/*
 Given a binary tree, find the length of the longest path where each node in
 the path has the same value. This path may or may not pass through the root.
 The length of path between two nodes is represented by the number of edges
 between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5

Output: 2


Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5

Output: 2

Note: The given binary tree has not more than 10000 nodes.
The height of the tree is not more than 1000.
*/


class Solution {
public:
    int ans = 0;
    int longestUnivalPath(TreeNode *root) {
        if (!root) return 0;
        helper(root, ans);
        return ans;
    }

    int helper(TreeNode *root, int& ans) {
        if (!root) return 0;
        int l = helper(root->left, ans);
        int r = helper(root->right, ans);
        int pl = 0, pr = 0;
        if (root->left && root->val == root->left->val) pl = l + 1;
        if (root->right && root->val == root->right->val) pr = r + 1;
        ans = max(ans, pl + pr);
        return max(pl, pr);
    }
};
