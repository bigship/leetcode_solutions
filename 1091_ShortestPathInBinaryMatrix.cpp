// 1091. Shortest Path in Binary Matrix
/*
 * In an N by N square grid, each cell is either empty (0) or blocked (1).

A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:

    Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
    C_1 is at location (0, 0) (ie. has value grid[0][0])
    C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
    If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).

Return the length of the shortest such clear path from top-left to bottom-right.
If such a path does not exist, return -1.
*/

class Solution {
  int shortestPathInBinaryMatrix(vector<vector<int>>& grid) {
    const int rows = grid.size();
    const int cols = grid[0].size();
    if (grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1)
      return -1;

    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    std::queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;

    int ans = 0;
    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        auto coord = q.front();
        q.pop();
        int x = coord.first;
        int y = coord.second;
        if (x == rows - 1 && y == cols - 1) {
          return ans + 1;
        }
        for (auto& dir : dirs) {
          int tx = x + dir[0];
          int ty = y + dir[1];
          if (tx >= 0 && tx < rows && ty >= 0 && ty < cols && grid[tx][ty] == 0 && visited[tx][ty] == 0) {
            visited[tx][ty] = 1;
            q.push({tx, ty});
          }
        }
      }
      ans += 1;
    }
    return -1;
  }
};
