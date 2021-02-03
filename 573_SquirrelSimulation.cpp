// 573. Squirrel Simulation
/*
 * There's a tree, a squirrel, and several nuts. Positions are represented by the cells in a 2D grid.
 * Your goal is to find the minimal distance for the squirrel to collect all the nuts and put them under the tree one by one.
 * The squirrel can only take at most one nut at one time and can move in four directions - up, down, left and right, to the adjacent cell.
 * The distance is represented by the number of moves.

Example 1:

Input:
Height : 5
Width : 7
Tree position : [2,2]
Squirrel : [4,4]
Nuts : [[3,0], [2,5]]
Output: 12
Explanation:
Note:
    All given positions won't overlap.
    The squirrel can take at most one nut at one time.
    The given positions of nuts have no order.
    Height and width are positive integers. 3 <= height * width <= 10,000.
    The given positions contain at least one nut, only one tree and one squirrel.
*/

class Solution {
public:
  int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
    int total = 0;
    int ans = INT_MAX;
    for (auto& nut : nuts) {
      total += 2 * (getDistance(nut[0], nut[1], tree[0], tree[1]));
    }
    for (auto& nut : nuts) {
      ans = std::min(ans, total - getDistance(tree[0], tree[1], nut[0], nut[1]) +
          getDistance(squirrel[0], squirrel[1], nut[0], nut[1]));
    }
    return ans;
  }
private:
  int getDistance(int x, int y, int m, int n) {
    return abs(x - m) + abs(y - n);
  }
};
