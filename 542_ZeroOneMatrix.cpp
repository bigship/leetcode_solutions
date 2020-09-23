// 542. 0 1 Matrix
/*
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
   The distance between two adjacent cells is 1.

Example 1:

Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Example 2:

Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]

Note:

    The number of elements of the given matrix will not exceed 10,000.
    There are at least one 0 in the given matrix.
    The cells are adjacent in only four directions: up, down, left and right.
*/
//
// 如果当前cell为0, 则结果一定为0
// 如果当前cell不为0, 则结果为与其四面相邻的cell的结果 + 1 (结果只能从与其相邻的节点得到)
// dp[i][j] = std::min(dp[i-1][j], dp[i][j-1], dp[i+1][j], dp[i][j+1]) + 1
// 四面相邻的结果取最小再加1
// 但是求解的过程中会出现需要某个cell的解但这个解还没有求出的问题
// 因此需要做两次dp, 第一次处理左上, 第二次处理右下
class Solution {
public:
  int row = matrix.size();
  if (row == 0) return matrix;
  int col = matrix[0].size();

  vector<vector<int>> dp(row, vector<int>(col, INT_MAX - 100000));

  // First pass: check for left and top
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (matrix[i][j] == 0) {
        dp[i][j] = 0;
      } else {
        if (i > 0)
          dp[i][j] = std::min(dp[i][j], dp[i-1][j] + 1);
        if (j > 0)
          dp[i][j] = std::min(dp[i][j], dp[i][j-1] + 1);
      }
    }
  }

  // Second pass; check for right and bottom
  for (int i = row - 1; i >= 0; i--) {
    for (int j = col - 1; j >= 0; j--) {
      if (i < row - 1) {
        dp[i][j] = std::min(dp[i][j], dp[i+1][j] + 1);
      }
      if (j < col - 1) {
        dp[i][j] = std::min(dp[i][j], dp[i][j+1] + 1);
      }
    }
  }

  return dp;
};



