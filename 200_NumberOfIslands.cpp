// 200. Number of Islands
/*
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
 * You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1') {
                    ans += 1;
                    dfs(i, j, r, c, grid);
                }
            }
        }
        return ans;
    }
private:
    void dfs(int x, int y, int m, int n, vector<vector<char>>& grid) {
        // hit the boundary, or meet '0', return.
        // DFS
        if (x < 0 || y < 0 || x >=m || y >= n || grid[x][y] == '0') {
            return ;
        }
        grid[x][y] = '0';
        dfs(x+1, y, m, n, grid);
        dfs(x-1, y, m, n, grid);
        dfs(x, y+1, m, n, grid);
        dfs(x, y-1, m, n, grid);
    }
};


