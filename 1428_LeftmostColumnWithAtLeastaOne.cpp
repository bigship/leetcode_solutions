// 1428. Leftmost Column with at least a one
/*
 * (This problem is an interactive problem.)

A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.
Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it.
If such index doesn't exist, return -1.
You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

    BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col) (0-indexed).
    BinaryMatrix.dimensions() returns a list of 2 elements [rows, cols], which means the matrix is rows * cols.

Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.
Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix mat as input in the following four examples.
You will not have access the binary matrix directly.

Example 1:

Input: mat = [[0,0],[1,1]]
Output: 0

Example 2:

Input: mat = [[0,0],[0,1]]
Output: 1

Example 3:

Input: mat = [[0,0],[0,0]]
Output: -1

Example 4:

Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
Output: 1

Constraints:

    rows == mat.length
    cols == mat[i].length
    1 <= rows, cols <= 100
    mat[i][j] is either 0 or 1.
    mat[i] is sorted in a non-decreasing way.
*/
class Solution {
public:
  // Solution: 针对每一行做二分查找, 更新最左边的1所在的列数
  int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
    vector<int> dimension = binaryMatrix.dimensions();
    int row = dimension[0];
    int col = dimension[1];
    int ans = INT_MAX;
    for (int i = 0; i < row; i++) {
      int ret = binarySearch(binaryMatrix, i, col);
      if (ret == col - 1 && binaryMatrix.get(i, ret) != 1)
        continue;
      ans = std::min(ans, ret);
    }
    if (ans == INT_MAX)
      return -1;
    return ans;
  }

  // Solution: 从右上角开始查找, 如果是0就下移一行, 如果是1则向左继续搜索直到为0为止,
  // 记录下当前最左边的1的列数位置, 然后再次下移一行.
  int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
    vector<int> rc = binaryMatrix.dimensions();
    int row = rc[0], col = rc[1];
    int x = 0, y = col - 1;
    int ans = INT_MAX;
    while (x < row && y >= 0) {
      if (binaryMatrix.get(x, y) == 0) {
        x++;
      } else {
        ans = std::min(ans, y);
        y--;
      }
    }
    if (ans == INT_MAX)
      return -1;
    return ans;
  }
private:
  int binarySearch(BinaryMatrix &binaryMatrix, int row, int col) {
    int low = 0, high = col - 1;
    while (low < high) {
      int mid = (high - low) / 2 + low;
      int ret = binaryMatrix.get(row, mid);
      if (ret == 0)
        low = mid + 1;
      else
        high = mid;
    }
    return low;
  }
};


