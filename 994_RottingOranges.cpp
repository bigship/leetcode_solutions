// 994. Rotting Oranges
/*
 * In a given grid, each cell can have one of three values:
    the value 0 representing an empty cell;
    the value 1 representing a fresh orange;
    the value 2 representing a rotten orange.

Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange.
If this is impossible, return -1 instead.

Example 1:

Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten,
because rotting only happens 4-directionally.

Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.

Note:

    1 <= grid.length <= 10
    1 <= grid[0].length <= 10
    grid[i][j] is only 0, 1, or 2.
*/

class Solution {
public:
  // Solution: BFS. 先遍历整个grid, 统计fresh的个数, 如果遇到rotted则将
  // rotted的坐标加入到queue中.
  // 依次从queue中取出rotted, 并向4个方向搜索. 如果遇到fresh则将其修改为rotted,
  // 将fresh计数减去1. 同时将新产生的rotted的坐标加入到queue中
  // 每一轮循环结束就增加minutes
  // 全部处理完毕后, 如果还剩余有fresh则表示无法将所有的fresh都变为rotted, 返回-1
  // 否则就返回minutes即为答案
  int orangesRotting(vector<vector<int>>& grid) {
    const int rows = grid.size();
    if (rows == 0) return 0;
    const int cols = grid[0].size();
    std::queue<pair<int, int>> q;
    int fresh = 0;
    int minutes = 0;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == 1) fresh++;
        if (grid[i][j] == 2) q.push({i, j});
      }
    }

    while (!q.empty() && fresh != 0) {
      int qsize = q.size();
      for (int i = 0; i < qsize; i++) {
        auto coord = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
          int tx = coord.first + dirs[k];
          int ty = coord.second + dirs[k+1];
          if (tx < 0 || ty < 0 || tx >= rows || ty >= cols || grid[tx][ty] != 1)
            continue;
          grid[tx][ty] = 2;  // mark as rotted
          q.push({tx, ty});  // put into queue
          fresh--;
        }
      }
      minutes++;
    }

    if (fresh != 0) return -1;
    return minutes;
  }
private:
  vector<int> dirs = {-1, 0, 1, 0, -1};
};


