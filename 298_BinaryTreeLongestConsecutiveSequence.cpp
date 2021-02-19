// 298. Binary Tree Longest Consecutive Sequence
/*
 * Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections.
The longest consecutive path need to be from parent to child (cannot be the reverse).

Example 1:

Input:

   1
    \
     3
    / \
   2   4
        \
         5

Output: 3

Explanation: Longest consecutive sequence path is 3-4-5, so return 3.

Example 2:

Input:

   2
    \
     3
    /
   2
  /
 1

Output: 2

Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.
*/
// 从root开始往左右遍历
// 初始的长度cur设为1. 如果左节点值减去当前root的值等于1, 说明有连续节点出现. 更新当前长度为cur + 1
// 同时更新最大值. 继续向下层递归求解. 如果孩子节点减去root的值不为1, 说明不连续, 此时只要把cur重置为1
// 再向下层递归即可. 右子树同样道理, 最终解就是左右分别求解完后的最大值.
class Solution {
public:
  int longestConsecutive(TreeNode *root) {
    if (!root) return 0;
    int ans = 1;
    helper(root, 1, ans);
    return ans;
  }
private:
  void helper(TreeNode *root, int cur, int& ans) {
    if (!root) return;
    if (root->left) {
      if (root->left->val - root->val == 1) {
        ans = max(ans, cur + 1);
        helper(root->left, cur + 1, ans);
      } else {
        helper(root->left, 1, ans);
      }
    }
    if (root->right) {
      if (root->right->val - root->val == 1) {
        ans = max(ans, cur + 1);
        helper(root->right, cur + 1, ans);
      } else {
        helper(root->right, 1, ans);
      }
    }
  }
};
