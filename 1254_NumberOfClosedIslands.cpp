// 1254. Number of Closed Islands
/*
 * Given a 2D grid consists of 0s (land) and 1s (water).
 * An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally
 * (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

Example 1:

Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation:
Islands in gray are closed because they are completely surrounded by water (group of 1s).

Example 2:

Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2

Constraints:

    1 <= grid.length, grid[0].length <= 100
    0 <= grid[i][j] <=1
*/
class Solution {
public:
  int closedIsland(vector<vector<int>>& grid) {
    int cnt = 0;
    const int row = grid.size();
    if (row == 0) return cnt;
    const int col = grid[0].size();

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (grid[i][j] == 0) {
          cnt += dfs(grid, i, j);
        }
      }
    }
    return cnt;
  }
private:
  vector<int> dirs = {-1, 0, 1, 0, -1};

  int dfs(vector<vector<int>>& grid, int x, int y) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
      return 0;    // reach the bound, this is not a closed island

    if (grid[x][y] == 1)  // already visited
      return 1;

    grid[x][y] = 1;  // mark as visited
    int ret = 1;
    for (int i = 0; i < 4; i++) {
      ret = std::min(ret, dfs(grid, x + dirs[i], y + dirs[i+1]));
    }
    return ret;
  }
};

