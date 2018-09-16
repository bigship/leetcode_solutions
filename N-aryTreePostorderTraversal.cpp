// 590. N-ary Tree Postorder Traversal

/*
Given an n-ary tree, return the postorder traversal of its nodes' values.
 

For example, given a 3-ary tree:
                1
             /  |  \
            3   2   4
           / \
          5   6
 

Return its postorder traversal as: [5,6,3,2,4,1].
 

Note: Recursive solution is trivial, could you do it iteratively?
*/

// Solution same as BinaryTree postorder traversal

class Solution {
public:
  vector<int> postorder(Node *root) {
    if (!root) return {};
    stack<Node *> st;
    deque<int> dq;
    st.push(root);
    while (!st.empty()) {
      Node *n = st.top();
      st.pop();
      dq.push_front(n->val);
      vector<Node *> children = n->children;
      if (children.size()) {
        for (const auto& child : children) {
          st.push(child);
        }
      }
    }
    return vector<int>(dq.begin(), dq.end());
  }
};