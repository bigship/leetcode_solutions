// 1351. Count Negative Numbers in a Sorted Matrix
/*
 * Given a m * n matrix grid which is sorted in non-increasing order both
 * row-wise and column-wise.
   Return the number of negative numbers in grid.

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0

Example 3:

Input: grid = [[1,-1],[-1,-1]]
Output: 3

Example 4:

Input: grid = [[-1]]
Output: 1

Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 100
    -100 <= grid[i][j] <= 100
*/

class Solution {
public:
  // 从左下角开始找, 如果小于0, 则这一行后面的都满足, 往上移动一行
  // 如果大于等于0, 往右找
  int countNegatives(vector<vector<int>>& grid) {
    const int row = grid.size();
    const int col = grid[0].size();
    int ans = 0;
    int i = row - 1, j = 0;
    while (i >= 0 && j <= col - 1) {
      if (grid[i][j] < 0) {
        ans += (col - j);
        i--;
      } else {
        j++;
      }
    }
    return ans;
  }
};

