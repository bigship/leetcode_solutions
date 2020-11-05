// 286. Walls and Gates
/*
 * You are given a m x n 2D grid initialized with these three possible values.

    -1 - A wall or an obstacle.
    0 - A gate.
    INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to
    represent INF as you may assume that the distance to a gate is less than 2147483647.

Fill each empty room with the distance to its nearest gate.
If it is impossible to reach a gate, it should be filled with INF.

Example:

Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF

After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
*/

class Solution {
public:
  const int inf = 2147483647;
  const int row = rooms.size();
  if (row == 0) return ;
  const int col = rooms[0].size();
  std::queue<pair<int, int>> q;
  vector<int> dirs = {-1, 0, 1, 0, -1};

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (rooms[i][j] == 0)
        q.push({i, j});
    }
  }

  while (!q.empty()) {
    int n = q.size();
    for (int i = 0; i < n; i++) {
      auto gate = q.front();
      q.pop();
      int x = gate.first;
      int y = gate.second;
      for (int k = 0; k < 4; k++) {
        int tx = x + dirs[k];
        int ty = y + dirs[k+1];
        if (tx >= 0 && ty >= 0 && tx < row && ty < col && rooms[tx][ty] == inf) {
          rooms[tx][ty] = rooms[x][y] + 1;
          q.push({tx, ty});
        }
      }
    }
  }
};


