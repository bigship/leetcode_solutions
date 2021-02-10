// 980. Unique Paths III
/*
 * On a 2-dimensional grid, there are 4 types of squares:

    1 represents the starting square.  There is exactly one starting square.
    2 represents the ending square.  There is exactly one ending square.
    0 represents empty squares we can walk over.
    -1 represents obstacles that we cannot walk over.

Return the number of 4-directional walks from the starting square to the ending square,
that walk over every non-obstacle square exactly once.

Example 1:

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
*/

// Solution: backtracking
class Solution {
public:
  int uniquePathsIII(vector<vector<int>>& grid) {
    int nonObstacles = 0, startx = 0, starty = 0;
    const int rows = grid.size();
    const int cols = grid[0].size();

    for (int row = 0; row < rows; row++) {
      for (int col = 0; col < cols; col++) {
        int cell = grid[row][col];
        if (cell > 0)
          nonObstacles++;
        if (cell == 1) {
          startx = row;
          starty = col'
        }
      }
    }

    int totalcnt = 0;
    backtrack(grid, startx, starty, nonObstacles, totalcnt);
    return totalcnt;
  }
private:
  vector<int> dirs = {-1, 0, 1, 0, -1};

  void backtrack(vector<vector<int>>& grid, int row, int col, int remain, int& ans) {
    if (grid[row][col] == 2 && remain == 1) {
      ans += 1;
      return ;
    }

    // mark the square as visited.
    int tmp = grid[row][col];
    grid[row][col] = -4;
    remain -= 1;

    for (int k = 0; k < 4; k++) {
      int tx = row + dirs[k];
      int ty = col + dirs[k+1];

      if (tx >= 0 && tx < grid.size() && ty >= 0 && ty < grid[0].size() && grid[tx][ty] >= 0) {
        backtrack(grid, tx, ty, remain, ans);
      }
    }
    grid[row][col] = tmp;  // backtrack.
  }
};
