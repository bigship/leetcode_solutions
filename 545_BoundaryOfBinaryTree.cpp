// 545. Boundary of Binary Tree
/*
 * The boundary of a binary tree is the concatenation of the root, the left boundary,
 * the leaves ordered from left-to-right, and the reverse order of the right boundary.

The left boundary is the set of nodes defined by the following:
    The root node's left child is in the left boundary. If the root does not have a left child, then the left boundary is empty.
    If a node in the left boundary and has a left child, then the left child is in the left boundary.
    If a node is in the left boundary, has no left child, but has a right child, then the right child is in the left boundary.
    The leftmost leaf is not in the left boundary.

The right boundary is similar to the left boundary, except it is the right side of the root's right subtree.
Again, the leaf is not part of the right boundary, and the right boundary is empty if the root does not have a right child.

The leaves are nodes that do not have any children. For this problem, the root is not a leaf.
Given the root of a binary tree, return the values of its boundary.
*/

// Solution:  整个问题划分为找出左边界, 找出叶子节点, 找出右边界
// 找左边界时, 先从left开始, 如果不为叶子节点就加入. 如果没有left节点但有right节点
// 就把right当做下一个节点继续遍历. 找右边界类似, 只是这里用栈保存. 因为在最后的顺序
// 里右边界是逆序的.
class Solution {
public:
  vector<int> boundaryOfBinaryTree(TreeNode* root) {
    vector<int> ans;
    std::stack<int> rightsk;
    if (!root) return ans;

    if (!isLeaf(root))
      ans.push_back(root->val);

    TreeNode *t = root->left;
    while (t) {
      if (!isLeaf(t)) {
        ans.push_back(t->val);
      }
      if (t->left) {
        t = t->left;
      } else {
        t = t->right;
      }
    }

    getLeaves(root, ans);

    t = root->right;
    while (t) {
      if (!isLeaf(t)) {
        rightsk.push(t->val);
      }
      if (t->right) {
        t = t->right;
      } else {
        t = t->left;
      }
    }

    while (!rightsk.empty()) {
      int val = rightsk.top();
      rightsk.pop();
      ans.push_back(val);
    }
    return ans;
  }
private:
  bool isLeaf(TreeNode *root) {
    return !root->left && !root->right;
  }

  void getLeaves(TreeNode *root, vector<int>& ans) {
    if (!root) return ;
    if (!root->left && !root->right) {
      ans.push_back(root->val);
      return ;
    }
    getLeaves(root->left, ans);
    getLeaves(root->right, ans);
  }
};
