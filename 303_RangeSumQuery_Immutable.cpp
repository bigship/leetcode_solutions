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
  NumArray(vector<int>& nums) {
    prefixSum = vector<int>(nums.size() + 1, 0);
    for (int i = 1; i < prefixSum.size(); i++) {
      prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    }
  }

  int sumRange(int left, int right) {
    return prefixSum[right + 1] - prefixSum[left];
  }
private:
  vector<int> prefixSum;
};
