// 101. Symmetric Tree

/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively. 
*/

class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    return isMirror(root, root);
  }

  // Travel Tree Twice
  // If node only has left  append 0 for right, if node only has right, append 0 for left   
  // root->right->left and root->left->right should generate same sequence, only if the tree is symmetric
  bool isSymmetric_iter(TreeNode *root) {
    if (!root) return true;
    vector<int> a;
    vector<int> b;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
      TreeNode *node = st.top();
      st.pop();
      if (node) {
        a.push_back(node->val);
        st.push(node->right);
        st.push(node->left);
      } else {
        a.push_back(0);
      }
    }

    stack<TreeNode *> emptyStack{};
    st.swap(emptyStack);
    st.push(root);
    while (!st.empty()) {
      TreeNode *node = st.top();
      st.pop();
      if (node) {
        b.push_back(node->val);
        st.push(node->left);
        st.push(node->right);
      } else {
        b.push_back(0);
      }
    }

    if (a.size() != b.size()) return false;
    else {
      for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
          return false;
        }
      }
      return true;
    }
  }

private:
  bool isMirror(TreeNode *t1, TreeNode *t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return t1->val == t2->val && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
  }
};