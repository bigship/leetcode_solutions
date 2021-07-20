// 213. House Robber II
/*
 * You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed. All houses at this place are arranged in a circle.
 * That means the first house is the neighbor of the last one.
 * Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
*/

// 由于头尾相连不能同时抢, 因此转化为抢第1到第n-1间的总收益和抢第2到第n间的总收益取最大的那个
class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return std::max(nums[0], nums[1]);

    vector<int> n1(nums.size() - 1, 0);
    vector<int> n2(nums.size() - 1, 0);
    for (int i = 0, j = 1; i < nums.size() - 1 && j < nums.size(); i++, j++) {
      n1[i] = nums[i];
      n2[j-1] = nums[j];
    }

    vector<int> dp1(n1.size(), 0);
    dp1[0] = n1[0];
    dp1[1] = std::max(n1[0], n1[1]);

    vector<int> dp2(n2.size(), 0);
    dp2[0] = n2[0];
    dp2[1] = std::max(n2[0], n2[1]);

    for (int i = 2; i < n1.size(); i++) {
      dp1[i] = std::max(dp1[i-1], dp1[i-2] + n1[i]);
      dp2[i] = std::max(dp2[i-1], dp2[i-2] + n2[i]);
    }

    return std::max(dp1.back(), dp2.back());
  }
};

