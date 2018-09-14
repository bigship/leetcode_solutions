// 94. Binary Tree Inorder Traversal

/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]

Follow up: Recursive solution is trivial, could you do it iteratively?
*/

class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ret;
    helper(root, &ret);
    return ret;
  }

  vector<int> inorderTraversal_iter(TreeNode *root) {
    vector<int> ret;
    stack<int> st;
    TreeNode *cur = root;
    while (cur || !st.empty()) {
      while (cur) {
        st.push(cur);
        cur = cur->left;
      }
      cur = st.top();
      st.pop();
      ret.push_back(cur->val);
      cur = cur->right;
    }
    return ret;
  }

private:
  void helper(TreeNode *root, vector<int> *ret) {
    if (!root) return;
    helper(root->left, ret);
    ret->push_back(root->val);
    helper(root->right, ret);
  }
};

