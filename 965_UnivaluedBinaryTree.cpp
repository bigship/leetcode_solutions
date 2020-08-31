// 965. Univalued Binary Tree
/*
 * A binary tree is univalued if every node in the tree has the same value.
   Return true if and only if the given tree is univalued.

Example 1:

Input: [1,1,1,1,1,null,1]
Output: true

Example 2:

Input: [2,2,2,5,2]
Output: false

Note:

    The number of nodes in the given tree will be in the range [1, 100].
    Each node's value will be an integer in the range [0, 99].
*/
class Solution {
public:
  // Solution: 遍历每个节点, prev表示前一个访问过的节点, 如果prev->val != cur->val
  // 提前返回false. 遍历完所有节点后都没有出现不同的节点, 返回true
  bool isUnivalTree(TreeNode *root) {
    if (!root) return true;
    int *prev = nullptr;
    bool ans = true;
    check(root, ans, &prev);
    return ans;
  }
private:
  void check(TreeNode *root, bool& ans, int **prev) {
    if (!root) return;
    if (*prev && **prev != root->val) {
      ans = false;
      return ;
    }
    *prev = &(root->val);
    check(root->left, ans, prev);
    check(root->right, ans, prev);
  }
};

