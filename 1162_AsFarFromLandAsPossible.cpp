// 1162. As Far from Land as possible
/*
 * Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land,
 * find a water cell such that its distance to the nearest land cell is maximized, and return the distance.
 * If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

Example 1:

Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.

*/

// Same idea as Leetcode 542. 0 1 Matrix
class Solution {
public:
  int maxDistance(vector<vector<int>>& grid) {
    const int rows = grid.size();
    const int cols = grid[0].size();
    vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX - 200));

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == 1) {
          distance[i][j] = 0;
        } else {
          if (i > 0) distance[i][j] = min(distance[i][j], distance[i-1][j] + 1);
          if (j > 0) distance[i][j] = min(distance[i][j], distance[i][j-1] + 1);
        }
      }
    }

    for (int i = rows -1; i >= 0; i--) {
      for (int j = cols - 1; j >= 0; j--) {
        if (i < rows - 1) distance[i][j] = min(distance[i][j], distance[i+1][j] + 1);
        if (j < cols - 1) distance[i][j] = min(distance[i][j], distance[i][j+1] + 1);
      }
    }
    int res = INT_MIN;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        res = max(res, distance[i][j]);
      }
    }
    if (res > rows + cols - 2 || res == 0)
      return -1;
    return res;
  }
};

