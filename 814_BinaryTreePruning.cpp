// 814. Binary Tree Pruning
/*
 * Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.
   A subtree of a node `node` is node plus every node that is a descendant of node.


Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation:
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.
*/

// 二叉树的后续遍历
class Solution {
public:
  TreeNode* pruneTree(TreeNode* root) {
    bool res = helper(root);
    if (res) return root;
    return nullptr;
  }
private:
  bool helper(TreeNode *root) {
    if (!root) {
      return false;
    }

    if (!root->left && !root->right) {
      return root->val == 1;
    }

    bool l = helper(root->left);
    bool r = helper(root->right);
    if (!l) {
      root->left = nullptr;
    }
    if (!r) {
      root->right = nullptr;
    }

    return l || r || root->val == 1;
  }
};
