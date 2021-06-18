// 918. Maximum Sum Circular Subarray
/*
 * Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array.
Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once.
Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10

*/

// 类似求数组中最大子数组和问题(Kadane's algorithm)
// 这里数组可以是循环的, 那么最大和可以是下列两种情况
//
// [xxxx][max_sum][xxxxxx]                -  对应于普通的Kadane's algorithm
// [left_max_sum][xxxxxx][right_max_sum]  -  即最大子数组和是左右两半子数组的和
// 此时我们可以求中间那段子数组和最小的情况
//
// 因此可以在一次遍历中找出子数组和最大和最小的值, 我们最终的结果就是 max(global_max, sum - global_min)
// 注意, 这里有一个edge case. 就是如果数组中所有数都小于0, 此时sum == global_min, 那么此时只能返回global_max
//

class Solution {
public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int curmax, global_max, curmin, global_min, sum;
    curmax = global_max = curmin = global_min = sum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      sum += nums[i];
      curmax = std::max(nums[i], curmax + nums[i]);
      global_max = std::max(global_max, curmax);
      curmin = std::min(nums[i], curmin + nums[i]);
      global_min = std::min(global_min, curmin);
    }

    if (sum == global_min) {
      return global_max;
    }
    return std::max(global_max, sum - global_min);
  }
};

