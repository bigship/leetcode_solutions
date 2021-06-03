// 375. Guess Number Higher or Lower II
/*
 * We are playing the Guessing Game. The game will work as follows:

I pick a number between 1 and n.
You guess a number.
If you guess the right number, you win the game.
If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.

*/

class Solution {
public:
  int getMoneyAmount(int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return dfs(dp, 1, n);
  }
private:
  int dfs(vector<vector<int>>& dp, int left, int right) {
    if (left >= right) return 0;
    if (dp[left][right] != -1)
      return dp[left][right];
    int res = INT_MAX;
    for (int i = left; i <= right; i++) {
      int cost = std::max(dfs(dp, left, i - 1), dfs(dp, i+1, right)) + i;
      res = std::min(res, cost);
    }
    dp[left][right] = res;
    return res;
  }
};
