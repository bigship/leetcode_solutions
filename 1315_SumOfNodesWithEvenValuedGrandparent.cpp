// 1315. Sum of Nodes with Even-Valued Grandparent
/*
 * Given a binary tree, return the sum of values of nodes with even-valued grandparent.
 * (A grandparent of a node is the parent of its parent, if it exists.)

If there are no nodes with an even-valued grandparent, return 0.

Example 1:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 18
Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.

Constraints:

    The number of nodes in the tree is between 1 and 10^4.
    The value of nodes is between 1 and 100.
*/

class Solution {
public:
  int sumEvenGrandparent(TreeNode *root) {
    int ans = 0;
    getSum(root, ans);
    return ans;
  }
private:
  void getSum(TreeNode *root, int& ans) {
    if (!root) return ;
    if (root->val % 2 == 0) {
      if (root->left && root->left->left)
        ans += root->left->left->val;
      if (root->left && root->left->right)
        ans += root->left->right->val;
      if (root->right && root->right->left)
        ans += root->right->left->val;
      if (root->right && root->right->right)
        ans += root->right->right->val;
    }
    getSum(root->left, ans);
    getSum(root->right, ans);
  }
};
