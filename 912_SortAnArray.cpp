// 912. Sort an Array
/*
 * Given an array of integers nums, sort the array in ascending order.

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]

Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]

Constraints:
    1 <= nums.length <= 50000
    -50000 <= nums[i] <= 50000
*/
// QuickSort template code
class Solution {
public:
  vector<int> sortArray(vecor<int>& nums) {
    sortArray(nums, 0, nums.size() - 1);
    return nums;
  }
private:
  void sortArray(vector<int>& nums, int start, int end) {
    if (start >= end) return ;
    int l = start, r = end;
    int pivot = nums[(r - l) / 2 + l];  // pick the mid value as pivot
    while (l <= r) {
      while (l <= r && pivot > nums[l]) {
        l++;
      }
      while (l <= r && pivot < nums[r]) {
        r--;
      }
      if (l <= r)
        std::swap(nums[l++], nums[r--]);
    }
    sortArray(nums, start, r);
    sortArray(nums, l, end);
  }
};

