// 314. Binary Tree Vertical Order Traversal
/*
 * Given the root of a binary tree, return the vertical order traversal of its nodes' values.
 * (i.e., from top to bottom, column by column).
   If two nodes are in the same row and column, the order should be from left to right.
 */

class Solution {
public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root)
      return ans;
    unordered_map<int, vector<int>> columnTable;
    queue<pair<TreeNode *, int>> q;
    int column = 0;
    q.push({root, column});

    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      root = p.first;
      column = p.second;

      if (root) {
        columnTable[column].push_back(root->val);
        q.push({root->left, column - 1});
        q.push({root->right, column + 1});
      }
    }
    vector<int> sortedColumn;
    for (auto it = columnTable.begin(); it != columnTable.end(); it++) {
      sortedColumn.push_back(it->first);
    }
    std::sort(sortedColumn.begin(), sortedColumn.end());
    for (auto& col : sortedColumn) {
      ans.push_back(columnTable[col]);
    }
    return ans;
  }
};
