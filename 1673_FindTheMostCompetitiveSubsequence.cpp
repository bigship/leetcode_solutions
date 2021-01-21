// 1673. Find the Most Competitive Subsequence
/*
 * Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.

An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.

We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first position where a and b differ, subsequence a has a number less than the corresponding number in b. For example, [1,3,4] is more competitive than [1,3,5] because the first position they differ is at the final number, and 4 is less than 5.

Example 1:

Input: nums = [3,5,2,6], k = 2
Output: [2,6]
Explanation: Among the set of every possible subsequence: {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]}, [2,6] is the most competitive.

Example 2:

Input: nums = [2,4,3,3,5,4,9,6], k = 4
Output: [2,3,3,4]

Constraints:
    1 <= nums.length <= 10^5
    0 <= nums[i] <= 10^5
    1 <= k <= nums.length
*/

// 单调栈. 每次入栈前看栈顶元素和当前遍历到的元素, 如果栈顶元素更大就循环pop
// 直到栈顶元素小于等于当前遍历到的元素, 然后再把当前元素入栈
//
// 需要注意的是, 如果当前栈中的元素不足k个, 那么需要看剩下的元素还有没有可能凑足k个
// 如果后面的元素无法满足, 则这个时候是不能pop的. 否则无法凑足k个
class Solution {
public:
  vector<int> mostCompetitive(vector<int>& nums, int k) {
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      while (!ans.empty() && ans.back() > nums[i]) {
        if (ans.size() < k && k - ans.size() > nums.size() - i - 1)
          break;
        ans.pop_back();
      }
      ans.push_back(nums[i]);
    }
    int n = ans.size();
    while (n - k > 0) {
      ans.pop_back();
      n--;
    }
    return ans;
  }
};

