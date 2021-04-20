// 589. N-ary Tree Preorder Traversal
/*
 * Given the root of an n-ary tree, return the preorder traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order traversal.
Each group of children is separated by the null value (See examples)
*/

class Solution {
public:
  vector<int> preorder(Node *root) {
    vector<int> ans;
    if (!root) return ans;
    std::stack<Node *> sk;
    sk.push(root);
    while (!sk.empty()) {
      Node *node = sk.top();
      sk.pop();
      ans.push_back(node->val);
      if (node->children.size() != 0) {
        for (int i = node->children.size() - 1; i >= 0; i--) {
          sk.push(node->children[i]);
        }
      }
    }
    return ans;
  }

  vector<int> preorderRecursively(Node *root) {
    vector<int> ans;
    preorder(root, ans);
    return ans;
  }
private:
  void preorder(Node *root, vector<int>& ans) {
    if (!root) return;
    ans.push_back(root->val);
    if (root->children.size() != 0) {
      for (int i = 0; i < root->children.size(); i++) {
        preorder(root->children[i], ans);
      }
    }
  }
};

