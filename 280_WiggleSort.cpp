// 280. Wiggle Sort
/*
 * Given an integer array nums, reorder it such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
   You may assume the input array always has a valid answer.

Example 1:

Input: nums = [3,5,2,1,6,4]
Output: [3,5,1,6,2,4]
Explanation: [1,6,2,5,3,4] is also accepted.
Example 2:

Input: nums = [6,6,5,6,3,8]
Output: [6,6,5,6,3,8]


Constraints:

1 <= nums.length <= 5 * 10^4
0 <= nums[i] <= 10^4
It is guaranteed that there will be an answer for the given input nums.
*/

class Solution {
public:
  // 最优解. one pass swap
  // 遍历数组一次, 只要发现当前元素和下一个元素不满足wiggle关系就交换它们
  // 因为如果当前元素比前一个元素大, 与它相邻的下一个元素必须比当前元素要小才满足
  // wiggle关系. 如果发现相邻的下一个元素比当前元素大, 说明它也比前一个元素要大.
  // 因此交换当前元素和下一个元素不会破坏之前的wiggle关系, 交换是安全的.
  //
  void wiggleSort(vector<int>& nums) {
    bool shouldLess = true;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (shouldLess) {
        if (nums[i] > nums[i + 1]) {
          std::swap(nums[i], nums[i+1]);
        }
      } else {
        if (nums[i] < nums[i+1]) {
          std::swap(nums[i], nums[i+1]);
        }
      }
      shouldLess = !shouldLess;
    }
    return ;
  }
};

