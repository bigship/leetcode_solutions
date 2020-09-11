// 106. Construct Binary Tree from inorder and postorder traversal
/*
 * Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
For example, given

inorder   = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/

class Solution {
public:
  TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> map;
    for (int i = 0; i < inorder.size(); i++) {
      map[inorder[i]] = i;
    }
    return buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size(), map);
  }
private:
  TreeNode *buildTree(vector<int>& inorder, int istart, int iend,
      vector<int>& postorder, int pstart, int pend, unordered_map<int, int>& map) {
    if (pstart == pend) return nullptr;
    int root_val = postorder[pend - 1];
    int root_idx = map[root_val];
    int leftnum = root_idx - istart;
    TreeNode *root = new TreeNode(root_val);
    root->left = buildTree(inorder, istart, root_idx, postorder, pstart, pstart+leftnum, map);
    root->right = buildTree(inorder, root_idx+1, iend, postorder, pstart+leftnum, pend-1, map);
    return root;
  }
};


