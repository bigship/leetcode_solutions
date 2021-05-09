// 256. Paint House
/*
 * There is a row of n houses, where each house can be painted one of three colors: red, blue, or green.
 * The cost of painting each house with a certain color is different.
 * You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by an n x 3 cost matrix costs.

For example, costs[0][0] is the cost of painting house 0 with the color red; costs[1][2] is the cost of painting house 1 with color green, and so on...
Return the minimum cost to paint all houses.

Example 1:

Input: costs = [[17,2,17],[16,16,5],[14,3,19]]
Output: 10
Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue.
Minimum cost: 2 + 5 + 3 = 10.
Example 2:

Input: costs = [[7,6,2]]
Output: 2
*/

// 思路: 动态规划
// 假设倒数第2个房子选择红色, 则最后一间房子需要在蓝色和绿色中选择较小的一种
// 同样道理, 可以逐次累计选择红色, 蓝色以及绿色需要耗费的cost
// 考虑到当前的状态只和前一次的状态相关, 因此可以压缩状态到1维

class Solution {
public:
  Solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  }

  int minCost(vector<vector<int>>& costs) {
    if (costs.empty()) return 0;

    vector<int> prev = costs.back();   // 先取出最后一间房的3种颜色花费

    // 从倒数第二间房开始累加花费
    for (int n = costs.size() - 2; n >= 0; n--) {
      vector<int> cur = costs[n];
      cur[0] += min(prev[1], prev[2]);   // 如果倒数第二间选红色, 则最后一间要在蓝色和绿色中选较小的那个
      cur[1] += min(prev[0], prev[2]);   // 如果倒数第二间选蓝色, 则最后一间在红色和绿色中选较小的那个
      cur[2] += min(prev[0], prev[1]);   // 如果倒数第二间选绿色, 则最后一间在红色和蓝色中选较小的那个
      prev = cur;                        // 更新状态, 下一次迭代时使用
    }

    return min(prev[0], min(prev[1], prev[2]));
  }
};
