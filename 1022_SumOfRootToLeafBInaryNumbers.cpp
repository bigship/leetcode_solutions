// 1022. Sum of Root to leaf binary numbers
/*
 * Given a binary tree, each node has value 0 or 1.
 * Each root-to-leaf path represents a binary number starting with the most significant bit.
 * For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
   For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.
   Return the sum of these numbers.

Example 1:

Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

Note:

    The number of nodes in the tree is between 1 and 1000.
    node.val is 0 or 1.
    The answer will not exceed 2^31 - 1.
*/
class Solution {
public:
  // Solution: Get each path and calculate binary sum
  int sumRootToLeaf(TreeNode *root) {
    vector<int> cur;
    int ans = 0;
    helper(root, cur, ans);
    return ans;
  }
private:
  void helper(TreeNode *root, vector<int>& cur, int& ans) {
    if (!root) return;
    if (!root->left && !root->right) {
      cur.push_back(root->val);
      int len = cur.size();
      for (int i = 0; i < cur.size(); i++) {
        ans += cur[i] * pow(2, len-1);
        len--;
      }
      return ;
    }
    cur.push_bck(root->val);
    if (root->left) {
      helper(root->left, cur, ans);
      cur.pop_back();
    }
    if (root->right) {
      helper(root->right, cur, ans);
      cur.pop_back();
    }
  }
};


