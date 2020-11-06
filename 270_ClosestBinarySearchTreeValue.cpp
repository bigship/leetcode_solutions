// 270. Closest Binary Search Tree Value
/*
 * Given a non-empty binary search tree and a target value,
 * find the value in the BST that is closest to the target.

Note:
    Given target value is a floating point.
    You are guaranteed to have only one unique value in the BST that is closest to the target.

Example:

Input: root = [4,2,5,1,3], target = 3.714286

    4
   / \
  2   5
 / \
1   3

Output: 4
*/

class Solution {
public:
  // Binary search
  int closestValue(TreeNode *root, double target) {
    int val, closest = root->val;
    while (root) {
      val = root->val;
      closest = abs(val - target) < abs(closest - target) ? val : closest;
      root = target < val ? root->left : root->right;
    }
    return closest;
  }
};


