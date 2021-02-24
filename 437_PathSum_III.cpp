// 437. Path Sum III
/*
 * You are given a binary tree in which each node contains an integer value.
Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
*/

class Solution {
public:
  int pathSum(TreeNode* root, int sum) {
    if (!root) return 0;
    int ans = 0;
    helper(root, sum, 0, ans);  // 得到包含根节点的路径之和为sum的个数
    ans += pathSum(root->left, sum);  // 递归求解左子树
    ans += pathSum(root->right, sum); // 递归求解右子树
    return ans;
  }
private:
  // 求出包含root节点的路径, 且使得路径之和为sum的个数
  void helper(TreeNode *root, int sum, int cur, int& res) {
    if (!root) return ;
    cur += root->val;
    if (cur == sum) {
      res += 1;
    }
    helper(root->left, sum, cur, res);
    helper(root->right, sum, cur, res);
  }
};
