// 698. Partition to K Equal Sum Subsets
/*
 * Given an array of integers nums and a positive integer k,
 * find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:

Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

Note:

    1 <= k <= len(nums) <= 16.
    0 < nums[i] < 10000.
*/
// Backtracking
// 可以先计算出每一组的和为多少 记为subSum
// 将数组排序, 从最大的开始取
// 如果数组中最大的值比subSum还要大, 说明无法划分出来 (数组中都是正整数)
// 如果数组中有值恰好等于subSum, 说明要单独分成一组. k--
// 剩下的数就要划分到当前k组中去
//
// 此时递归尝试将剩余的数加入到k组中去. 如果可以加入, index--
// 如果index < 0 表示所有数全部划分完毕, 此时返回true表示可以划分成功了
// 开一个长度为k的数组表示划分的组group, 数组元素就表示该组的和
// 能否加入的条件就是subset[i] + selected <= target
// 注意需要backtrack.
class Solution {
public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) return false;

    int subSum = sum / k;
    std::sort(nums.begin(), nums.end());

    int start = nums.size() - 1;
    if (nums[start] > subSum) return false;

    while (start >= 0 && nums[start] == subSum) {
      start--;
      k--;
    }

    vector<int> subsets = vector<int>(k, 0);
    return partition(subsets, nums, start, subSum);
  }
private:
  bool partition(vector<int> subset, vector<int>& nums, int index, int target) {
    if (index < 0) return true;

    int selected = nums[index];
    for (int i = 0; i < subset.size(); i++) {
      if (subset[i] + selected <= target) {
        subset[i] += selected;
        if (partition(subset, nums, index - 1, target)) {
          return true;
        }
        subset[i] -= selected;
      }
    }
    return false;
  }
};

