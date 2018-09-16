// 145. Binary tree Postorder Traversal

/*
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]

Follow up: Recursive solution is trivial, could you do it iteratively?
*/

// Trick: 
// Postorder traversal, the sequence would be left -> right -> root
// Preorder traversal, the sequence would be root -> left -> right

// so, if we use preorder traversal, the result is happend to be the REVERSED postorder traversal

class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    deque<int> dq;
    stack<int> st;
    if (!root) return {};
    st.push(root);
    while (!st.empty()) {
      TreeNode *node = st.top();
      st.pop();
      dq.push_front(node->val);
      if (node->left) st.push(node->left);
      if (node->right) st.push(node->right);
    }
    return vector<int>(dq.begin(), dq.end());
  }
};