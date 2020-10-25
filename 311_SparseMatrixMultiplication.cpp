// 311. Sparse Matrix Multiplication
/*
 * Given two sparse matrices A and B, return the result of AB.
   You may assume that A's column number is equal to B's row number.

Example:

Input:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]

Output:

     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |

Constraints:

    1 <= A.length, B.length <= 100
    1 <= A[i].length, B[i].length <= 100
    -100 <= A[i][j], B[i][j] <= 100
*/
class Solution {
public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int arow = A.size(), acol = A[0].size();
    int brow = B.size(), bcol = B[0].size();

    vector<int> azeroRow = vector<int>(arow, 1);
    vector<int> bzeroCol = vector<int>(bcol, 1);

    // 统计出A中全0的行和B中全0的列. 计算乘积时它们的结就是0
    for (int i = 0; i < arow; i++) {
      for (int j = 0; j < acol; j++) {
        if (A[i][j] != 0) {
          azeroRow[i] = 0;
          break;
        }
      }
    }

    for (int j = 0; j < bcol; j++) {
      for (int i = 0; i < brow; i++) {
        if (B[j][i] != 0) {
          bzeroCol[j] = 0;
          break;
        }
      }
    }

    vector<vector<int>> ans = vector<vector<int>>(arow, vector<int>(bcol, 0));
    for (int i = 0; i < arow; i++) {
      for (int j = 0; j < bcol; j++) {
        if (azeroRow[i] || bzeroCol[j])   // 这一行或者这一列全为0, 则不用计算. 结果一定是0
          continue;
        int sum = 0;
        for (int k = 0; k < acol; k++) {
          sum += A[i][k] * B[k][j];
        }
        ans[i][j] = sum;
      }
    }
    return ans;
  }
};

