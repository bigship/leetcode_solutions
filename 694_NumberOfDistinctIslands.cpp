// 694. Number of Distinct Islands
/*
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land)
 * connected 4-directionally (horizontal or vertical.)
 * You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands.
An island is considered to be the same as another if and only if one island
can be translated (and not rotated or reflected) to equal the other.

Example 1:

11000
11000
00011
00011

Given the above grid map, return 1.

Example 2:

11011
10000
00001
11011

Given the above grid map, return 3.

Notice that:

11
1

and

 1
11

are considered different island shapes, because we do not consider reflection / rotation.
Note: The length of each dimension in the given grid does not exceed 50.
*/

class Solution {
public:
  // 如果形状相同, 那么以同样的遍历方式(dfs)访问每个节点, 这个路径就是相同的
  // 遇到求结构相同(二叉树), 或者形状/路径相同的问题, 考虑序列化的方案
  // 序列化的结果可以唯一标识这种结构/形状/路径
  int numDistinctIslands(vector<vector<int>>& grid) {
    const int row = grid.size();
    const int col = grid[0].size();
    visited = vector<vector<int>>(row, vector<int>(col, 0));

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        string shape = "";
        expand(i, j, 0, shape, grid);
        if (!shape.empty())
          shapes.insert(shape);
      }
    }
    return shapes.size();
  }
private:
  vector<vector<int>> visited;
  std::set<string> shapes;

  void expand(int x, int y, int di, string& shape, vector<vector<int>>& grid) {
    if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() &&
        grid[x][y] == 1 && !visited[x][y]) {
      visited[x][y] = 1;
      shape = shape + to_string(di);
      expand(x+1, y, 1, shape, grid);
      expand(x-1, y, 2, shape, grid);
      expand(x, y+1, 3, shape, grid);
      expand(x, y-1, 4, shape, grid);
      shape = shape + '0';
    }
  }
};



