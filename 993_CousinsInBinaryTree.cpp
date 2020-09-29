// 993. Cousins in Binary Tree
/*
 * In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
   Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
Return true if and only if the nodes corresponding to the values x and y are cousins.

Example 1:

Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2:

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

Example 3:

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false

Constraints:

    The number of nodes in the tree will be between 2 and 100.
    Each node has a unique integer value from 1 to 100.
*/

class Solution {
public:
  // Solution: 迭代法 BFS. 利用level order遍历, 将当前节点以及该节点的root val加入
  // 最后遍历所有的层, 如果目标值位于当前层, 且它们的root val不相同表示它们是cousins
  // 否则就返回false
  // Time: O(n)
  bool isCousins(TreeNode *root, int x, int y) {
    if (!root) return false;
    std::queue<pair<TreeNode *, int>> q;
    q.push({root, root->val});
    while (!q.empty()) {
      int n = q.size();
      vector<pair<TreeNode *, int>> cur;
      bool foundx = false;
      bool foundy = false;
      int px = -1;
      int py = -1;

      for (int i = 0; i < n; i++) {
        auto a = q.front();
        q.pop();
        cur.push_back(a);
        TreeNode *tmp = a.first;
        if (tmp->left) q.push({tmp->left, a.first->val});
        if (tmp->right) q.push({tmp->right, a.first->val});
      }

      for (int i = 0; i < cur.size(); i++) {
        if (x == cur[i].first->val) {
          foundx = true;
          px = cur[i].second;
        }
        if (y == cur[i].first->val) {
          foundy = true;
          py = cur[i].second;
        }
      }

      if (foundx && foundy && px != py)
        return true;
      vector<pair<TreeNode *, int>>().swap(cur);
    }
    return false;
  }

  // Solution: 递归解法, 先根遍历, 遇到x和y时分别记录下x和y的层次以及它们对应的父节点
  // 最后判断: x和y的层次相同且父节点不同, 则它们就是兄弟节点
  bool isCousins_recursive(TreeNode *root, int x, int y) {
    if (!root) return false;
    preorder(root, x, y, nullptr, 0);
    if (dx == dy && px != py) {
      return true;
    }
    return false;
  }
private:
  int dx;        // x的层次
  int dy;        // y的层次
  TreeNode *px;  // x的父节点
  TreeNode *py;  // y的父节点

  void preorder(TreeNode *root, int x, int y, TreeNode *parent, int depth) {
    if (!root) return ;
    if (root->val == x) {
      dx = depth;
      px = parent;
    }
    if (root->val == y) {
      dy = depth;
      py = parent;
    }
    preorder(root->left, x, y, root, depth + 1);
    preorder(root->right, x, y, root, depth + 1);
  }
};


