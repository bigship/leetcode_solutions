// 81. Search In Rotated Sorted Array II
/*
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
   (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

Follow up:
    This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
    Would this affect the run-time complexity? How and why?
*/

class Solution {
public:
  bool search(vector<int>& nums, int target) {
    if (nums.size() == 0) return false;
    if (nums.size() == 1) return nums[0] == target;

    int h = -1, l = -1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < nums[i - 1]) {
        h = i - 1;
        l = i;
        break;
      }
    }
    if (h == -1 && l == -1) {
      return -1 != binarySearch(nums, 0, nums.size() - 1, target);
    }
    if (binarySearch(nums, 0, h, target) == -1) {
      return -1 != binarySearch(nums, l, nums.size() - 1, target)
    }
    return true;
  }
private:
  int binarySearch(vector<int>& nums, int low, int high, int target) {
    while (low <= high) {
      int mid = (high - low ) / 2 + low;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] > target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return -1;
  }
};


class Solution2 {
public:
  bool search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = (right - left) / 2 + left;
      if (nums[mid] == target)
        return mid;

      // 不确定是左区间还是右区间
      if (nums[mid] == nums[left])
        left += 1;
      else if (nums[mid] <= nums[right]) {
        // 右半边是有序的, 如果target在此区间, 则使用二分查找
        if (nums[right] >= target && target > nums[mid]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      } else {
        // 左半边是有序的, 如果target在此区间, 同样使用二分查找
        if (nums[left] <= target && target < nums[mid]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
    }
    return -1;
  }
};


