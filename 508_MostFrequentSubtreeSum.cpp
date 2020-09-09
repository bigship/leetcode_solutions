// 508. Most Frequent Substree Sum
/*
 *  Given the root of a tree, you are asked to find the most frequent subtree sum.
 *  The subtree sum of a node is defined as the sum of all the node values formed by
 *  the subtree rooted at that node (including the node itself). So what is the most
 *  frequent subtree sum value? If there is a tie, return all the values with the highest
 *  frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3

return [2, -3, 4], since all the values happen only once, return all of them in any order.

Examples 2
Input:

  5
 /  \
2   -5

return [2], since 2 happens twice, however -5 only occur once.

Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
*/

class Solution {
public:
  vector<int> findFrequentTreeSum(TreeNode *root) {
    vector<int> ans;
    dfs(root);
    for (auto it = map.begin(); it != map.end(); it++) {
      if (it->second == maxCnt) {
        ans.push_back(it->first);
      }
    }
    return ans;
  }
private:
  int maxCnt = 0;
  unordered_map<int, int> map;

  int dfs(TreeNode *root) {
    if (!root) return 0;
    int s = dfs(root->left) + dfs(root->right) + root->val;
    maxCnt = std::max(maxCnt, ++map[s]);
    return s;
  }
};
