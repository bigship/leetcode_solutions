// 1102. Path With Maximum Minimum Value
/*
 * Given a matrix of integers A with R rows and C columns,
 * find the maximum score of a path starting at [0,0] and ending at [R-1,C-1].

The score of a path is the minimum value in that path.
For example, the value of the path 8 →  4 →  5 →  9 is 4.

A path moves some number of times from one visited cell to any
neighbouring unvisited cell in one of the 4 cardinal directions (north, east, west, south).

Example 1:

Input: [[5,4,5],[1,2,6],[7,4,6]]
Output: 4
Explanation:
The path with the maximum score is highlighted in yellow.

Example 2:

Input: [[2,2,1,2,2,2],[1,2,2,2,1,2]]
Output: 2

Example 3:

Input: [[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
Output: 3

Note:
    1 <= R, C <= 100
    0 <= A[i][j] <= 10^9
*/
class Solution {
public:
  // 使用大顶堆来保存下一个要访问的节点
  int maximumMinimumPath(vector<vector<int>> &A) {
    const int row = A.size();
    const int col = A[0].size();
    int min = std::min(A[0][0], A[row-1][col-1]);   // path must include start and end point

    auto cmp = [&](Unit x1, Unit x2) {
      return x1.value < x2.value;
    };
    std::priority_queue<Unit, std::vector<Unit>, decltype(cmp)> maxq(cmp);
    vector<vector<int>> visited = vector<vector<int>>(row, vector<int>(col, 0));
    int x = 0, y = 0;
    while (x != row - 1 || y != col - 1) {
      visited[x][y] = 1;
      int cur = A[x][y];
      for (int k = 0; k < 4; k++) {
        int tx = x + dirs[k];
        int ty = y + dirs[k+1];
        if (tx >= 0 && tx < row && ty >= 0 && ty < col && visited[tx][ty] == 0) {
          if (tx == row - 1 && ty == col - 1) {
            return min;
          }
          visited[tx][ty] = 1;
          maxq.push({A[tx][ty], tx, ty});  // 将扩展的节点加入到大顶堆
        }
      }

      Unit next = maxq.top();  // 堆顶就是当前可以访问到的最大值节点
      maxq.pop();
      if (next.value < min)    // 在访问的过程中更新节点最小值
        min = next.value;
      x = next.row;            // 得到下一个节点的位置坐标
      y = next.col;
    }
    return min;
  }
private:
  struct Unit {
    int value;   // 当前节点的值, 大顶堆保存, 堆顶就是目前值最大的节点
    int row;
    int col;
  };

  vector<int> dirs = {-1, 0, 1, 0, -1};
};



