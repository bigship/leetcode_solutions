// 840. Magic Squares in Grid
/*
 * A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9
 * such that each row, column, and both diagonals all have the same sum.

Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).

Example 1:

Input: [[4,3,8,4],
        [9,5,1,9],
        [2,7,6,2]]
Output: 1
Explanation:
The following subgrid is a 3 x 3 magic square:
438
951
276

while this one is not:
384
519
762

In total, there is only one magic square inside the given grid.

Note:

    1 <= grid.length <= 10
    1 <= grid[0].length <= 10
    0 <= grid[i][j] <= 15
*/
class Solution {
public:
  int numMagicSquareInside(vector<vector<int>>& grid) {
    set<int> s{1,2,3,4,5,6,7,8,9};
    set<int> a;
    int ans = 0;
    const int rows = grid.size();
    const int cols = grid[0].size();
    for (int x = 0; x < rows - 2; x++) {
      for (int y = 0; y < cols - 2; y++) {
        a.insert(grid[x][y]);
        a.insert(grid[x][y+1]);
        a.insert(grid[x][y+2]);
        a.insert(grid[x+1][y]);
        a.insert(grid[x+1][y+1]);
        a.insert(grid[x+1][y+2]);
        a.insert(grid[x+2][y]);
        a.insert(grid[x+2][y+1]);
        a.insert(grid[x+2][y+2]);
        if (a == s && grid[x][y]+grid[x][y+1]+grid[x][y+2]==15 &&
            grid[x+1][y]+grid[x+1][y+1]+grid[x+1][y+2]==15 &&
            grid[x+2][y]+grid[x+2][y+1]+grid[x+2][y+2]==15 &&
            grid[x][y]+grid[x+1][y]+grid[x+2][y]==15 &&
            grid[x][y+1]+grid[x+1][y+1]+grid[x+2][y+1]==15 &&
            grid[x][y+2]+grid[x+1][y+2]+grid[x+2][y+2]==15 &&
            grid[x][y]+grid[x+1][y+1]+grid[x+2][y+2]==15 &&
            grid[x][y+2]+grid[x+1][y+1]+grid[x+2][y] == 15) {
          ans++;
        }
        a.clear();
      }
    }
    return ans;
  }
};

