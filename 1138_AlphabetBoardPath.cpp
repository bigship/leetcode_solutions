// 1138. Alphabet Board Path
/*
 * On an alphabet board, we start at position (0, 0), corresponding to character board[0][0].
   Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], as shown in the diagram below.

   We may make the following moves:

    'U' moves our position up one row, if the position exists on the board;
    'D' moves our position down one row, if the position exists on the board;
    'L' moves our position left one column, if the position exists on the board;
    'R' moves our position right one column, if the position exists on the board;
    '!' adds the character board[r][c] at our current position (r, c) to the answer.

(Here, the only positions that exist on the board are positions with letters on them.)
Return a sequence of moves that makes our answer equal to target in the minimum number of moves.
You may return any path that does so.

Example 1:

Input: target = "leet"
Output: "DDR!UURRR!!DDD!"

Example 2:

Input: target = "code"
Output: "RR!DDRR!UUL!R!"

Constraints:
    1 <= target.length <= 100
    target consists only of English lowercase letters.
*/
class Solution {
public:
  string alphabetBoardPath(string target) {
    string ans = "";
    boardPath({0, 0}, ans, target);
    return ans;
  }

private:
  unordered_map<char, pair<int, int>> map = {
    {'a' , {0, 0}}, {'b', {0, 1}}, {'c', {0, 2}}, {'d', {0, 3}}, {'e', {0, 4}},
    {'f' , {1, 0}}, {'g', {1, 1}}, {'h', {1, 2}}, {'i', {1, 3}}, {'j', {1, 4}},
    {'k' , {2, 0}}, {'l', {2, 1}}, {'m', {2, 2}}, {'n', {2, 3}}, {'o', {2, 4}},
    {'p' , {3, 0}}, {'q', {3, 1}}, {'r', {3, 2}}, {'s', {3, 3}}, {'t', {3, 4}},
    {'u' , {4, 0}}, {'v', {4, 1}}, {'w', {4, 2}}, {'x', {4, 3}}, {'y', {4, 4}},
    {'z', {5, 0}}
  };

  // 由于Z的右边没有合法的空位, 因此如果要从右上往左下走时优先选择往左, 再往下
  // 避免出现一直向下而进入非法的位置
  // 同理, 如果要从右下往左上方前进, 则优先考虑往上走, 再向右
  void boardPath(pair<int, int> start, string& path, string& target) {
    for (int i = 0; i < target.length(); i++) {
      std::pair<int, int> end = map[target[i]];
      // second control left or right, first control up or down
      if (end.first > start.first && end.second > start.second) {
        for (int i = 0; i < end.first - start.first; i++) {
            path += "D";
        }
        for (int j = 0; j < end.second - start.second; j++) {
            path += "R";
        }
      } else if (end.first > start.first && end.second == start.second) {
        for (int i = 0; i < end.first - start.first; i++) {
            path += "D";
        }
      } else if (end.first > start.first && end.second < start.second) {
        for (int j = 0; j < start.second - end.second; j++) {
            path += "L";
        }
        for (int i = 0; i < end.first - start.first; i++) {
            path += "D";
        }
      } else if (end.first < start.first && end.second < start.second) {
        for (int i = 0; i < start.first - end.first; i++) {
            path += "U";
        }
        for (int j = 0; j < start.second - end.second; j++) {
            path += "L";
        }
      } else if (end.first < start.first && end.second  == start.second) {
        for (int i = 0; i < start.first - end.first; i++) {
            path += "U";
        }
      } else if (end.first < start.first && end.second > start.second) {
        for (int i = 0; i < start.first - end.first; i++) {
            path += "U";
        }
        for (int j = 0; j < end.second - start.second; j++) {
            path += "R";
        }
      } else if (end.first == start.first && end.second > start.second) {
        for (int j = 0; j < end.second - start.second; j++) {
            path += "R";
        }
      } else if (end.first == start.first && end.second < start.second) {
        for (int j = 0; j < start.second - end.second; j++) {
            path += "L";
        }
      }
      path += "!";
      start.first = end.first;
      start.second = end.second;
    }
  }
};

