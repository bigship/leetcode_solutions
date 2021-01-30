// 987. Vertical Order Traversal of a Binary Tree
/*
 * Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
For each node at position (x, y), its left and right children will be at positions (x - 1, y - 1) and (x + 1, y - 1) respectively.

The vertical order traversal of a binary tree is a list of non-empty reports for each unique x-coordinate from left to right.
Each report is a list of all nodes at a given x-coordinate.
The report should be primarily sorted by y-coordinate from highest y-coordinate to lowest.
If any two nodes have the same x-coordinate in the report, the node with the smaller value should appear earlier.

Return the vertical order traversal of the binary tree.
*/
class Solution {
public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root)
      return ans;

    vector<Triplet> nodeList;
    BFS(root, nodeList);

    std::sort(nodeList.begin(), nodeList.end(), [&](Triplet& t1, Triplet& t2) {
      if (t1.column == t2.column) {
        if (t1.row == t2.row) {
          return t1.node->val < t2.node->val;
        } else {
          return t1.row < t2.row;
        }
      } else {
        return t1.column < t2.column;
      }
    });

    // extract values
    vector<int> curCol;
    int curColIndex = nodeList[0].column;
    for (auto& triple : nodeList) {
      int col = triple.column;
      int val = triple.node->val;
      if (col == curColIndex) {
        curCol.push_back(val);
      } else {
        ans.push_back(curCol);
        vector<int>().swap(curCol);
        curCol.push_back(val);
        curColIndex = col;
      }
    }
    ans.push_back(curCol);
    return ans;
  }
private:
  struct Triplet {
    int column;
    int row;
    TreeNode *node;
  };

  void BFS(TreeNode *root, vector<Triplet>& nodeList) {
    std::queue<Triplet> q;
    int row = 0, col = 0;
    q.push({col, row, root});
    while (!q.empty()) {
      auto triple = q.front();
      q.pop();
      root = triple.node;
      row = triple.row;
      col = triple.column;

      if (root) {
        nodeList.push_back({col, row, root});
        q.push({col - 1, row + 1, root->left});
        q.push({col + 1, row + 1, root->right});
      }
    }
  }
};



