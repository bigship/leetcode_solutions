// 529. MineSweeper

/*
Let's play the minesweeper game (Wikipedia, online game)!

You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.

Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:

    If a mine ('M') is revealed, then the game is over - change it to 'X'.
    If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
    If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
    Return the board when no more squares will be revealed.

Note:
    The range of the input matrix's height and width is [1,50].
    The click position will only be an unrevealed square ('M' or 'E'), which also means the input board contains at least one clickable square.
    The input board won't be a stage when game is over (some mines have been revealed).
    For simplicity, not mentioned rules should be ignored in this problem. For example, you don't need to reveal all the unrevealed mines when the game is over, consider any cases that you will win the game or flag any squares.
*/

class Solution {
public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    int i = click.front(), j = click.back();
    deque<pair<int, int>> eTobeRevealed;

    if (board[i][j] == 'M') {
      board[i][j] = 'X';
      return board;
    } else if (board[i][j] == 'E') {
      eTobeRevealed.push_back({i, j});
      while (!eTobeRevealed.empty()) {
        auto reveal = eTobeRevealed.front();
        int tc = reveal.first;
        int tr = reveal.second;
        eTobeRevealed.pop_front();
        if (board[tc][tr] == 'B')
          continue;
        board[tc][tr] = 'B';

        // number of 'M' around
        int numberOfUnrevealedM = 0;
        vector<pair<int, int>> toBePush;
        for (int pc = -1; pc <= 1; pc++) {
          for (int pr = -1; pr <= 1; pr++) {
            if (tc+pc >= 0 && tc+pc < board.size() && tr+pr >= 0 && tr+pr < board[0].size()) {
              if (board[tc+pc][tr+pr] == 'E')
                toBePush.push_back({tc+pc, tr+pr});
              if (board[tc+pc][tr+pr] == 'M') {
                numberOfUnrevealedM++;
              }
            }
          }
        }

        if (numberOfUnrevealedM)
          board[tc][tr] = '0' + numberOfUnrevealedM;
        else
          eTobeRevealed.insert(eTobeRevealed.end(), toBePush.begin(), toBePush.end());
      }
    }
    return board;
  }

  // Add recursion solution
  vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    const int row = board.size();
    const int col = board[0].size();
    update(click[0], click[1], row, col, board);
    return board;
  }
private:
  vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
  void update(int x, int y, int row, int col, vector<vector<int>>& board) {
    if (board[x][y] == 'M' || board[x][y] == 'X') {
      board[x][y] = 'X';
      return ;
    }
    int minecnt = 0;
    for (auto& dir : dirs) {
      int tx = dir.first;
      int ty = dir.second;
      if (tx >= 0 && ty >= 0 && tx < row && ty < col) {
        if (board[tx][ty] == 'M') minecnt++;
      }
    }
    if (minecnt > 0) {
      board[x][y] = minecnt + '0';
      return ;
    } else {
      board[x][y] = 'B';
      for (auto& dir : dirs) {
        int tx = dir.first;
        int ty = dir.second;
        if (tx >= 0 && ty >= 0 && tx < row && ty < col) {
          if (board[tx][ty] == 'E')
            update(tx, ty, row, col, board);
        }
      }
    }
  }
};