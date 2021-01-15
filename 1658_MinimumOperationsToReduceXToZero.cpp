// 1658. Minimum Operations to Reduce X to Zero
/*
 * You are given an integer array nums and an integer x. In one operation,
 * you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x.
 * Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it's possible, otherwise, return -1.

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1

Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.

Constraints:

    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^4
    1 <= x <= 10^9
*/

// Solution 1: 由于数组中都是正整数, 可以将问题转换为找出数组中最长的子数组
// 使得子数组的和为totalSum - x
// Time: O(n), Space: O(1)
class Solution {
public:
  int minOperations(vector<int>& nums, int x) {
    int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
    const int n = nums.size();

    int left = 0, right = 0, cur = 0, maxlen = -1;
    for (; right < n; right++) {
      cur += nums[right];
      while (cur > totalSum - x && left <= right) {
        cur -= nums[left];
        left++;
      }
      if (cur == totalSum - x) {
        maxlen = std::max(maxlen, right - left + 1);
      }
    }

    return maxlen != -1 ? n - maxlen : -1;
  }
};

// Solution 2: 由于数组中元素都是正整数, 因此它的前缀和数组和后缀和数组一定是有序的
// 设prefixSum array 为A, suffixSum array为B. 我们要找的就是A[i] + B[j] == x, 且i+j最小
// 由于有可能只需要利用到A[i]或者B[j], 因此可以往A和B中各添加一个0
// 有序数组, 因此可以利用二分查找
// Time: O(nlogn), Space: O(n)
class Solution2 {
public:
  int minOperations(vector<int>& nums, int x) {
    int ans = INT_MAX;
    const int n = nums.size();
    vector<int> prefixSum(n + 1, 0);
    vector<int> suffixSum(n + 1, 0);
    for (int i = 0; i < n; i++) {
      prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
    for (int j = n - 1; j >= 0; j--) {
      suffixSum[j] = nums[j] + suffixSum[j + 1];
    }

    std::reverse(suffixSum.begin(), suffixSum.end());
    for (int i = 0; i < n + 1; i++) {
      int j = binarySearch(suffixSum, x - prefixSum[i]);
      if (j != -1 && i + j <= n) {
        ans = std::min(ans, i + j);
      }
    }

    return ans != INT_MAX ? ans : -1;
  }
private:
  int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = (right - left) / 2 + left;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return -1;
  }
}

