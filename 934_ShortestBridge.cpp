// 934. Shortest Bridge
/*
 * In a given 2D binary array grid, there are two islands.
 * (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.
Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1
Example 2:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
Example 3:

Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1

Constraints:

2 <= grid.length == grid[0].length <= 100
grid[i][j] == 0 or grid[i][j] == 1

*/

class Solution {
public:
  int shortestBridge(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    std::queue<vector<int>> que;
    bool foundIsland = false;

    vector<vector<int>> visited(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == 1) {
          dfs(grid, i, j, visited, que);
          foundIsland = true;
          break;
        }
      }
      if (foundIsland) {
        break;
      }
    }

    int ans = 0;
    while (!que.empty()) {
      int n = que.size();
      for (int i = 0; i < n; i++) {
        auto coord = que.front();
        que.pop();

        for (int k = 0; k < 4; k++) {
          int nx = coord[0] + dirs[k];
          int ny = coord[1] + dirs[k+1];
          if (inGrid(nx, ny, rows, cols) && grid[nx][ny] == 1 && visited[nx][ny] == 0) {
            return ans;
          } else if (inGrid(nx, ny, rows, cols) && grid[nx][ny] == 0 && visited[nx][ny] == 0) {
            visited[nx][ny] = 1;
            que.push({nx, ny});
          }
        }
      }
      ans++;
    }

    return -1;
  }
private:
  vector<int> dirs = {-1, 0, 1, 0, -1};

  bool inGrid(int x, int y, int rows, int cols) {
    if (x >= 0 && x < rows && y >= 0 && y < cols) {
      return true;
    }
    return false;
  }

  void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& vis, std::queue<vector<int>>& que) {
    vis[x][y] = 1;
    que.push({x, y});
    for (int k = 0; k < 4; k++) {
      int nx = x + dirs[k];
      int ny = y + dirs[k+1];
      if (inGrid(nx, ny, grid.size(), grid[0].size()) && grid[nx][ny] == 1 && vis[nx][ny] == 0) {
        dfs(grid, nx, ny, vis, que);
      }
    }
    return ;
  }
};



