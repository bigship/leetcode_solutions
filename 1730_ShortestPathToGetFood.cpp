// 1730. Shortest Path to Get Food
/*
 * You are starving and you want to eat food as quickly as possible.
 * You want to find the shortest path to arrive at any food cell.

You are given an m x n character matrix, grid, of these different types of cells:

'*' is your location. There is exactly one '*' cell.
'#' is a food cell. There may be multiple food cells.
'O' is free space, and you can travel through these cells.
'X' is an obstacle, and you cannot travel through these cells.
You can travel to any adjacent cell north, east, south, or west of your current location if there is not an obstacle.

Return the length of the shortest path for you to reach any food cell. If there is no path for you to reach food, return -1.
*/

// 典型的BFS
//
class Solution {
public:
  int getFood(vector<vector<char>>& grid) {
    vector<int> dirs = {-1, 0, 1, 0, -1};
    pair<int, int> start;
    queue<pair<int, int>> q;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '*') {
          start = {i, j};
          break;
        }
      }
    }

    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
    int shortest = 0;
    q.push(start);
    visited[start.first][start.second] = 1;

    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        auto coord = q.front();
        q.pop();
        int x = coord.first;
        int y = coord.second;
        if (grid[x][y] == '#') {
          return shortest;
        }
        for (int k = 0; k < 4; k++) {
          int tx = x + dirs[k];
          int ty = y + dirs[k + 1];
          if (tx >= 0 && ty >= 0 && tx < grid.size() && ty < grid[0].size() &&
             grid[tx][ty] != 'X' && visited[tx][ty] == 0) {
            q.push({tx, ty});
            //cout << "push " << tx << ", " << ty << endl;
            visited[tx][ty] = 1;
          }
        }
      }
      shortest += 1;
    }
    return -1;
  }
};
