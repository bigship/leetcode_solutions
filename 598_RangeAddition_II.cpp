// 598. Range Addition II
/*
 * You are given an m x n matrix M initialized with all 0's and an array of operations ops,
 * where ops[i] = [ai, bi] means M[x][y] should be incremented by one for all 0 <= x < ai and 0 <= y < bi.

Count and return the number of maximum integers in the matrix after performing all the operations.
*/

class Solution {
public:
  // 不需要具体去做递增的操作. 由于每个ops表示的是某个矩形区域的右下角坐标,
  // 因此能够被重复递增的cell都在矩形的左上角. 能够被重复递增次数最多的格子就是最后的最大值.
  // 只需要遍历一次ops, 找到最小的
  // row与col即可.它们就是被重复递增次数最多的区域. 答案就是rows_min * col_min
  int maxCount(int m, int n, vector<vector<int>>& ops) {
    int minRow = m, minCol = n;
    for (int i = 0; i < ops.size(); i++) {
      minRow = std::min(minRow, ops[i][0]);
      minCol = std::min(minCol, ops[i][1]);
    }
    return minRow * minCol;
  }
};
