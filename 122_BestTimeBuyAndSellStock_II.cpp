// 122. Best Time to Buy and Sell Stock II
/*
 * Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like
(i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.

Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.

Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.



Constraints:

    1 <= prices.length <= 3 * 10 ^ 4
    0 <= prices[i] <= 10 ^ 4
*
*/
class Solution {
public:
    // 把所有正的价格差相累加就是结果
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - prices[i - 1] > 0) {
                ans += prices[i] - prices[i-1];
            }
        }
        return ans;
    }

    // Brute Force. 暴力求解所有可能, 求最大  Time - O(n^n)  会超时
    // 可利用递归. 参数s表示开始购买股票的下标, 从0开始
    // 递归终止条件, s == prices.size()
    int calculate(vector<int>& prices, int s) {
        if (s == prices.size()) {
            return 0;
        }

        int max = 0;
        for (int start = s; start < prices.size(); start++) {
            int maxprofit = 0;
            for (int i = start + 1; i < prices.size(); i++) {
                if (prices[i] - prices[start] > 0) {
                    int profit = calculate(prices, i + 1) + prices[i] - prices[start];
                    if (profit > maxprofit)
                        maxprofit = profit;
                }
            }
            if (max < maxprofit)
                max = maxprofit;
        }
        return max;
    }
};


