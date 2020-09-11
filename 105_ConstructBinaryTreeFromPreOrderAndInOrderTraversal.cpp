// 105. Construct Binary Tree from Preorder and Inorder Traversal
/*
 * Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]

Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/

class Solution {
public:
  TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> map;
    for (int i = 0; i < inorder.size(); i++)
      map[inorder[i]] = i;

    return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size(), map);
  }
private:
  // 划分左右子树的范围, 递归求解左右子树
  // preorder的第一个元素一定是根节点, 找出在inorder中的索引idx, 因此在inorder中
  // idx左边的部分全部是左子树的节点, idx右边的部分全部都是右子树的节点
  TreeNode *buildTree(vector<int>& preorder, int pstart, int pend,
      vector<int>& inorder, int istart, int iend, unordered_map<int, int>& map) {
    if (pstart >= pend) return nullptr;
    TreeNode *root = new TreeNode(preorder[pstart]);
    int i_root_idx = map[root->val];
    int leftnum = i_root_idx - istart;
    root->left = buildTree(preorder, pstart+1, pstart+leftnum+1, inorder, istart, leftnum, map);
    root->right = buildTree(preorder, pstart+leftnum+1, pend, inorder, i_root_idx+1, iend, map);
    return root;
  }
};

