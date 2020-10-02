// 532. K-diff Pairs in an Array
/*
 * Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

    0 <= i, j < nums.length
    i != j
    a <= b
    b - a == k

Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.

Example 2:

Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).

Example 3:

Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).

Example 4:

Input: nums = [1,2,4,4,3,3,0,9,2,3], k = 3
Output: 2

Example 5:

Input: nums = [-1,-2,-3], k = 1
Output: 2

Constraints:

    1 <= nums.length <= 10^4
    -107 <= nums[i] <= 10^7
    0 <= k <= 10^7
*/

class Solution {
public:
  // Time: O(n), Space: O(n)
  int findPairs(vector<int>& nums, int k) {
    int ans = 0;
    if (nums.size() == 0) return ans;

    unordered_map<int, int> map;
    unordered_map<int, int> used;  // 用来去重
    for (auto& n : nums)
      map[n]++;

    // 特别针对k=0时的情况, 此时只要遍历一次map找出出现频次大于2的数
    if (k == 0) {
      int cnt = 0;
      for (auto& item : map) {
        if (item.second >= 2)
          cnt++;
      }
      return cnt;
    }

    // 其他k的情况
    for (int i = 0; i < nums.size(); i++) {
      if (map.count(nums[i] + k) != 0 && used.count(nums[i]) == 0) {
        ans++;
        used[nums[i]]++;
      }
    }
    return ans;
  }
};




