// 73. Set Matrix Zeros
/*
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0.
 * Do it in-place.

Example 1:

Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

Example 2:

Input:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

Follow up:

    A straight forward solution using O(mn) space is probably a bad idea.
    A simple improvement uses O(m + n) space, but still not the best solution.
    Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeros(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<pair<int, int>> m;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    m.push_back({i, j});
                }
            }
        }

        for (auto& v : m) {
            for (int i = 0; i < col; i++)
                matrix[v.first][i] = 0;

            for (int j = 0; j < row; j++)
                matrix[j][v.second] = 0;
        }

        return ;
    }
};


