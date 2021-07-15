// 337. House Robber III
/*
 * The thief has found himself a new place for his thievery again.
 * There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house.
After a tour, the smart thief realized that all houses in this place form a binary tree.
It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree,
return the maximum amount of money the thief can rob without alerting the police.
*/

// 转化为树的后续遍历问题
class Solution {
public:
    int rob(TreeNode* root) {
      if (!root) return 0;
      auto res = helper(root);
      return std::max(res[0], res[1]);
    }
private:
    vector<int> helper(TreeNode *root) {
    if (!root) {
      return {0, 0};
    }

    auto left = helper(root->left);
    auto right = helper(root->right);
    vector<int> cur(2, 0);
    cur[0] = std::max(left[0], left[1]) + std::max(right[0], right[1]);  // 不抢当前层, 收益只来自于左右
    cur[1] = left[0] + right[0] + root->val;  // 抢当前层, 所以左右都不能抢
    return cur;
  }
};
