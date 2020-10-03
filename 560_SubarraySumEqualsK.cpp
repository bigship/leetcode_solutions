// 560. Subarray Sum equals K
/*
 * Given an array of integers and an integer k, you need to find the total number
 * of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2

Constraints:
  The length of the array is in range [1, 20,000].
  The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

// 思路
// 如果前i个数的和记为 sum_i, 前j个数的和记为sum_j, 如果sum_i == sum_j 则说明i和j之间元素的和为0
// 把上述结论扩展到k的情况, 就是sum_i == sum_j - k, 那么i到j之间元素的和就是k了.
// 因此用一个hashmap记录当前求和的结果, 以及对应的出现次数, 当发现sum - k已经存在了, 就更新结果
class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    int cnt = 0, sum = 0;
    unordered_map<int, int> map;    // sum at idx i, the frequence of that sum
    map[0] = 1;                     // Initial state, we don't use any element, so the sum is 0.
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      if (map.find(sum - k) != map.end()) {
        cnt += map[sum - k];
      }
      map[sum]++;
    }
    return cnt;
  }
};

