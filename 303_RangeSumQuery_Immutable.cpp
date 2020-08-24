// 303. Range Sum Query - Immutable
/*
 * Given an integer array nums, find the sum of the elements between
 * indices i and j (i ≤ j), inclusive.

Example:

Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Constraints:

    You may assume that the array does not change.
    There are many calls to sumRange function.
    0 <= nums.length <= 10^4
    -10^5 <= nums[i] <= 10^5
    0 <= i <= j < nums.length
*/

class NumArray {
public:
  // 利用前缀和, 每次计算sumRange可降为O(1)时间
  NumArray(vector<int>& nums): ptr(nums) {
    int sum = 0;
    if (nums.size() >= 1)
      m[{0, 0}] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (i == 1) {
        sum += (nums[i] + nums[i-1]);
      } else {
        sum += nums[i];
      }
      m[{0, i}] = sum;
    }
  }

  int sumRange(int i, int j) {
    if (m.find({i, j}) != m.end()) return m[{i, j}];
    if (i == j) return ptr[i];
    return m[{0, j}] - m[{0, i - 1}];
  }
};
