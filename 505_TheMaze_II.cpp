// 505. The Maze II
/*
 * There is a ball in a maze with empty spaces and walls.
 * The ball can go through empty spaces by rolling up, down, left or right,
 * but it won't stop rolling until hitting a wall.
 * When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, find the shortest distance for the ball to stop at the destination.
The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included).
If the ball cannot stop at the destination, return -1.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space.
You may assume that the borders of the maze are all walls.
The start and destination coordinates are represented by row and column indexes.


Example 1:

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)

Output: 12

Explanation: One shortest way is : left -> down -> left -> down -> right -> down -> right.
             The total distance is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.

Example 2:

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)

Output: -1

Explanation: There is no way for the ball to stop at the destination.

Note:
    There is only one ball and one destination in the maze.
    Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
    The given maze does not contain border (like the red rectangle in the example pictures),
    but you could assume the border of the maze are all walls.
    The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
*/

class Solution {
public:
  int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    const int row = maze.size();
    const int col = maze[0].size();
    vector<vector<int>> distance(row, vector<int>(col, INT_MAX));  // 距离矩阵 distance[i][j] 表示从起点走到(i,j)的最短距离
    int dirs[] = {-1, 0, 1, 0, -1};
    queue<pair<int, int>> q;
    q.push({start[0], start[1]});
    distance[start[0]][start[1]] = 0;    // 初始化从起点到当前位置(也是起点)的距离是0

    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      int cur = distance[p.first][p.second];  // 从起点走到当前位置的最短距离

      for (int k = 0; k < 4; k++) {
        int steps = 0;
        int x = p.first;
        int y = p.second;

        // 4个方向扩展, 每次可以移动就更新步数
        while (x + dirs[k] >= 0 && y + dirs[k+1] >= 0 &&
            x + dirs[k] < row && y + dirs[k+1] < col && maze[x+dirs[k]][y+dirs[k+1]] == 0) {
          x += dirs[k];
          y += dirs[k+1];
          steps++;
        }
        // 遇到墙了或者走出边界了, 查看步数. 如果有更短的距离就更新
        // 注意, 要加上cur. 之前走的步数不能不算
        if (distance[x][y] > steps + cur) {
          distance[x][y] = steps + cur;
          q.push({x, y});  // 下一个起点加入队列
        }
      }
    }
    if (distance[destination[0][destination[1]]] != INT_MAX)
      return distance[destination[0]][destination[1]];
    return -1;
  }
};




