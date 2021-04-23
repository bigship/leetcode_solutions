// 510. Inorder Successor in BST II
/*
 * Given a node in a binary search tree, return the in-order successor of that node in the BST.
 * If that node has no in-order successor, return null.

The successor of a node is the node with the smallest key greater than node.val.
You will have direct access to the node but not to the root of the tree.
Each node will have a reference to its parent node. Below is the definition for Node:

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
*/

class Solution {
public:
  Node* inorderSuccessor(Node* node) {
    if (!node) return nullptr;

    if (!node->right) {
      if (!node->parent) return nullptr;
      Node *p = node->parent;
      while (p && p->val < node->val) {
        p = p->parent;
      }
      return p;
    }

    Node *right = node->right;
    Node *prev = nullptr;
    while (right) {
      prev = right;
      right = right->left;
    }
    return prev;
  }
};
