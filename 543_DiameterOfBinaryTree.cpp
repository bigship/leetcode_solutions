// 543. Diameter of Binary Tree
/*
 *  Given a binary tree, you need to compute the length of the diameter of the tree.
 *  The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
 *  This path may or may not pass through the root.

Example:
Given a binary tree

          1
         / \
        2   3
       / \
      4   5

Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/
// 就是求二叉树中任意两节点之间的最长距离
class Solution {
public:
  int diameterOfBinaryTree(TreeNode *root) {
    if (!root) return 0;
    maxSide(root);
    return ans_;
  }
private:
  int ans_ = 0;

  // 求以该节点为根节点的最长边
  int maxSide(TreeNode *root) {
    if (!root) return -1;
    // 递归求解左右子树的最长边, 每次返回加1
    int left = maxSide(root->left) + 1;
    int right = maxSide(root->right) + 1;
    ans_ = std::max(ans_, left + right);    // 更新结果, 就是左右两边之和
    return std::max(left, right);           // 返回时只能返回最大的一边
  }
};
