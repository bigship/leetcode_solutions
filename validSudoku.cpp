// 36. Valid Sudoku

bool isRow(const vector<vector<char>>& board, int i) {
  int count = 0;
  unordered_set<char> record;
  for (int j = 0; j < 9; j++) {
    if (board[j][i] != '.') {
      ++count;
      record.emplace(board[j][i]);
    }
  }
  return (record.size() == count);
}

bool isCol(const vector<vector<char>>& board, int i){
  int count = 0;
  unordered_set<char> record;
  for (int j = 0; j < 9; j++) {
    if (board[i][j] != '.') {
      ++count;
      record.emplace(board[i][j]);
    }
  }
  return (record.size() == count);
}

bool isSub(const vector<vector<char>>& board, int m, int n){
  int count = 0;
  unordered_set<char> record;
  for (int j = 3*m; j < 3*m + 3; j++) {
    for (int i = 3*n; i < 3*n + 3; i++) {
      if (board[i][j] != '.'){
        ++count;
        record.emplace(board[i][j]);
      }
    }
  }
  return (record.size() == count);
}


bool isValidSudoku(vector<vector<char>>& board) {
  for (int i = 0; i < 9; i++){
    if (!isCol(board, i) || !isRow(board, i) || !isSub(board, i/3, i%3)){
      return false;
    }
  }
       
  return true;
}
