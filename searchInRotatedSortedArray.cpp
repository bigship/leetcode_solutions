// 33. Search in Rotated Sorted Array

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

*/

class Solution {
public:
  int search(vector<int>& nums, int target) {
    if (nums.size() == 0) return -1;
    if (nums.size() == 1) return nums[0] == target ? 0 : -1;

    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int middle = (right - left) / 2 + left;
      if (nums[middle] == target) {
        return middle;
      } else if (nums[middle] < nums[left]) {
        if (target > nums[middle] && target <= nums[right]) {
          left = middle + 1;
        } else {
          right = middle - 1;
        }
      } else {
        if (target < nums[middle] && target >= nums[left]) {
          right = middle - 1;
        } else {
          left = middle + 1;
        }
      }
    }
    return -1;
  }
};