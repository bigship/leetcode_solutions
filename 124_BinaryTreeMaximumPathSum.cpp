// 124. Binary Tree Maximum Path Sum
/*
 * Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any
node in the tree along the parent-child connections.
The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6

Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42

*/

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if (!root) return 0;
        int ans = INT_MIN;
        maxPathSum(root, ans);
        return ans;
    }
private:
    int maxPathSum(TreeNode *root, int& ans) {
        if (!root) return 0;
        int left = std::max(0, maxPathSum(root->left, ans));
        int right = std::max(0, maxPathSum(root->right, ans));
        int sum = left + right + root->val;
        ans = std::max(ans, sum);
        return std::max(left, right) + root->val;  // 只能返回其中一边, 不然就不是一条路径了
    }
};



