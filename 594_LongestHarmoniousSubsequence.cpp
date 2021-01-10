// 594. Longest Harmonious Subsequence
/*
 * We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.
A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

Example 1:

Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].

Example 2:

Input: nums = [1,2,3,4]
Output: 2

Example 3:

Input: nums = [1,1,1,1]
Output: 0

Constraints:

    1 <= nums.length <= 2 * 104
    -109 <= nums[i] <= 109
*/
// Solution: 根据harmonious数组的定义, 最大值减去最小值的差刚好为1
// 因此这种子序列中只可能有2种不同的值, 且它们的差刚好为1
// 先统计每个数出现的次数, 加入到hashmap中
// 遍历hashmap, 设当前访问到的元素为key, 如果key + 1也存在 则可以构成的subsequence长度
// 就是map[key] + map[key+1]
// Time: O(n), Space: O(n)

class Solution {
public:
  int findLHS(vector<int>& nums) {
    unordered_map<int, int> mapping;  // key: val in nums, value: the number of times the val appears in nums
    for (auto& v : nums) {
      mapping[v]++;
    }

    int maxlen = 0;
    for (auto it = mapping.begin(); it != mapping.end(); it++) {
      int key = it->first;
      if (mapping.find(key+1) != mapping.end()) {
        maxlen = std::max(maxlen, mapping[key] + mapping[key+1]);
      }
    }

    return maxlen;
  }
};

