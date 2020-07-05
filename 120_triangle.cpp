// 120. Triangle
/*
 * Given a triangle, find the minimum path sum from top to bottom.
 * Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space,
where n is the total number of rows in the triangle.
*/

// DP bottom up
#include <vector>

int minimumTotal_BottomUp(vector<vector<int>>& triangle) {
    int row = triangle.size();
    for (int i = row - 2; i >= 0; i--) {
        for (int j = 0; j < i + 1; j++) {
            triangle[i][j] += std::min(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }
    return triangle[0][0];
}

// DP top down
int minimumTotal_TopDown(vector<vector<int>>& triangle) {
    int row = triangle.size();
    if (row == 0) return 0;
    if (row == 1) return triangle[0][0];
    for (int i = 1; i < row; i++) {
        int column = triangle[i].size();
        for (int j = 0; j < column; j++) {
            if (j == 0) triangle[i][j] += triangle[i-1][j];
            else if (j == column - 1) triangle[i][j] += triangle[i-1][j-1];
            else {
                triangle[i][j] += std::min(triangle[i-1][j], triangle[i-1][j+1]);
            }
        }
    }
    return *(std::min_element(triangle[row-1].begin(), triangle[row-1].end()));
}


