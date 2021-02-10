// 538. Convert BST to Greater Tree
/*
 * Given the root of a Binary Search Tree (BST), convert it to a Greater Tree
 * such that every key of the original BST is changed to the original key plus
 * sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:
    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
Note: This question is the same as 1038: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
*/

// Recursion. Reverse in-order traversal
class Solution {
public:
  TreeNode *convertBST(TreeNode *root) {
    if (root) {
      convertBST(root->right);
      sum += root->val;
      root->val = sum;
      convertBST(root->left);
    }
  }
private:
  int sum = 0;
};

// Iterative Solution. Reverse in-order traversal
class Solution2 {
public:
  TreeNode *convertBST(TreeNode *root) {
    int sum = 0;
    std::stack<TreeNode *> sk;
    TreeNode *node = root;
    while (!sk.empty() || node) {
      while (node) {
        sk.push(node);
        node = node->right;
      }
      TreeNode *cur = sk.top();
      sum += cur->val;
      cur->val = sum;
      sk.pop();
      if (cur->left) {
        node = cur->left;
      }
    }

    return root;
  }
};
