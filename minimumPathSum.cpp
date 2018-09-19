// 64. Minimum Path Sum

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

*/

/*
Dynamic programming

[                      [
  [1,3,1],                [1, 4, 5],
  [1,5,1],     ->         [2, 7, 6],
  [4,2,1]                 [6, 8, 7]
]                      ]

*/

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    int cols = grid[0].size();
    int rows = grid.size();

    vector<vector<int>> dp(grid);
    int i = 0, j = 1;
    for (; j < cols; j++) {
      dp[i][j] = dp[i][j-1] + dp[i][j];
    }
    i = 1, j = 0;
    for (; i < rows; i++) {
      dp[i][j] = dp[i-1][j] + dp[i][j];
    }

    for (int i = 1; i < rows; i++) {
      for (int j = 1; j < cols; j++) {
        dp[i][j] = dp[i][j] + min(dp[i][j-1], dp[i-1][j]);
      }
    }

    return dp[row-1][cols-1];
  }
};
