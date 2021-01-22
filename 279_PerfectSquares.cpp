// 279. Perfect Squares
/*
 * Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words,
it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

Constraints:
    1 <= n <= 10^4
*/
// DFS, recursion + memo
class Solution {
public:
  int numSquares(int n) {
    unordered_map<int, int> memo;
    return helper(n, memo);
  }
private:
  int helper(int n, unordered_map<int, int>& memo) {
    if (memo.count(n) != 0)
      return memo[n];
    if (n == 0)
      return 0;

    int cnt = INT_MAX;
    for (int i = 1; i * i <= n; i++) {
      cnt = std::min(cnt, helper(n - i * i, memo) + 1);
    }
    return memo[n] = cnt;
  }
};


