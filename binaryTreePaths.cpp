// 257. Binary Tree Paths

/*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
*/

class Solution {
public:
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> ans;
    if (!root) return ans;
    stack<pair<TreeNode *, string>> st;
    st.push(make_pair(root, ""));
    while (!st.empty()) {
      auto node = st.top();
      st.pop();
      if (node.first->right) st.push(make_pair(node.first->right, node.second + to_string(node->val) + "->"));
      if (node.first->left) st.push(make_pair(node.first->left, node.second + to_string(node->val) + "->"));
      if (node.first->left == nullptr && node.first->right == nullptr) {
        node.second += std::to_string(node.first->val);
        ans.push_back(node.second);
      }
    }
    return ans;
  }
};

// Recursion solution
class Solution2 {
public:
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    getPath(root, "", ans);
    return ans;
  }
private:
  void getPath(TreeNode *root, string cur, vector<string>& ans) {
    if (!root) return;
    if (!root->left && !root->right) {
      cur += to_string(root->val);
      ans.push_back(cur);
      return ;
    }
    cur += to_string(root->val);
    cur += "->";
    getPath(root->left, cur, ans);
    getPath(root->right, cur, ans);
  }
};

