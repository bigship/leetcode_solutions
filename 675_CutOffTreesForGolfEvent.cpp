// 675. Cut Off Trees for Golf Event
/*
 * You are asked to cut off trees in a forest for a golf event.
 * The forest is represented as a non-negative 2D map, in this map:

    0 represents the obstacle can't be reached.
    1 represents the ground can be walked through.
    The place with number bigger than 1 represents a tree can be walked through,
    and this positive number represents the tree's height.

In one step you can walk in any of the four directions top, bottom,
left and right also when standing in a point which is a tree you can decide whether or not to cut off the tree.

You are asked to cut off all the trees in this forest in the order of tree's height - always cut off the tree with lowest height first.
And after cutting, the original place has the tree will become a grass (value 1).

You will start from the point (0, 0) and you should output the minimum steps you need to walk to cut off all the trees.
If you can't cut off all the trees, output -1 in that situation.

You are guaranteed that no two trees have the same height and there is at least one tree needs to be cut off.

Example 1:

Input:
[
 [1,2,3],
 [0,0,4],
 [7,6,5]
]
Output: 6

Example 2:

Input:
[
 [1,2,3],
 [0,0,0],
 [7,6,5]
]
Output: -1

Example 3:

Input:
[
 [2,3,4],
 [0,0,5],
 [8,7,6]
]
Output: 6
Explanation: You started from the point (0,0) and you can cut off the tree in (0,0) directly without walking.

Constraints:
    1 <= forest.length <= 50
    1 <= forest[i].length <= 50
    0 <= forest[i][j] <= 10^9
*/
class Solution {
public:
  int cutOffTree(vector<vector<int>>& forest) {
    row = forest.size();
    col = forest[0].size();
    vector<std::tuple<int, int, int>> dest;

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (forest[i][j] > 1) {
          dest.push_back({forest[i][j], i, j});
        }
      }
    }
    std::sort(dest.begin(), dest.end());
    int total_steps = 0;
    int sx = 0, sy = 0;    // starting point
    for (int i = 0; i < dest.size(); i++) {
      int tx = std::get<1>(dest[i]);
      int ty = std::get<2>(dest[i]);
      int steps = BFS(forest, sx, sy, tx, ty);
      if (steps == INT_MAX)
        return -1;           // cannot cut all the trees
      forest[tx][ty] = 1;
      total_steps += steps;
      sx = ty;     // set new starting point
      sy = ty;
    }
    return total_steps;
  }
private:
  int row;
  int col;

  int BFS(vector<vector<int>>& forest, int sx, int sy, int tx, int ty) {
    std::queue<pair<int, int>> q;
    q.emplace(sx, sy);
    vector<vector<int>> used(row, vector<int>(col, 0));

    int steps = 0;
    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        auto coord = q.front();
        q.pop();
        int cx = coord.first;
        int cy = coord.second;
        if (cx == tx && cy == ty)
          return steps;

        for (int k = 0; k < 4; k++) {
          int x = cx + dirs[k];
          int y = cy + dirs[k+1];
          if (x < 0 || y < 0 || x >= row || y >= col ||
              forest[x][y] == 0 || used[x][y] == 1)
            continue;
          used[x][y] = 1;
          q.emplace(x, y);
        }
      }
      steps++;
    }
    return INT_MAX;
  }
};


