// 695. Max Area of Island
/*
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land)
 * connected 4-directionally (horizontal or vertical.)
 * You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array.
(If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]

Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.

Example 2:

[[0,0,0,0,0,0,0,0]]

Given the above grid, return 0.

Note: The length of each dimension in the given grid does not exceed 50.
*/

class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    const int row = grid.size();
    const int col = grid[0].size();
    int ans = 0;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (grid[i][j] == 1) {
          int cur = dfs(i, j, row, col, grid);
          if (ans < cur) {
            ans = cur;
          }
        }
      }
    }
    return ans;
  }
private:
  vector<int> dirs = {-1, 0, 1, 0, -1};

  int dfs(int x, int y, int row, int col, vector<vector<int>>& grid) {
    int cnt = 0;
    grid[x][y] = 0;
    cnt++;
    for (int k = 0; k < 4; k++) {
      int tx = x + dirs[k];
      int ty = y + dirs[k+1];
      if (tx >= 0 && ty >= 0 && tx < row && ty < col && grid[tx][ty] == 1) {
        cnt += dfs(tx, ty, row, col, grid);
      }
    }
    return cnt;
  }
};
