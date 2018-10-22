// 16. 3Sum closest

/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

// Time complexity O(n^2)
// Space complexity O(1)

class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    int d = INT_MAX, ans = 0;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
      int low = i+1, high = nums.size()-1;
      while (low < high) {
        int sum = nums[i] + nums[high] + nums[low];
        if (sum == target)
          return target;

        int diff = abs(sum - target);
        if (diff < d) {
          d = diff;
          ans = sum;
        }

        if (sum > target) high--;
        else ++low;
      }
    }
    return ans;
  }
};

