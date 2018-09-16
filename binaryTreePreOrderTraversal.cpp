// 144. Binary Tree Preorder Traversal

/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]

Follow up: Recursive solution is trivial, could you do it iteratively?
*/

// make use of stack. Because stack is LIFO, we should push right before push left

class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ans;
    if (!root) return ans;
    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty()) {
      TreeNode *node = st.top();
      st.pop();
      if (node) {
        ans.push_back(node->val);
        st.push(node->right);
        st.push(node->left);
      }
    }
    return ans;
  }
};


