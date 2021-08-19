// 1339. Maximum Product of Splitted Binary Tree
/*
 * Given the root of a binary tree, split the binary tree into two subtrees by removing one edge
 * such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees.
Since the answer may be too large, return it modulo 1e9 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.

Example 1:

Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)

*/

class Solution {
public:
  int maxProduct(TreeNode* root) {
    long ans = 0;
    long totalSum = sumOfTree(root);
    helper(root, totalSum, ans);
    return ans % mod;
  }
private:
  int mod = 1e9 + 7;

  long sumOfTree(TreeNode *root) {
    if (!root) return 0;
    long cur = root->val;
    return cur + sumOfTree(root->left) + sumOfTree(root->right);
  }

  // 考虑后续遍历. 从叶子节点开始逐层向上累加和, 从而得到子树的和
  long helper(TreeNode *root, int totalSum, long& ans) {
    if (!root) return 0;

    long left = helper(root->left, totalSum, ans);
    long right = helper(root->right, totalSum, ans);
    long curmax = std::max(left * (totalSum - left), right * (totalSum - right));
    if (curmax > ans) {
      ans = curmax;
    }

    return left + right + root->val;
  }
};

