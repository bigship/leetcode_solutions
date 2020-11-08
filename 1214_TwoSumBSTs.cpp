// 1214. Two Sum BSTs
/*
 * Given two binary search trees, return True if and only if there is a node
 * in the first tree and a node in the second tree whose values sum up to a given integer target.

Example 1:

Input: root1 = [2,1,4], root2 = [1,0,3], target = 5
Output: true
Explanation: 2 and 3 sum up to 5.

Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2], target = 18
Output: false

Constraints:

    Each tree has at most 5000 nodes.
    -10^9 <= target, node.val <= 10^9
*/

class Solution {
public:
  bool twoSumBSTs(TreeNode *root1, TreeNode *root2, int target) {
    unordered_set<int> sets;
    inOrder(root1, sets, target);
    return validate(root2, sets);
  }
private:
  void inOrder(TreeNode *root, unordered_set<int>& sets, int& target) {
    if (!root) return;
    inOrder(root->left, sets, target);
    sets.insert(target - root->val);
    inOrder(root->right, sets, target);
  }

  bool validate(TreeNode *root, unordered_set<int>& sets) {
    if (!root) return false;
    if (sets.find(root->val) != sets.end()) return true;
    return validate(root->left, sets) || validate(root->right, sets);
  }
};


