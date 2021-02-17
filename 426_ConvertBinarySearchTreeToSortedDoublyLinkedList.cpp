// 426. Convert Binary Search Tree to Sorted Doubly Linked List
/*
 * Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

You can think of the left and right pointers as synonymous to the predecessor and successor pointers in a doubly-linked list.
For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.

We want to do the transformation in place.
After the transformation, the left pointer of the tree node should point to its predecessor,
and the right pointer should point to its successor.
You should return the pointer to the smallest element of the linked list.
*/

// BST 中序遍历有序. 先按顺序拿到节点, 遍历节点依次修改left和right指针
// 注意最后一个节点的right要指向第一个节点, 第一个节点的left要指向最后一个节点
class Solution {
public:
  Node *treeDoublyList(Node *root) {
    std::stack<Node *> sk;
    Node *cur = root;
    vector<Node *> nodes;
    while (!sk.empty() || cur) {
      while (cur) {
        sk.push(cur);
        cur = cur->left;
      }
      Node *node = sk.top();
      sk.pop();
      if (node) {
        nodes.push_back(node);
        cur = node->right;
      }
    }

    if (nodes.empty())
      return nullptr;

    if (nodes.size() >= 2) {
      for (int i = 0, j = 1; i < nodes.size() && j < nodes.size(); i++, j++) {
        nodes[i]->right = nodes[j];
        nodes[j]->left = nodes[i];
      }
    }
    nodes[nodes.size() - 1]->right = nodes[0];
    nodes[0]->left = nodes[nodes.size() - 1];
    return nodes[0];
  }
};
