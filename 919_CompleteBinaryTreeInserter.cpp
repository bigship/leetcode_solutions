// 919. Complete Binary Tree Inserter
/*
 * A complete binary tree is a binary tree in which every level, except possibly the last,
 * is completely filled, and all nodes are as far left as possible.

Write a data structure CBTInserter that is initialized with a complete binary tree and supports the following operations:

CBTInserter(TreeNode root) initializes the data structure on a given tree with head node root;
CBTInserter.insert(int v) will insert a TreeNode into the tree with value node.val = v so that the tree remains complete,
and returns the value of the parent of the inserted TreeNode;
CBTInserter.get_root() will return the head node of the tree.

Example 1:

Input: inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
Output: [null,1,[1,2]]
*/

class CBInserter {
public:
  CBInserter(TreeNode *root) {
    this->root = root;
    std::queue<TreeNode *> q;
    q.push(this->root);

    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();
      if (!node->left || !node->right) {
        deque.push_back(node);
      }
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
  }

  int insert(int v) {
    TreeNode *node = deque.front();
    deque.push_back(new TreeNode(v));
    if (!node->left) {
      node->left = deque.back();
    } else {
      node->right = deque.back();
      deque.pop_front();
    }
    return node->val;
  }

  TreeNode *get_root() {
    return this->root;
  }
private:
  TreeNode *root;
  std::deque<TreeNode *> deque;
};

