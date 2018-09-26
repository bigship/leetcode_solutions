// 79. Word Search

/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

*/

// DFS 

// Worst case: O(m*n*4^l), l = len(word)
// Space complexity: O(m * n + 1)

class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    w = board.size();
    h = board[0].size();
    if (w == 0 || h == 0 || word.size() == 0) return false;

    // iterate every cell
    for (int i = 0; i < w; i++) {
      for (int j = 0; j < h; j++) {
        if (search(board, word, 0, i, j)) return true;
      }
    }
    return false;
  }

private:
  int w;
  int h;

  bool search(vector<vector<char>>& board, string& word, int idx, int i, int j) {
    // if out of bound, or current cell doesn't equal to word[idx], return false
    if (i < 0 || i == w || j < 0 || j == h || word[idx] != board[i][j])
      return false;

    // if idx == word size - 1, means we found the last char of word in board.
    // which also means the word exists in board, just return true 
    if (idx == word.size() - 1) return true;

    // one particular cell can only visit once, so we save cell content,
    // modify it to 0, means we cann't visit it.
    char cur = board[i][j];
    board[i][j] = 0;

    // recursively call search on 4 directions
    bool found = search(board, word, idx+1, i-1, j) || search(board, word, idx+1, i+1, j)
            || search(board, word, idx+1, i, j-1) || search(board, word, idx+1, i, j+1);
    board[i][j] = cur;   // write cell content back, means we can visit it again.
    return found;
  }
};

