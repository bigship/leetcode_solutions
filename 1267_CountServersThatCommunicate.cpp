// 1267. Count Servers that Communicate
/*
 * You are given a map of a server center, represented as a m * n integer matrix grid,
 * where 1 means that on that cell there is a server and 0 means that it is no server.
 * Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.

Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.

Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.

Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other.
The two servers in the third column can communicate with each other.
The server at right bottom corner can't communicate with any other server.

Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m <= 250
    1 <= n <= 250
    grid[i][j] == 0 or 1
*/

class Solution {
public:
  // 先把每行每列有1的个数存下来
  // 遍历整个表格, 如果发现了1, 查这一行或者这一列的1的个数, 大于1则表示可以相连
  // 计数统计
  int countServers(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<int> r_cnt(col, 0);
    vector<int> c_cnt(row, 0);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (grid[i][j] == 1) {
          r_cnt[j]++;
          c_cnt[i]++;
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (grid[i][j] == 1 && (r_cnt[j] > 1 || c_cnt[i] > 1))
          ans++;
      }
    }
    return ans;
  }
};

