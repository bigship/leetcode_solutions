// 1379. Find a Corresponding Node of a Binary Tree in a Clone of that tree
/*
 * Given two binary trees original and cloned and given a reference to a node target in the original tree.
   The cloned tree is a copy of the original tree.

Return a reference to the same node in the cloned tree.
Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.

Follow up: Solve the problem if repeated values on the tree are allowed.

Example 1:

Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree.
The answer is the yellow node from the cloned tree.

Example 2:

Input: tree = [7], target =  7
Output: 7

Example 3:

Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
Output: 4

Example 4:

Input: tree = [1,2,3,4,5,6,7,8,9,10], target = 5
Output: 5

Example 5:

Input: tree = [1,2,null,3], target = 2
Output: 2

Constraints:

    The number of nodes in the tree is in the range [1, 10^4].
    The values of the nodes of the tree are unique.
    target node is a node from the original tree and is not null.
*/
class Solution {
public:
  // Follow up: 如果允许树中的值出现重复
  // 此时BFS遍历原树, 发现target == cur (比较的是指针本身) 记录此时的层数以及当前层中的列数
  // 再次使用BFS遍历克隆树, 当层数和列数都满足时返回克隆树中的节点即可
  TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
    int level = -1;
    int pos = 0;
    bool found = false;
    std::queue<TreeNode *> q;
    q.push(original);
    while (!q.empty()) {
      int n = q.size();
      level++;
      for (int i = 0; i < n; i++) {
        TreeNode *cur = q.front();
        q.pop();
        if (cur == target) {
          pos = i;
          found = true;
          break;
        }
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
      }
      if (found)
        break;
    }

    int newLevel = -1;
    std::queue<Node *>().swap(q);
    q.push(cloned);
    while (!q.empty()) {
      int n = q.size();
      newLevel++;
      for (int i = 0; i < n; i++) {
        TreeNode *cur = q.front();
        q.pop();
        if (newLevel == level && cur->val == target->val && i == pos) {
          return cur;
        }
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
      }
    }
    return nullptr;
  }
};

