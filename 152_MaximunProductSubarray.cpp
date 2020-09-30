// 152. Maximum Product Subarray
/*
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

// 如果负数存在有偶数个, 则乘积最大为全部数相乘
// 如果负数只有奇数个, 则乘积最大的结果只可能是下列两种情况 (不算第一个负数, 以及不算最后一个负数)
// 2, 3, -3, [9, 6, -2, 7, 5, -1, 4]
// [2, 3, -3, 9, 6, -2, 7, 5], -1, 4
// 如果遇到0会使得乘积变为0, 那么只要遇到0, 就让max重新记为1即可
class Solution {
public:
  int maxProduct(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    int ans = nums[0];
    int max = 1;

    // 正向遍历数组, 针对负数出现次数为奇数的情况1
    for (int i = 0; i < nums.size(); i++) {
      max *= nums[i];
      ans = std::max(ans, max);
      if (max == 0) {
        max = 1;  // 遇到0会使得结果乘积变为0, 此时重置max为1就可以再次计算乘积了
      }
    }

    max = 1;
    // 重置max为1, 然后逆向再次遍历数组, 针对负数出现次数为奇数的情况2
    for (int i = nums.size() - 1; i >= 0; i--) {
      max *= nums[i];
      ans = std::max(ans, max);
      if (max == 0) {
        max = 1;
      }
    }

    return ans;
  }
};

