// 1008. Construct Binary Search Tree from Preorder Traversal
/*
 * Return the root node of a binary search tree that matches the given preorder traversal.
(Recall that a binary search tree is a binary tree where for every node,
 any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.
 Also recall that a preorder traversal displays the value of the node first,
 then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a
binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Constraints:
    1 <= preorder.length <= 100
    1 <= preorder[i] <= 10^8
    The values of preorder are distinct.
*/
class Solution {
public:
  TreeNode *bstFromPreorder(vector<int>& preorder) {
    int idx = 0;
    return helper(preorder, INT_MIN, INT_MAX, idx);
  }
private:
  TreeNode *helper(vector<int>& preorder, int lower, int upper, int& idx) {
    if (idx == preorder.size())
      return nullptr;

    int cur = preorder[idx];
    if (cur < lower || cur > upper)   // 不在范围之内, 返回空指针. 表示这个位置无法填入一个节点
      return nullptr;
    idx++;
    TreeNode *root = new TreeNode(cur);
    root->left = helper(preorder, lower, cur, idx);     // 左子树, 最大的节点值不能超过cur
    root->right = helper(preorder, cur, upper, idx);    // 右子树, 最小的节点值不能小于cur
    return root;
  }
};

