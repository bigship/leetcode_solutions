// 581. Shortest Unsorted Continuous Subarray
/*
 * Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order,
 * then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0
*/

// 先找到错位的最大值和最小值
// 再找到错位的最大值和最小值排序后的位置
// 答案就是最大错位值的下标减去最小错位值的下标再加1
class Solution {
public:
  int findUnsortedSubarray(vector<int>& nums) {
    if (nums.size() == 1)
      return 0;
    vector<int> res = subarraySort(nums);
    if (res[0] == -1 && res[1] == -1)
      return 0;
    return res[1] - res[0] + 1;
  }

  bool outOfOrder(int idx, int num, vector<int>& array) {
    if (idx == 0) {
      return num > array[idx + 1];
    }
    if (idx == array.size() - 1) {
      return num < array[idx - 1];
    }
    return num < array[idx - 1] || num > array[idx + 1];
  }

  vector<int> subarraySort(vector<int> array) {
    int minOutOfOrder = INT_MAX;
    int maxOutOfOrder = INT_MIN;
    for (int i = 0; i < array.size(); i++) {
      int num = array[i];
      if (outOfOrder(i, num, array)) {
        minOutOfOrder = std::min(minOutOfOrder, num);
        maxOutOfOrder = std::max(maxOutOfOrder, num);
      }
    }

    if (minOutOfOrder == INT_MAX || maxOutOfOrder == INT_MIN)
      return vector<int>{-1, -1};

    int startIdx = 0, endIdx = array.size() - 1;
    while (minOutOfOrder >= array[startIdx])
      startIdx++;
    while (maxOutOfOrder <= array[endIdx])
      endIdx--;
    return vector<int>{startIdx, endIdx};
  }
};
