// 487. Max Consecutive Ones II
/*
 * Given a binary array nums, return the maximum number of consecutive 1's in the array if you can flip at most one 0.
 *
Example 1:

Input: nums = [1,0,1,1,0]
Output: 4
Explanation: Flip the first zero will get the maximum number of consecutive 1s.
After flipping, the maximum number of consecutive 1s is 4.

Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 4

Constraints:

1 <= nums.length <= 10^5
nums[i] is either 0 or 1.

*/

// 滑动窗口. 因为可以最多包含一个0(把这个0翻转成1就可以构成连续的1),
// 因此滑动窗口的满足条件就是中间包含0的个数不能超过1. 如果超过了1, 移动left边界直到0的个数小于2

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int ans = 0, left = 0, right = 0, ans = 0, zeroCnt = 0;
    while (right < nums.size()) {
      if (nums[right] == 0) zeroCnt++;
      while (zeroCnt > 1) {
        if (nums[left] == 0)
          zeroCnt--;
        left++;
      }
      ans = max(ans, right - left + 1);
      right++;
    }
    return ans;
  }
};

