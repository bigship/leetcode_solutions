// 750. Number Of Corner Rectangles
/*
 * Given a grid where each entry is only 0 or 1, find the number of corner rectangles.
A corner rectangle is 4 distinct 1s on the grid that form an axis-aligned rectangle.
Note that only the corners need to have the value 1. Also, all four 1s used must be distinct.

Example 1:

Input: grid =
[[1, 0, 0, 1, 0],
 [0, 0, 1, 0, 1],
 [0, 0, 0, 1, 0],
 [1, 0, 1, 0, 1]]
Output: 1
Explanation: There is only one corner rectangle, with corners grid[1][2], grid[1][4], grid[3][2], grid[3][4].

Example 2:

Input: grid =
[[1, 1, 1],
 [1, 1, 1],
 [1, 1, 1]]
Output: 9
Explanation: There are four 2x2 rectangles, four 2x3 and 3x2 rectangles, and one 3x3 rectangle.

Example 3:

Input: grid =
[[1, 1, 1, 1]]
Output: 0
Explanation: Rectangles must have four distinct corners.

Note:
    The number of rows and columns of grid will each be in the range [1, 200].
    Each grid[i][j] will be either 0 or 1.
    The number of 1s in the grid will be at most 6000.
*/

// 计算每一行中出现两个1的位置对, 用hashmap保存下来
// 当处理下一行时如果出现同样位置上的两个1, 则表示可以构建一个4角全为1的矩形
class Solution {
public:
  int countCornerRectangles(vector<vector<int>>& grid) {
    unordered_map<int, int> cntmap;
    int ans = 0;
    for (auto& row : grid) {
      for (int c1 = 0; c1 < row.size(); ++c1) {
        if (row[c1] == 1) {
          for (int c2 = c1 + 1; c2 < row.size(); ++c2) {
            if (row[c2] == 1) {
              int pos = c1 * 200 + c2;
              if (cntmap.count(pos) == 0)
                cntmap[pos] = 0;
              int c = cntmap[pos];
              ans += c;
              cntmap[pos] = c + 1;
            }
          }
        }
      }
    }
    return ans;
  }
};
