// 361. Bomb Enemy
/*
 * Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero),
 * return the maximum enemies you can kill using one bomb.
 * The bomb kills all the enemies in the same row and column from the planted point
 * until it hits the wall since the wall is too strong to be destroyed.

Note: You can only put the bomb at an empty cell.
Example:

Input: [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
Output: 3
Explanation: For the given grid,

0 E 0 0
E 0 W E
0 E 0 0

Placing a bomb at (1,1) kills 3 enemies.
*/

class Solution {
public:
  int maxKilledEnemies(vector<vector<char>>& grid) {
    const int rows = grid.size();
    if (rows == 0)
      return 0;
    const int cols = grid[0].size();
    if (cols == 0)
      return 0;
    int ans = 0;
    for (int x = 0; x < rows; x++) {
      for (int y = 0; y < cols; y++) {
        if (grid[x][y] == '0') {
          ans = std::max(ans, enemyKills(grid, rows, cols, x, y));
        }
      }
    }
    return ans;
  }
private:
  int enemyKills(vector<vector<char>>& grid, int row, int col, int x, int y) {
    int kills = 0;
    static vector<int> dirs = {-1, 0, 1, 0, -1};
    for (int k = 0; k < 4; k++) {
      int tx = x + dirs[k];
      int ty = y + dirs[k+1];
      while (tx >= 0 && tx < row && ty >= 0 && ty < col && grid[tx][ty] != 'W') {
        if (grid[tx][ty] == 'E') {
          kills++;
        }
        tx = tx + dirs[k];
        ty = ty + dirs[k+1];
      }
    }
    return kills;
  }
};

