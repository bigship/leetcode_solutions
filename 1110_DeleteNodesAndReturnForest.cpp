// 1110. Delete Nodes And Return Forest
/*
 * Given the root of a binary tree, each node in the tree has a distinct value.
After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
Return the roots of the trees in the remaining forest.
You may return the result in any order.

Example 1:

Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]

*/

class Solution {
public:
  vector<TreeNode *> delNodes(TreeNode *root, vector<int>& to_delete) {
    unordered_set<TreeNode *> ans;
    if (!root) return {};

    ans.insert(root);
    int idx = 0;
    dfs(ans, idx, to_delete);
    return vector<TreeNode *>(ans.begin(), ans.end());
  }

private:
  void dfs(unordered_set<TreeNode *>& ans, int idx, vector<int>& to_delete) {
    if (idx == to_delete.size()) {
      return ;
    }

    int target = to_delete[idx];
    bool deleteSuccess = false;
    for (auto it = ans.begin(); it != ans.end(); it++) {
      delNode(*it, target, nullptr, deleteSuccess, false, ans);
      if (deleteSuccess) {
        break;
      }
    }

    dfs(ans, idx + 1, to_delete);
  }

  void delNode(TreeNode *root, int target, TreeNode *parent,
      bool& deleteSuccess, bool isLeft, unordered_set<TreeNode *>& ans)
  {
    if (!root) return ;
    if (root->val == target) {
      if (root->left) ans.insert(root->left);
      if (root->right) ans.insert(root->right);
      if (!parent) {
        ans.erase(root);
      } else {
        if (isLeft) {
          parent->left = nullptr;
        } else {
          parent->right = nullptr;
        }
      }
    }
    delNode(root->left, target, root, deleteSuccess, true, ans);
    delNode(root->right, target, root, deleteSuccess, false, ans);
  }
};


