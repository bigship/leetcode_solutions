// 1631. Path With Minumum Effort
/*
 * You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns,
 * where heights[row][col] represents the height of cell (row, col).
 * You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed).
 * You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
*/

class Solution {
public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    int left = 0, right = 1000000;
    int res = right;
    while (left <= right) {
      int mid = (right - left) / 2 + left;
      if (canReach(heights, mid)) {
        res = std::min(res, mid);
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return res;
  }
private:
  vector<int> dirs = {-1, 0, 1, 0, -1};

  bool canReach(vector<vector<int>>& heights, int mid) {
    int rows = heights.size();
    int cols = heights[0].size();
    std::queue<pair<int, int>> q;
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    q.push({0, 0});
    visited[0][0] = 1;
    while (!q.empty()) {
      auto curr = q.front();
      q.pop();
      if (curr.first == rows - 1 && curr.second == cols - 1)
        return true;
      for (int k = 0; k < 4; k++) {
        int tx = curr.first + dirs[k];
        int ty = curr.second + dirs[k+1];
        if (tx >= 0 && ty >= 0 && tx < rows && ty < cols && !visited[tx][ty]) {
          int curDiff = std::abs(heights[tx][ty] - heights[curr.first][curr.second]);
          if (curDiff <= mid) {
            visited[tx][ty] = 1;
            q.push({tx, ty});
          }
        }
      }
    }
    return false;
  }
};
