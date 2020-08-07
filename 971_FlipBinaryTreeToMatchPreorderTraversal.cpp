// 971. Flip Binary Tree To Match Preorder Traversal
/*
 * Given a binary tree with N nodes, each node has a different value from {1, ..., N}.
A node in this binary tree can be flipped by swapping the left child and the right child of that node.
Consider the sequence of N values reported by a preorder traversal starting from the root.
Call such a sequence of N values the voyage of the tree.
(Recall that a preorder traversal of a node means we report the current node's value,
 then preorder-traverse the left child, then preorder-traverse the right child.)

Our goal is to flip the least number of nodes in the tree so that the voyage of the tree matches the voyage we are given.
If we can do so, then return a list of the values of all nodes flipped.  You may return the answer in any order.
If we cannot do so, then return the list [-1].

*/

class Solution {
public:
  vector<int> flipMatchVoyage(TreeNode *root, vector<int>& voyage) {
    stack<TreeNode *> s;
    vector<int> ans;
    s.push(root);
    int i = 0;
    while (!s.empty()) {
      TreeNode *cur = s.top();
      s.pop();
      if (!cur) continue;
      // root不同, 不可能通过交换左右子节点来完成. 直接返回-1
      if (cur->val != voyage[i++])
        return vector<int>{-1};
      // cur的右节点和voyage的下一个值相等了, 如果cur还有左节点
      // 就表示可以通过交换左右子节点的值来满足voyage的先根顺序
      if (cur->right && cur->right->val == voyage[i]) {
        if (cur->left)
          ans.push_back(cur->val);
        // 以相反的顺序入栈
        s.push(cur->left);
        s.push(cur->right);
      } else {
        // 和正常的先根遍历顺序一致
        s.push(cur->right);
        s.push(cur->left);
      }
    }
    return ans;
  }
};
