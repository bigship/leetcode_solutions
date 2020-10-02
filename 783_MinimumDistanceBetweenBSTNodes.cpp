// 783. Minimum Distance Between BST Nodes
/*
 * Given a Binary Search Tree (BST) with the root node root, return the minimum
 * difference between the values of any two different nodes in the tree.

Example :

Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

          4
        /   \
      2      6
     / \
    1   3

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.

Note:

    The size of the BST will be between 2 and 100.
    The BST is always valid, each node's value is an integer, and each node's value is different.
    This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
*/

class Solution {
public:
  // BST, 中序遍历后结果为有序数组
  // 再遍历一次数组, 每次迭代计算两个相邻节点之间的差, 更新结果即可
  int minDiffInBST(TreeNode *root) {
    if (!root) return 0;
    int ans = INT_MAX;
    vector<int> vals;
    stack<TreeNode *> sk;
    TreeNode *cur = root;
    while (cur || !sk.empty()) {
      while (cur) {
        sk.push(cur);
        cur = cur->left;
      }
      TreeNode *node = sk.top();
      sk.pop();
      if (node) {
        vals.push_back(node->val);
      }
      cur = node->right;
    }
    if (vals.size() == 1)
      return vals[0];
    for (int i = 1; i < vals.size(); i++) {
      ans = std::min(ans, vals[i] - vals[i-1]);
    }
    return ans;
  }

  // 不用保存每个节点值, 只需要一个prev指针指向前一个节点即可
  // 在遍历中更新cur->val - prev->val的值即可
  int minDiffInBST(TreeNode *root) {
    if (!root) return 0;
    int ans = INT_MAX;
    stack<TreeNode *> sk;
    TreeNode *cur = root;
    TreeNode *prev = nullptr;
    while (cur || !sk.empty()) {
      while (cur) {
        sk.push(cur);
        cur = cur->left;
      }
      TreeNode *node = sk.top();
      sk.pop();
      if (prev) {
        ans = std::min(ans, node->val - prev->val);
      }
      prev = node;
      cur = node->right;
    }
    return ans;
  }
};


