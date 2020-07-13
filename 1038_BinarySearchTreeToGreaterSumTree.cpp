// 1038. Binary Search Tree to Greater Sum Tree
/*
 * Given the root of a binary search tree with distinct values, modify it so that
 * every node has a new value equal to the sum of the values of the original tree
 * that are greater than or equal to node.val.

As a reminder, a binary search tree is a tree that satisfies these constraints:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
*/

/* Constraints:

    The number of nodes in the tree is between 1 and 100.
    Each node will have value between 0 and 100.
    The given tree is a binary search tree.
*/

class Solution {
public:
    // 中序遍历的变种, 先右后左不断累加即可
    TreeNode *bstToGst(TreeNode *root) {
        stack<TreeNode *> s;
        TreeNode *cur = root;
        int prev = 0;
        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                cur = cur->right;
            }
            cur = s.top();
            s.pop();
            cur->val = cur->val + prev;
            prev = cur->val;
            cur = cur->left;
        }
        return root;
    }
};

