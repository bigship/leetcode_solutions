// 209. Minimum Size Subarray Sum
/*
 * Given an array of n positive integers and a positive integer s,
 * find the minimal length of a contiguous subarray of which the sum ≥ s.
 * If there isn't one, return 0 instead.

Example:

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.

Follow up:
If you have figured out the O(n) solution,
try coding another solution of which the time complexity is O(nlogn).
*/

class Solution {
public:
  // Sliding window
  // 累加和, 如果和小于目标值, 继续向右边扩展窗口
  // 如果和满足条件, 更新此时的解. 然后向右移动左窗口使得窗口减小, 以此期望能找到更好的解
  // Time: O(n), Space: O(1)
  int minSubarrayLen(int target, vector<int>& nums) {
    const int len = nums.size();
    if (len == 0) return 0;

    int left = 0;
    int ans = INT_MAX;
    int cursum = 0;

    for (int i = 0; i < len; i++) {
      cursum += nums[i];
      while (cursum >= target) {
        ans = std::min(ans, i - left + 1);
        cursum -= nums[left++];
      }
    }

    return (ans == INT_MAX) ? 0 : ans;
  }
};

