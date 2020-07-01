// 98. Validate Binary Search Tree

/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

Example 1:

Input:
    2
   / \
  1   3
Output: true

Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.


*/

// 充分利用BST的性质. 左子树节点值小于根节点值, 右子树节点值大于跟节点
// 因此可以判断左右子树节点的值的范围, 超过范围就不是合法的BST

class Solution {
public:
  bool isValidBST(TreeNode *root) {
    return isValidBST(root, nullptr, nullptr);
  }
private:
  // root: 根节点, min: 指针, 指向左子节点的值, max: 指向右子节点的值
  bool isValidBST(TreeNode *root, int *min, int *max) {
    if (!root) return true;
    if ((min && root->val <= *min) || (max && root->val >= *max))
      return false;
    return isValidBST(root->left, min, &root->val) && isValidBST(root->right, &root->val, max);
  }

  // BST中序遍历, 每次比较prev和cur指向的值, prev >= cur则不是BST
  // 中序遍历的迭代算法必须牢记. 利用stack, 不断push左子节点, 再将cur设为right
  bool isValidBST_iter(TreeNode *root) {
      stack<TreeNode *> st;
      TreeNode *curnode = root;
      int *prev = nullptr, *cur = nullptr;
      while (curnode || !st.empty()) {
          while (curnode) {
              st.push(curnode);
              curnode = curnode->left;
          }
          curnode = st.top();
          st.pop();
          cur = &(curnode->val);
          if (prev) {
              if (*prev >= *cur) return false;
          }
          prev = &(curnode->val);
          cur = cur->right;
      }
      return true;
  }
};

