// 285. Inorder Successor in BST
/*
 * Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
   The successor of a node p is the node with the smallest key greater than p.val.

Example 1:

Input: root = [2,1,3], p = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.

Example 2:

Input: root = [5,3,6,2,4,null,null,1], p = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.

Note:

    If the given node has no in-order successor in the tree, return null.
    It's guaranteed that the values of the tree are unique.
*/

class Solution {
public:
  // Solution: 中根遍历保存节点. 再遍历一次保存的节点找到结果
  TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
    vector<TreeNode *> nodes;
    inOrder(root, nodes);
    int idx = -1;
    for (int i = 0; i < nodes.size(); i++) {
      if (p->val == nodes[i]->val) {
        idx = i;
        break;
      }
    }
    if (idx == -1 || idx == nodes.size() - 1)
      return nullptr;
    return nodes[idx+1];
  }

  // 利用BST的性质. 如果当前节点的值小于p, 则答案一定在右子树
  // 如果当前节点的值大于p, 则当前节点是可能的解, 只需要继续
  // 往左子树搜索, 看是否能找到一个更小的值即可
  TreeNode *inorderSuccessor2(TreeNode *root, TreeNode *p) {
    TreeNode *ans = nullptr;
    TreeNode *cur = root;
    while (cur) {
      if (cur->val > p->val) {
        ans = cur;
        cur = cur->left;
      } else {
        cur = cur->right;
      }
    }
    return ans;
  }
private:
  void inOrder(TreeNode *root, vector<TreeNode *>& nodes) {
    if (!root) return;
    inOrder(root->left, nodes);
    nodes.push_back(root);
    inOrder(root->right, nodes);
  }
};


