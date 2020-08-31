// 897. Increasing Order Search Tree
/*
 * Given a binary search tree, rearrange the tree in in-order so that the leftmost
 * node in the tree is now the root of the tree, and every node has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9

Constraints:
  The number of nodes in the given tree will be between 1 and 100.
  Each node will have a unique integer value from 0 to 1000.
*/

class Solution {
public:
  // Solution: in-order traversal + build tree
  TreeNode *increasingBST(TreeNode *root) {
    vector<int> vals;
    stack<TreeNode *> sk;
    vector<int> vals;
    TreeNode *cur = root;
    while (cur || !sk.empty()) {
      while (cur) {
        sk.push(cur);
        cur = cur->left;
      }
      TreeNode *node = sk.top();
      sk.pop();
      vals.push_back(node->val);
      cur = node->right;
    }

    TreeNode *newroot = root;
    newroot->val = vals[0];
    for (int i = 1; i < vals.size(); i++) {
      if (newroot->left) {
        delete newroot->left;
        newroot->left = nullptr;
      }
      if (newroot->right) {
        newroot = newroot->right;
        newroot->val = vals[i];
      } else {
        newroot->right = new TreeNode(vals[i]);
        newroot = newroot->right;
      }
    }
    return root;
  }
};


