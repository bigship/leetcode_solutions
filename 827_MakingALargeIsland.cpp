// 827. Making a Large Island
/*
 * You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
Return the size of the largest island in grid after applying this operation.
An island is a 4-directionally connected group of 1s.

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.
*/

class Solution {
public:
  int largestIsland(vector<vector<int>>& grid) {
    color_ = 1;
    g_ = &grid;
    m_ = grid.size();
    n_ = grid[0].size();
    unordered_map<int, int> areas; // color -> area  跟每个连通分量设一个idx, 连通分量就是指上下左右可以连通到的1
    int ans = 0;
    for (int i = 0; i < m_; ++i) {
      for (int j = 0; j < n_; ++j) {
        if (grid[i][j] == 1) {
          ++color_;
          areas[color_] = getArea(j, i);
          ans = max(ans, areas[color_]);    // 这里也要统计一次, 因为可能没有0, 那么后面的逻辑走不到
        }
      }
    }

    // 连通分量已经标记完毕, 现在只要找0, 并检查它上下左右的连通分量的id, 如果id不同就表示可以合并
    for (int i = 0; i < m_; ++i) {
      for (int j = 0; j < n_; ++j) {
        if (grid[i][j] == 0) {
          int area = 1;
          for (int color : set<int>{getColor(j, i - 1), getColor(j, i + 1),
                                    getColor(j - 1, i), getColor(j + 1, i)})
            area += areas[color];
          ans = max(ans, area);
        }
      }
    }
    return ans;
  }
private:
  int m_;
  int n_;
  int color_;
  vector<vector<int>>* g_; // does not own the object. 避免拷贝整个矩阵

  int getColor(int x, int y) {
    return (x < 0 || x >= n_ || y < 0 || y >= m_) ? 0 : (*g_)[y][x];
  }

  // Return the area of a connected component, set all elements to color_.
  int getArea(int x, int y) {
    if (x < 0 || x >= n_ || y < 0 || y >= m_ || (*g_)[y][x] != 1) return 0;
    (*g_)[y][x] = color_;  // mark as visited
    return 1 + getArea(x - 1, y) + getArea(x + 1, y)
             + getArea(x, y - 1) + getArea(x, y + 1);
  }
};

