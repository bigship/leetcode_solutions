// 34. Find First and Last Position of Element in Sorted Array

/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int l = 0, h = nums.size() - 1;
    vector<int> ans;
    deque<int> dq;
    while (l <= h) {
      int mid = l + (h - l) / 2;
      if (nums[mid] == target) {
        dq.push_back(mid);
        for (int i = mid - 1; i >= 0; i--) {
          if (nums[i] == target) dq.push_front(i);
        }
        for (int j = mid + 1; j < nums.size(); j++) {
          if (nums[j] == target) dq.push_back(j);
        }
        break;
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        h = mid - 1;
      }
    }
    
    if (dq.size() == 0) {
      return vector<int>{-1, -1};
    } else {
      if (ans.size() == 1) {
        return vector<int>{dq.back(), dq.back()};
      } else {
        return vector<int>{dq.front(), dq.back()};
      }
    }
  }
};

