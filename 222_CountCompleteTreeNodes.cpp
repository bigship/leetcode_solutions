// 222. Count Complete Tree Nodes
/*
 * Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled,
and all nodes in the last level are as far left as possible.
It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input:
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6
*/

class Solution {
public:
  // 利用满二叉树的性质, 左子树中一定不会出现空缺, 空缺只可能在右子树上
  int countNodes(TreeNode *root) {
    if (!root) return 0;
    int leftH = 0, rightH = 0;
    for (TreeNode *p = root; p; p = p->left)
      leftH++;
    for (TreeNode *q = root; q; q = q->right)
      rightH++;
    if (leftH == rightH) return (1 << leftH) - 1;
    else {
      return countNodes(root->left) + countNodes(root->right) + 1;
    }
  }
};


