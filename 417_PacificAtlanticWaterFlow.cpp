// 417. Pacific Atlantic Water Flow
/*
 * Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent,
 * the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.
Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:
    The order of returned grid coordinates does not matter.
    Both m and n are less than 150.

Example:
Given the following 5x5 matrix:
  Pacific ~   ~   ~   ~   ~
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:
[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
*/
// 从边缘开始做BFS(DFS也可以, 用递归即可), 使用两个队列
// 分别统计可以扩展到的格子, 最后比较扩展后的格子, 如果都扩展过了, 表示这个点既可以通往Pacific也可以通往Atlantic
class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty())
      return {};
    const int rows = matrix.size();
    const int cols = matrix[0].size();
    std::queue<vector<int>> pacque;
    std::queue<vector<int>> atlque;
    vector<vector<int>> pacvisited(rows, vector<int>(cols, 0));
    vector<vector<int>> atlvisited(rows, vector<int>(cols, 0));
    vector<vector<int>> ans;

    for (int i = 0; i < rows; i++) {
      pacque.push({i, 0});
      atlque.push({i, cols - 1});
    }
    for (int i = 0; i < cols; i++) {
      pacque.push({0, i});
      atlque.push({rows - 1, i});
    }

    BFS(matrix, rows, cols, pacque, pacvisited);
    BFS(matrix, rows, cols, atlque, atlvisited);

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (pacvisited[i][j] && atlvisited[i][j]) {
          ans.push_back({i, j});
        }
      }
    }

    return ans;
  }
private:
  void BFS(vector<vector<int>>& matrix, int rows, int cols, queue<vector<int>>& q, vector<vector<int>>& visited) {
    vector<int> dirs = {-1, 0, 1, 0, -1};
    while (!q.empty()) {
      auto coord = q.front();
      q.pop();
      visited[coord[0]][coord[1]] = 1;

      for (int k = 0; k < 4; k++) {
        int x = coord[0] + dirs[k];
        int y = coord[1] + dirs[k + 1];
        if (x >= 0 && x < rows && y >= 0 && y < cols && matrix[x][y] >= matrix[coord[0]][coord[1]] && visited[x][y] == 0) {
          q.push({x, y});
        }
      }
    }
    return ;
  }
};

