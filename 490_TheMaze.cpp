// 490. The Maze
/*
 * There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1).
 * The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall.
 * When the ball stops, it could choose the next direction.

Given the maze, the ball's start position and the destination,
where start = [startrow, startcol] and destination = [destinationrow, destinationcol],
return true if the ball can stop at the destination, otherwise return false.

You may assume that the borders of the maze are all walls (see examples).

Example 1:

Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.

Example 2:

Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
Output: false
Explanation: There is no way for the ball to stop at the destination.
Notice that you can pass through the destination but you cannot stop there.

Example 3:

Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
Output: false

Constraints:
    1 <= maze.length, maze[i].length <= 100
    maze[i][j] is 0 or 1.
    start.length == 2
    destination.length == 2
    0 <= startrow, destinationrow <= maze.length
    0 <= startcol, destinationcol <= maze[i].length
    Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
    The maze contains at least 2 empty spaces.
*/
class Solution {
public:
  bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    const int rows = maze.size();
    if (rows == 0) return false;
    const int cols = maze[0].size();
    vector<vector<int>> used(rows, vector<int>(cols, 0));
    std::queue<vector<int>> q;
    q.push(start);
    used[start[0]][start[1]] = 1;

    while (!q.empty()) {
      vector<int> cur = q.front();
      q.pop();
      int x = cur[0];
      int y = cur[1];
      if (x == destination[0] && y == destination[1])
        return true;

      for (int k = 0; k < 4; k++) {
        int tx = x + dirs[k];
        int ty = y + dirs[k+1];
        while (tx >= 0 && ty >= 0 && tx < rows && ty < cols && maze[tx][ty] == 0) {
          tx += dirs[k];
          ty += dirs[k+1];
        }
        // 检查该方向上的最后一步是不是已经访问过了, 如果没有访问则添加到队列作为下一个出发点
        // 同时标记该位置为已经访问
        if (!used[tx - dirs[k]][ty - dirs[k+1]]) {
          q.push({tx - dirs[k], ty - dirs[k+1]});
          used[tx - dirs[k]][ty - dirs[k+1]] = 1;
        }
      }
    }
    return false;
  }
private:
  vector<int> dirs = {-1, 0, 1, 0, -1};
};


