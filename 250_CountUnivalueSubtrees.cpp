// 250. Count Univalue Subtrees
/*
 * Given the root of a binary tree, return the number of uni-value subtrees.
   A uni-value subtree means all nodes of the subtree have the same value.

Example 1:

Input: root = [5,1,5,5,5,null,5]
Output: 4

Example 2:

Input: root = []
Output: 0

Example 3:

Input: root = [5,5,5,5,5,null,5]
Output: 6

Constraints:

    The numbrt of the node in the tree will be in the range [0, 1000].
    -1000 <= Node.val <= 1000
*/
class Solution {
  // 针对每个节点调用univalTree看其是否所有节点的值相同, 若是则更新计数
public:
  int countUnivalSubtrees(TreeNode *root) {
    int ans = 0;
    traversal(root, ans);
    return ans;
  }

private:
  void traversal(TreeNode *root, int& ans) {
    if (!root) return ;

    bool res = true;
    univalTree(root, root->val, res);
    if (res)
      ans++;
    traversal(root->left, ans);
    traversal(root->right, ans);
  }

  // 遍历当前树的所有节点, 如果出现节点的值和根节点值不一致则不是unival Tree
  void univalTree(TreeNode *root, int val, bool& res) {
    if (!root) return ;
    if (root->left && root->left->val != val) {
      res = false;
      return ;
    }
    if (root->right && root->right->val != val) {
      res = false;
      return ;
    }
    univalTree(root->left, val, res);
    univalTree(root->right, val, res);
  }
};


