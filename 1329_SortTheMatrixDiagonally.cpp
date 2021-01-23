// 1329. Sort the Matrix Diagonally
/*
 * A matrix diagonal is a diagonal line of cells starting from some cell in either
 * the topmost row or leftmost column and going in the bottom-right direction until
 * reaching the matrix's end.
 * For example, the matrix diagonal starting from mat[2][0],
 * where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].

Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.
*/

class Solution {
public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    const int rows = mat.size();
    const int cols = mat[0].size();

    for (int x = 0; x < cols; x++) {
      vector<int> d;
      int c = x;
      int r = rows - 1;
      while (r >= 0 && c >= 0) {
        d.push_back(mat[r--][c--]);
      }
      sort(d.rbegin(), d.rend());

      c = x;
      r = rows - 1;
      int idx = 0;
      while (r >= 0 && c >= 0) {
        mat[r--][c--] = d[idx++];
      }
    }

    for (int y = rows - 2; y >= 0; y--) {
      vector<int> d;
      int c = cols - 1;
      int r = y;
      while (r >= 0 && c >= 0) {
        d.push_back(mat[r--][c--]);
      }
      sort(d.rbegin(), d.rend());

      c = cols - 1;
      r = y;
      int idx = 0;
      while (r >= 0 && c >= 0) {
        mat[r--][c--] = d[idx++];
      }
    }
    return mat;
  }
};
