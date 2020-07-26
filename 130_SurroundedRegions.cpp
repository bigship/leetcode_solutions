// 130. Surrounded Regions
/*
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'.
Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'.
Two cells are connected if they are adjacent cells connected horizontally or vertically.
*
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return ;
        int row = board.size();
        int col = board[0].size();

        function<void(int, int)> dfs = [&](int x, int y) {
            if (x < 0 || x >= row || y < 0 || y >= col || board[x][y] != 'O')
                return;
            board[x][y] = 'G'; // marked as 'G', and visited
            dfs(x+1, y);
            dfs(x-1, y);
            dfs(x, y-1);
            dfs(x, y+1);
        };

        // 从四条边开始尝试扩展
        for (int i = 0; i < row; ++i)
            dfs(i, 0), dfs(i, col - 1);
        for (int j = 0; j < col; ++j)
            dfs(0, j), dfs(row - 1, j);

        map<char, char> v{{'G', 'O'}, {'O', 'X'}, {'X', 'X'}};
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                board[i][j] = v[board[i][j]];
            }
        }
    }
};


