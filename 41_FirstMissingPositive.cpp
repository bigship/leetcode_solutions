// 41. First Missing Positive
/*
 * Given an unsorted integer array nums, find the smallest missing positive integer.

Follow up: Could you implement an algorithm that runs in O(n) time and uses constant extra space.?

Example 1:

Input: nums = [1,2,0]
Output: 3

Example 2:

Input: nums = [3,4,-1,1]
Output: 2

Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
*/

// Time: O(n), Space: O(n)
class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    std::unordered_set<int> set;
    for (auto& num : nums) {
      if (num > 0) {
        set.insert(num);
      }
    }

    int start = 1;
    while (true) {
      if (set.count(start) == 0)
        return start;
      start++;
    }
    return -1;
  }
};

// Time: O(n), Space: O(1)
class Solution2 {
public:
  int firstMissingPositive(vector<int>& nums) {
    const int n = nums.size();
    int containOne = 0;
    for (auto& num : nums) {
      if (num == 1) {
        containOne++;
        break;
      }
    }
    if (containOne == 0)
      return 1;
    if (n == 1)
      return 2;

    for (auto& num : nums) {
      if (num <= 0 || num > n) {
        num = 1;
      }
    }

    // use index as hash key, and the sign of the num as detector
    for (int i = 0; i < n; i++) {
      int a = std::abs(nums[i]);
      if (a == n) {
        nums[0] = -std::abs(nums[0]);
      } else {
        nums[a] = -std::abs(nums[a]);
      }
    }

    for (int i = 1; i < n; ++i) {
      if (nums[i] > 0)
        return i;
    }

    if (nums[0] > 0)
      return n;

    return n + 1;
  }
};


