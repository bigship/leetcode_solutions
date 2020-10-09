// 515. Find Largest Value in Each Tree Row
/*
 * Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]

Example 2:
Input: root = [1,2,3]
Output: [1,3]

Example 3:
Input: root = [1]
Output: [1]

Example 4:
Input: root = [1,null,2]
Output: [1,2]

Example 5:
Input: root = []
Output: []

Constraints:

    The number of nodes in the tree will be in the range [0, 104].
    -2^31 <= Node.val <= 2^31 - 1
*/
class Solution {
public:
  // Solution: level order traversal. 遍历每一层时记录最大的值
  vector<int> largestValues(TreeNode *root) {
    vector<int> ans;
    if (!root) return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      int v = INT_MIN;
      for (int i = 0; i < n; i++) {
        TreeNode *node = q.front();
        q.pop();
        if (node) {
          v = std::max(v, node->val);
          if (node->left) q.push(node->left);
          if (node->right) q.push(node->right);
        }
      }
      ans.push_back(v);
    }
    return ans;
  }
};


