// 15. 3Sum

/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int partial_sum, partial_target, i, left, right;
    vector<vector<int>> ret;

    if (nums.size() <= 2) 
      return ret;

    for (i = 0; i < nums.size() - 2; i++) {
      if (i >= 1 && nums[i-1] == nums[i])
        continue;
      partial_target = 0 - nums[i];
      left = i + 1;
      right = nums.size() - 1;
      while (left < right) {
        partial_sum = nums[left] + nums[right];
        if (partial_sum == partial_target) {
          ret.push_back({nums[i], nums[left], nums[right]});
          while (left < right && nums[left] == nums[left + 1]) 
            left++;
          while (left < right && nums[right] == nums[right - 1])
            right--;
          left++;
          right--;
        } else if (partial_sum > partial_target) {
          left++;
        } else {
          right--;
        }
      }
    }
    return ret;
  }
}