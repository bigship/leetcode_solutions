// 659. Split Array into Consecutive Subsequences
/*
 * Given an integer array nums that is sorted in ascending order, return true if and only if
 * you can split it into one or more subsequences such that each subsequence consists of
 * consecutive integers and has a length of at least 3.

Example 1:

Input: nums = [1,2,3,3,4,5]
Output: true
Explanation:
You can split them into two consecutive subsequences :
1, 2, 3
3, 4, 5

Example 2:

Input: nums = [1,2,3,3,4,4,5,5]
Output: true
Explanation:
You can split them into two consecutive subsequences :
1, 2, 3, 4, 5
3, 4, 5

Example 3:

Input: nums = [1,2,3,4,4,5]
Output: false

Constraints:
    1 <= nums.length <= 104
    -1000 <= nums[i] <= 1000
    nums is sorted in an ascending order.
*/

// 思路: 两个hashmap, left和end
// left[i]表示有多少个i还没有放置过
// end[i] 表示有多少个连续的子序列是以i结尾的
//
// 如果遇到不能把数加到已有的连续子序列的结尾, 或者在left中找到了连续的两个数 此时返回false
class Solution {
public:
    bool isPossible(vector<int>& A) {
    unordered_map<int, int> left, end;
    for (int i: A) {
      left[i]++;
    }
    for (int i: A) {
      if (left[i] == 0) continue;
      left[i]--;
      if (end[i - 1] > 0) {
        end[i - 1]--;
        end[i]++;
      } else if (left[i + 1] > 0 && left[i + 2] > 0) {
        left[i + 1]--;
        left[i + 2]--;
        end[i + 2]++;
      } else {
        return false;
      }
    }
    return true;
  }
};

