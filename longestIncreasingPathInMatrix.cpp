// 329. Longest Increasing Path in a Matrix

/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down.
You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

Input: nums =
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:

Input: nums =
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;
    rows = matrix.size();
    cols = matrix[0].size();
    dp = vector<vector<int>>(rows, vector<int>(cols, -1));  // 全部初始化为-1, 记忆化搜索时判断是否已有解
    int ans = 0;
    for (int x = 0; x < rows; x++) {
      for (int y = 0; y < cols; y++) {
        ans = max(ans, dfs(matrix, x, y));
      }
    }
    return ans;
  }

private:
  int rows;
  int cols;
  vector<vector<int>> dp;

  int dfs(vector<vector<int>>& mat, int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];   // 记忆化, 已有解直接返回
    static int dirs[] = {0, -1, 0, 1, 0};  // 控制方向
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++) {
      int tx = x + dirs[i];
      int ty = y + dirs[i+1];
      if (tx < 0 || ty < 0 || tx >= rows || ty >= cols || mat[tx][ty] <= mat[x][y])
        continue;
      dp[x][y] = max(dp[x][y], 1 + dfs(mat, tx, ty));
    }
    return dp[x][y];
  }
};
