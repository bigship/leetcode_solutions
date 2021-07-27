// 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
/*
 * Given an array nums, you are allowed to choose one element of nums and change it by any value in one move.
Return the minimum difference between the largest and smallest value of nums after perfoming at most 3 moves.

Example 1:

Input: nums = [5,3,2,4]
Output: 0
Explanation: Change the array [5,3,2,4] to [2,2,2,2].
The difference between the maximum and minimum is 2-2 = 0.
*/

class Solution {
public:
  int minDifference(vector<int>& nums) {
    if (nums.size() <= 4) return 0;
    std::sort(nums.begin(), nums.end());

    int n = nums.size();
    int a = nums[n - 1] - nums[3];     // 把前3个元素变成最大
    int b = nums[n - 2] - nums[2];     // 把前2个以及最后一个元素变成最小
    int c = nums[n - 3] - nums[1];     // 把最后两个以及第一个元素变最小
    int d = nums[n - 4] - nums[0];     // 把最后3个元素都变最小

    return min(a, min(b, min(c, d)));
  }
};
