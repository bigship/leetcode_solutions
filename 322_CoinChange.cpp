// 322. Coin Change
/* You are given coins of different denominations and a total amount of money amount.
 * Write a function to compute the fewest number of coins that you need to make up that amount.
 * If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Note:
You may assume that you have an infinite number of each kind of coin.
*/
//                           coins   amount, cnt
/*                          [5,2,1],   11,    0
 *
 *              [2,1], 1, 2      [2,1], 6, 1    [2,1], 11, 0
 *
 *       [1], 1, 2
 *
 *     [], 0, 3
 *
 *
 *
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::sort(coins.rbegin(), coins.rend());
        int ans = INT_MAX;
        coinChange(coins, 0, amount, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }

private:
    // DFS + pruning
    void coinChange(const vector<int>& coins, int s, int amount, int cnt, int& ans) {
        // have a solution, update ans
        if (amount == 0) {
            ans = min(cnt, ans);
            return ;
        }

        // Already at the last coin and no solution. Also return
        if (s == coins.size()) return;

        // Select biggest coin
        const int coin = coins[s];
        for (int k = amount / coin; k >= 0 && cnt + k < ans; k--) {
            coinChange(coins, s+1, amount - k * coin, cnt + k, ans);
        }
    }
};


class Solution_DP {
public:
  // dp[i] 表示凑出面值为i的值最少需要使用的硬币个数
  int coinChange(vector<int>& coins, int amount) {
    int max = amount + 1;   // 表示无法凑出的面值
    vector<int> dp(max, max);
    dp[0] = 0;    // 不使用任何硬币可以凑出面值为0

    for (int i = 1; i <= amount; i++) {
      for (int j = 0; j < coins.size(); j++) {
        if (coins[j] <= i) {
          dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
      }
    }
    return dp[amount] > amount ? -1 : dp[amount];
  }
};

