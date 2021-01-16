// 1287. Element Appearing More Than 25% In Sorted Array
/*
 * Given an integer array sorted in non-decreasing order,
 * there is exactly one integer in the array that occurs more than 25% of the time.

Return that integer.

Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6

Constraints:
    1 <= arr.length <= 10^4
    0 <= arr[i] <= 10^5
*/

// 由于数组有序, 且要找的值有且只有一个. 那么出现次数超过25%的值只可能出现在原数组中的
// 3个地方. 1/4处, 1/2处以及3/4处.
// 依次对这3个可能的值做二分查找, 找到它们位置的上界和下界
// 如果上下界的距离乘以4大于原数组的长度了, 那么这就是要找的值
// Time : O(log(n)), Space: O(1)
class Solution {
public:
  int findSpecialInteger(vector<int>& arr) {
    const int len = arr.size();
    vector<int> candidates{arr[len / 4], arr[len / 2], arr[len * 3 / 4]};
    for (auto& cand : candidates) {
      auto low = std::lower_bound(arr.begin(), arr.end(), cand);
      auto high = std::upper_bound(arr.begin(), arr.end(), cand);
      if (4 * (distance(low, high)) > len)
        return cand;
    }
    return -1;
  }
};

