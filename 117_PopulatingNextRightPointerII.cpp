// 117. Populating next right pointers in each node II
/*
 * Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.



Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
 */


class Solution {
public:
    Node *connect(Node *root) {
        if (!root || (!root->left &&!root->right)) return root;
        if (root->left) {
            if (root->right) {
                root->left->next = root->right;
            } else {
                root->left->next = getNext(root->next);
            }
        }
        if (root->right) {
            root->right->next = getNext(root->next);
        }
        connect(root->right);
        connect(root->left);
        return root;
    }

    Node *getNext(Node *next) {
        while (next) {
            if (next->left) return next->left;
            if (next->right) return next->right;
            next = next->next;
        }
        return NULL;
    }
};
