// 51. N-Queens
/*
 * The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
   Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement,
where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/

class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<vector<int>> res;
    vector<int> cur;
    dfs(n, 0, cur, res);
    generateBoard(res, ans, n);
    return ans;
  }
private:
  unordered_set<int> cols;
  unordered_set<int> diag1;
  unordered_set<int> diag2;

  void generateBoard(vector<vector<int>>& res, vector<vector<string>>& ans, int n) {
    for (int i = 0; i < res.size(); i++) {
      vector<string> board;
      for (int j = 0; j < res[i].size(); j++) {
        string line = string(n, '.');
        line[res[i][j]] = 'Q';
        board.push_back(line);
      }
      ans.push_back(board);
    }
  }

  void dfs(int n, int row, vector<int> cur, vector<vector<int>>& res) {
    if (row >= n) {
      res.push_back(cur);
      return ;
    }

    for (int col = 0; col < n; col++) {
      if (cols.count(col) != 0 || diag1.count(row + col) != 0 || diag2.count(row - col) != 0)
        continue;

      cols.insert(col);
      diag1.insert(row + col);
      diag2.insert(row - col);
      cur.push_back(col);

      dfs(n, row + 1, cur, res);

      cur.pop_back();
      cols.erase(col);
      diag1.erase(row + col);
      diag2.erase(row - col);
    }
  }
};
