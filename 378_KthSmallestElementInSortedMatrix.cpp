// 378. Kth Smallest Element in a Sorted Matrix
/*
 * Given a n x n matrix where each of the rows and columns are sorted in ascending order,
 * find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.

Note:
You may assume k is always valid, 1 ≤ k ≤ n^2.
*/

class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    const int rows = matrix.size();
    const int cols = matrix[0].size();

    auto cmp = [&](State& s1, State& s2) {
      return s1.val >= s2.val;
    };
    std::priority_queue<State, vector<State>, decltype(cmp)> minheap(cmp);
    vector<vector<int>> visited(rows, vector<int>(cols, 0));

    State s{matrix[0][0], 0, 0};
    minheap.push(s);

    int ans = -1;
    while (!minheap.empty()) {
      auto s = minheap.top();
      minheap.pop();
      k--;
      if (k == 0) {
        ans = s.val;
        break;
      }
      int x = s.x;
      int y = s.y;
      if (x + 1 < rows && y + 1 < cols) {
        if (!visited[x][y+1]) {
          minheap.push({matrix[x][y+1], x, y+1});
          visited[x][y+1] = 1;
        }
        if (!visited[x+1][y]) {
          minheap.push({matrix[x+1][y], x+1, y});
          visited[x+1][y] = 1;
        }
      } else if (x == rows - 1) {
        if (y + 1 < cols && !visited[x][y+1]) {
          minheap.push({matrix[x][y+1], x, y+1});
          visited[x][y+1] = 1;
        }
      } else if (y == cols - 1) {
        if (x + 1 < rows && !visited[x+1][y]) {
          minheap.push({matrix[x+1][y], x+1, y});
          visited[x+1][y] = 1;
        }
      }
    }

    return ans;
  }
};



