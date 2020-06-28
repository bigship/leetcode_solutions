// 404. Sum of Left Leaves
/*
 * Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively.
Return 24.
*/

class Solution {
public:
    int sumOfLeftLeaves(TreeNode *root) {
        int ans = 0;
        helper(root, -1, ans);
        return ans;
    }
private:
    void helper(TreeNode *root, int left, int& vals) {
        if (!root) return;
        if (left == 1 && !root->left && !root->right) {
            vals += root->val;
        }
        if (root->left) helper(root->left, 1, vals);
        if (root->right) helper(root->right, 2, vals);
    }
};

