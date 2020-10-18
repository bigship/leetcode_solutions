// 1120. Maximum Average Subtree
/*
 * Given the root of a binary tree, find the maximum average value of any subtree of that tree.
   (A subtree of a tree is any node of that tree plus all its descendants.
    The average value of a tree is the sum of its values, divided by the number of nodes.)

Input: [5,6,1]
Output: 6.00000
Explanation:
For the node with value = 5 we have an average of (5 + 6 + 1) / 3 = 4.
For the node with value = 6 we have an average of 6 / 1 = 6.
For the node with value = 1 we have an average of 1 / 1 = 1.
So the answer is 6 which is the maximum.

Note:
  The number of nodes in the tree is between 1 and 5000.
  Each node will have a value between 0 and 100000.
  Answers will be accepted as correct if they are within 10^-5 of the correct answer.
*/

// Solution: 计算每颗子树的节点和, 计算每颗子树的节点总数, 求出当前子树的平均值
// 遍历整棵树, 以每一个节点为root的子树计算平均值, 求最大即可
class Solution {
public:
  double maximumAverageSubtree(TreeNode *root) {
    double ans = 0.0;
    ans = (double)sumOfTree(root) / cntOfNodes(root);
    ans = std::max(ans, maximumAverageSubtree(root->left));
    ans = std::max(ans, maximumAverageSubtree(root->right));
    return ans;
  }
private:
  int sumOfTree(TreeNode *root) {
    if (!root) return 0;
    if (!root->left && !root->right)
      return root->val;
    return sumOfTree(root->left) + sumOfTree(root->right) + root->val;
  }

  int cntOfNodes(TreeNode *root) {
    if (!root) return 0;
    if (!root->left && !root->right)
      return 1;
    return cntOfNodes(root->left) + cntOfNodes(root->right) + 1;
  }
};


// Solution: 为每颗子树维护一个状态. 遍历每个节点时始终维护这个状态
class Solution2 {
public:
  double maximumAverageSubtree(TreeNode *root) {
    return maxAverage(root).maxAve;
  }
private:
  struct State {
    int nodeCnt;
    int valSum;
    double maxAve;
  };

  State maxAverage(TreeNode *root) {
    if (!root) return {0, 0, 0.0};
    if (!root->left && !root->right)
      return {1, root->val, root->val / 1.0};

    State left = maxAverage(root->left);
    State right = maxAverage(root->right);
    int sum = left.valSum + right.valSum + root->val;
    int cnt = left.nodeCnt + right.nodeCnt + 1;
    double maxAve = max(1.0 * sum / cnt, max(left.maxAve, right.maxAve));
    return {cnt, sum, maxAve};
  }
};
