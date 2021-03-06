// 1026. Maximum Difference Between Node and Ancestor
/*
 * Given the root of a binary tree, find the maximum value V for which there exist different nodes A and B
 * where V = |A.val - B.val| and A is an ancestor of B.

A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.

Example 1:

Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.

Example 2:

Input: root = [1,null,2,null,0,3]
Output: 3

Constraints:
    The number of nodes in the tree is in the range [2, 5000].
    0 <= Node.val <= 105
*/

// Solution: Brute Force. We compare every two node
// O(n^2)
class Solution {
public:
  int maxAncestorDiff(TreeNode* root) {
    int ans = 0;
    if (!root) return 0;

    maxDiff(root, root, ans);
    ans = max(ans, maxAncestorDiff(root->left));
    ans = max(ans, maxAncestorDiff(root->right));
    return ans;
  }
private:
  void maxDiff(TreeNode *root, TreeNode *child, int& ans) {
    if (child == nullptr) return ;
    ans = max(ans, abs(root->val - child->val));

    TreeNode *l = child->left;
    TreeNode *r = child->right;
    maxDiff(root, l, ans);
    maxDiff(root, r, ans);
  }
};

// Solution2. 求出每条root到leaf的路径上节点最大值和最小值
// 当到达叶子节点时, 计算最大值和最小值的差即可. 遍历所有路径找出最大的差值
// O(n). 每个节点只访问一次
class Solution2 {
public:
  int maxAncestorDiff(TreeNode* root) {
    if (!root) return 0;
    int maxv = INT_MIN;
    int minv = INT_MAX;
    int ans = INT_MIN;
    dfs(root, maxv, minv, ans);
    return ans;
  }
private:
  void dfs(TreeNode *root, int maxv, int minv, int& ans) {
    if (!root) {
      ans = max(ans, maxv - minv);
      return ;
    }
    maxv = max(root->val, maxv);
    minv = min(root->val, minv);
    dfs(root->left, maxv, minv, ans);
    dfs(root->right, maxv, minv, ans);
  }
};


