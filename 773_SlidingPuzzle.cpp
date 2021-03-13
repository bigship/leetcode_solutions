// 773. Sliding Puzzle
/*
 * On a 2x3 board, there are 5 tiles represented by the integers 1 through 5,
 * and an empty square represented by 0.

A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given a puzzle board, return the least number of moves required so that the state of the board is solved.
If it is impossible for the state of the board to be solved, return -1.

Examples:

Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.

Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.

Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]

Input: board = [[3,2,4],[1,5,0]]
Output: 14

Note:
    board will be a 2 x 3 array as described above.
    board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].
*/

// Solution: BFS 这里要把整个board当做queue里的元素
class Solution {
public:
  int slidingPuzzle(vector<vector<int>>& board) {
    std::queue<vector<vector<int>>> que;
    que.push(board);
    int ans = -1;

    map<vector<vector<int>>, int> mp;   // mark visited board pattern
    mp[board]++;

    while (!que.empty()) {
      ans++;
      int n = que.size();
      while (n--) {
        vector<vector<int>> cur = que.front();
        que.pop();
        if (isValid(cur)) {
          return ans;
        }
        auto coord = findZero(cur);
        int x = coord.first, y = coord.second;
        for (int k = 0; k < 4; k++) {
          int tx = x + dirs[k];
          int ty = y + dirs[k+1];
          if (tx < 0 || ty < 0 || tx >= 2 || ty >= 3)
            continue;
          std::swap(cur[x][y], cur[tx][ty]);
          if (mp.find(cur) == mp.end()) {
            que.push(cur);
            mp[cur]++;
          }
          std::swap(cur[x][y], cur[tx][ty]);
        }
      }
    }
    return -1;
  }
private:
    vector<int> dirs = {-1, 0, 1, 0, -1};

    std::pair<int, int> findZero(vector<vector<int>> &vec) {
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
          if (vec[i][j] == 0) {
            return {i, j};
          }
        }
      }
      return {-1, -1};
    }

    bool isValid(vector<vector<int>>& mat) {
      return (mat[0][0] == 1 && mat[0][1] == 2 && mat[0][2] == 3 && mat[1][0] == 4 && mat[1][1] == 5
             && mat[1][2] == 0);
    }
};


