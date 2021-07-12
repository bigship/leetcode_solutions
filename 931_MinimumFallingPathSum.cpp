// 931. Minimum Falling Path Sum
/*
 * Given an n x n array of integers matrix,
 * return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row
that is either directly below or diagonally left/right.
Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col),
or (row + 1, col + 1).

Example 1:

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum underlined below:
[[2,1,3],      [[2,1,3],
 [6,5,4],       [6,5,4],
 [7,8,9]]       [7,8,9]]
*/

class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = rows - 2; i >= 0; i--) {
      for (int j = 0; j < cols; j++) {
        if (j == 0) {
          matrix[i][j] = std::min(matrix[i+1][j], matrix[i+1][j+1]) + matrix[i][j];
        } else if (j == cols - 1) {
          matrix[i][j] = std::min(matrix[i+1][j-1], matrix[i+1][j]) + matrix[i][j];
        } else {
          matrix[i][j] = std::min(matrix[i+1][j-1],
                                  std::min(matrix[i+1][j], matrix[i+1][j+1])) + matrix[i][j];
        }
      }
    }

    return *min_element(matrix[0].begin(), matrix[0].end());
  }
};


