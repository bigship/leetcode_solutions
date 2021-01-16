// 523. Continuous Subarray Sum
/*
 * Given a list of non-negative numbers and a target integer k,
 * write a function to check if the array has a continuous subarray of size at least 2 that sums up to a multiple of k,
 * that is, sums up to n*k where n is also an integer.

Example 1:

Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.

Example 2:

Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.

Constraints:

    The length of the array won't exceed 10,000.
    You may assume the sum of all the numbers is in the range of a signed 32-bit integer.
*/

class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    if (nums.size() == 1) return false;
    bool ans = false;
    checkSubarraySum(nums, 0, nums.size() - 1, k, ans);
    return ans;
  }
private:
  void checkSubarraySum(vector<int>& nums, int start, int end, int k, bool& ans) {
    if (start >= end) return ;
    int left = start, right = start;
    int cursum = 0;
    while (right <= end) {
      cursum += nums[right];
      if (right - left + 1 >= 2) {
        if (k == 0 && cursum == 0) {
          ans = true;
          return;
        } else if (k != 0 && cursum % k == 0) {
          ans = true;
          return ;
        }
      }
      right++;
    }

    right--;
    while (left <= end) {
      cursum -= nums[left++];
      if (right - left + 1 >= 2) {
        if (k == 0 && cursum == 0) {
          ans = true;
          return ;
        } else if (k != 0 && cursum % k == 0) {
          ans = true;
          return ;
        }
      }
    }
    checkSubarraySum(nums, start + 1, end - 1, k, ans);
  }
};


