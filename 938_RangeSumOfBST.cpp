// 938. Range Sum of BST
/*
 * Given the root node of a binary search tree, return the sum of values of all
 * nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.

Example 1:

Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
Output: 32

Example 2:

Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
Output: 23

Note:

    The number of nodes in the tree is at most 10000.
    The final answer is guaranteed to be less than 2^31.
*/

class Solution {
public:
    int rangeSumBST_Recursion(TreeNode *root, int L, int R) {
        int ans = 0;
        helper(root, L, R, ans);
        return ans;
    }

    int rangeSumBST_Iterative(TreeNode *root, int L, int R) {
        stack<TreeNode *> s;
        s.push(root);
        int ans = 0;
        while (!s.empty()) {
            TreeNode *curnode = s.top();
            s.pop();
            if (curnode->val >= L && curnode->val <= R) {
                ans += curnode->val;
            }
            if (curnode->left) s.push(curnode->left);
            if (curnode->right) s.push(curnode->right);
        }
        return ans;
    }
private:
    void helper(TreeNode *root, int L, int R, int& ans) {
        if (root) {
            if (root->val >= L && root->val <= R) {
                ans += root->val;
            }
            if (root->val > L) {
                helper(root->left, L, R, ans);
            }
            if (root->val < R) {
                helper(root->right, L, R, ans);
            }
        }
    }
};


