// 221. Maximal Square
/*
 * Given an m x n binary matrix filled with 0's and 1's,
 * find the largest square containing only 1's and return its area.
 *
 */

// Solution: 定义dp[i][j]为matrix中以i, j为右下角位置的正方形的边长
class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    const int row = matrix.size();
    const int col = matrix[0].size();

    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
    int maxside = 0;
    for (int i = 1; i <= rows; ++i) {
      for (int j = 1; j <= cols; ++j) {
        if (matrix[i - 1][j - 1] == '1') {
          dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
          maxside = std::max(maxside, dp[i][j]);
        }
      }
    }
    return maxside * maxside;
  }
};
