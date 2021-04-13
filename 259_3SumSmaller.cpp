// 259. 3Sum smaller
/*
 * Given an array of n integers nums and an integer target,
 * find the number of index triplets i, j, k with 0 <= i < j < k < n that
 * satisfy the condition nums[i] + nums[j] + nums[k] < target.

Follow up: Could you solve it in O(n^2) runtime?

Example 1:

Input: nums = [-2,0,1,3], target = 2
Output: 2
Explanation: Because there are two triplets which sums are less than 2:
[-2,0,1]
[-2,0,3]
Example 2:

Input: nums = [], target = 0
Output: 0
Example 3:

Input: nums = [0], target = 0
Output: 0

Constraints:
n == nums.length
0 <= n <= 300
-100 <= nums[i] <= 100
-100 <= target <= 100
*/

// Time: nlog(n) + n^2  == n^2
class Solution {
public:
  int threeSumSmaller(vector<int>& nums, int target) {
    int ans = 0;
    if (nums.size() < 3) return ans;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
      int low = i + 1, high = nums.size() - 1;
      while (low < high) {
        int sum = nums[i] + nums[low] + nums[high];
        // sum 比target更大, high必须往左移动才有可能出现解
        if (sum >= target) {
          high--;
        } else {
          // nums[i] + nums[low] + nums[high] < target
          // 由于已经排序了, 因此low 到 high之间的所有位置都可以满足
          // 一共会有high - low组解
          // 之后将low向右侧移动, 继续判断可能出现的解
          ans += (high - low);
          low++;
        }
      }
    }
    return ans;
  }
};
