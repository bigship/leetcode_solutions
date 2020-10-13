// 1490. Clone N-ary Tree
/*
 * Given a root of an N-ary tree, return a deep copy (clone) of the tree.
   Each node in the n-ary tree contains a val (int) and a list (List[Node]) of its children.

class Node {
    public int val;
    public List<Node> children;
}

Nary-Tree input serialization is represented in their level order traversal,
each group of children is separated by the null value (See examples).

Follow up: Can your solution work for the graph problem?

Example 1:

Input: root = [1,null,3,2,4,null,5,6]
Output: [1,null,3,2,4,null,5,6]

Example 2:

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]

Constraints:

    The depth of the n-ary tree is less than or equal to 1000.
    The total number of nodes is between [0, 10^4].
*/
class Solution {
public:
  // Solution: n叉树的深拷贝
  // 递归的做法, 先复制根节点, 如果根节点的children数组长度不为0
  // 在循环中依次递归复制每个孩子节点
  Node *cloneTree(Node *root) {
    if (!root) return nullptr;
    Node *nroot = new Node(root->val);
    if (root->children.size() != 0) {
      int n = root->children.size();
      nroot->children = vector<Node *>(n, nullptr);
      for (int i = 0; i < n; i++) {
        nroot->children[i] = cloneTree(root->children[i]);
      }
    }
    return nroot;
  }
};

