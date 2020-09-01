// 463. Island Perimeter
/*
 * You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally).
The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
The island doesn't have "lakes" (water inside that isn't connected to the water around the island).
One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:
*/

class Solution {
public:
  // Solution: 总的岛屿格子数量 * 4 - 相邻岛屿的数量
  int islandPerimeter(vector<vector<int>>& grid) {
    const int row = grid.size();
    const int col = grid[0].size();
    int connected = 0;
    int totalcnt = 0;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (grid[i][j] == 1) {
          totalcnt++;
          if (i+1 < row && grid[i+1][j] == 1) ++connected;
          if (i-1 >= 0 && grid[i-1][j] == 1) ++connected;
          if (j+1 < col && grid[i][j+1] == 1) ++connected;
          if (j-1 >= 0 && grid[i][j-1] == 1) ++connected;
        }
      }
    }
    return totalcnt * 4 - connected;
  }
};
