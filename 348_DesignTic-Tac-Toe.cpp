// 348. Design Tic-Tac-Toe
/*
 * Assume the following rules are for the tic-tac-toe game on an n x n board between two players:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves are allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
Implement the TicTacToe class:

TicTacToe(int n) Initializes the object the size of the board n.
int move(int row, int col, int player) Indicates that player with id player plays at the cell (row, col) of the board.
The move is guaranteed to be a valid move.

Follow up:
Could you do better than O(n2) per move() operation?

Example 1:

Input
["TicTacToe", "move", "move", "move", "move", "move", "move", "move"]
[[3], [0, 0, 1], [0, 2, 2], [2, 2, 1], [1, 1, 2], [2, 0, 1], [1, 0, 2], [2, 1, 1]]
Output
[null, 0, 0, 0, 0, 0, 0, 1]
*/

// 对角线行列关系
// 正对角线: row == col
// 反对角线: row + col == size - 1

class TicTacToe {
public:
  /** Initialize your data structure here. */
  TicTacToe(int n) {
    rows = vector<int>(n, 0);   // 记录每一行被选中的次数
    cols = vector<int>(n, 0);   // 记录每一列被选中的次数
  }

  /** Player {player} makes a move at ({row}, {col}).
      @param row The row of the board.
      @param col The column of the board.
      @param player The player, can be either 1 or 2.
      @return The current winning condition, can be either:
              0: No one wins.
              1: Player 1 wins.
              2: Player 2 wins. */

  // move is guaranteed to be a valid move
  int move(int row, int col, int player) {
    int thePlayer = player == 1 ? 1 : -1;
    rows[row] += thePlayer;
    cols[col] += thePlayer;
    if (row == col) diag1 += thePlayer;
    if (row == rows.size() - col - 1) diag2 += thePlayer;

    int size = rows.size();
    if (abs(rows[row]) == size ||
     abs(cols[col]) == size ||
     abs(diag1) == size ||
     abs(diag2) == size) {
      return player;
    }
    return 0;
  }
private:
  vector<int> rows;
  vector<int> cols;
  int diag1 = 0;     // 记录对角线1被选中的次数
  int diag2 = 0;     // 记录对角线2被选中的次数
};

