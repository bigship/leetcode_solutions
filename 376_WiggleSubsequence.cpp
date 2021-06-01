// 376. Wiggle Subsequence
/*
 * A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative.
 * The first difference (if one exists) may be either positive or negative.
 * A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences.
The first is not because its first two differences are positive, and the second is not because its last difference is zero.
A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

Given an integer array nums, return the length of the longest wiggle subsequence of nums.

Example 1:

Input: nums = [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).
*/

// 当前状态只和前一步有关, 状态压缩为只需要两个整数即可
// 每个值只可能处于3个状态:
// 1. 上升  nums[i] > nums[i-1]    当前点i是处于上升的, i-1一定是下降, up[i] = down[i-1] + 1
// 2. 下降  nums[i] < nums[i-1]    当前点i是处于下降的, i-1一定是上升, down[i] = up[i-1] + 1
// 3. 不变  nums[i] == nums[i-1]   up[i]和down[i]维持不变
class Solution {
public:
  int wiggleMaxLength(vector<int>& nums) {
    if (nums.size() < 2) return nums.size();
    int up = 1, down = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > nums[i-1]) {
        up = down + 1;
      } else if (nums[i] < nums[i-1]) {
        down = up + 1;
      }
    }
    return std::max(up, down);
  }
};
