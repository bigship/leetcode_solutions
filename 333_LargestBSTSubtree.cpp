// 333. Largest BST Subtree
/*
 * Given a binary tree, find the largest subtree which is a Binary Search Tree (BST),
 * where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.

Example:

Input: [10,5,15,1,8,null,7]

   10
   / \
  5  15
 / \   \
1   8   7

Output: 3
Explanation: The Largest BST Subtree in this case is the highlighted one.
             The return value is the subtree's size, which is 3.

Follow up:
Can you figure out ways to solve it with O(n) time complexity?
*/

class Solution {
public:
  // Divide and Conquer.
  // 中序遍历一次二叉树将所有的节点值加入vector
  // 如果vector是严格升序的, 则表示二叉树本身是一颗BST, 返回vector的长度即可
  // 如果不是严格升序的, 以当前根节点作为分割点将vector分为左右两部分
  // 递归求解左半部分和右半部分
  // 返回max(left, right)
  int largestBSTSubtree(TreeNode *root) {
    std::stack<TreeNode *> sk;
    vector<int> vals;
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
    return findMaxBSTSize(vals, root);
  }

  // O(n)的方案
  int largestBSTSubtree_Linear(TreeNode *root) {
    if (!root) return 0;
    traversal(root);
    return max;
  }
private:
  int max = 0;

  int findMaxBSTSize(vector<int> vals, TreeNode *root) {
    int idx = 0;
    bool sorted = true;
    for (int i = 0; i + 1 < vals.size(); i++) {
      if (vals[i + 1] - vals[i] <= 0) {
        sorted = false;
        break;
      }
    }
    if (sorted)
      return vals.size();

    for (int i = 0; i < vals.size(); i++) {
      if (vals[i] == root->val) {
        idx = i;
        break;
      }
    }

    int leftsize = idx;
    int rightsize = vals.size() - 1 - idx;
    int ans1 = INT_MIN, ans2 = INT_MIN;
    if (leftsize > 0 && root->left) {
      auto left = vector<int>(vals.begin(), vals.begin() + idx);
      ans1 = findMaxBSTSize(left, root->left);
    }
    if (rightsize > 0 && root->right) {
      auto right = vector<int>(vals.begin() + idx + 1, vals.end());
      ans2 = findMaxBSTSize(right, root->right);
    }
    return std::max(ans1, ans2);
  }

  vector<int> traversal(TreeNode *root) {
    if (!root) return {0, INT_MAX, INT_MIN};
    auto left = traversal(root->left);
    auto right = traversal(root->right);
    if (left[0] == -1 || right[0] == -1 || root->val <= left[2] || root->val >= right[1]) {
      return {-1, 0, 0};
    }
    int s = left[0] + 1 + right[0];
    max = std::max(s, max);
    return {s, std::min(left[1], root->val), std::max(right[2], root->val)};
  }
};

