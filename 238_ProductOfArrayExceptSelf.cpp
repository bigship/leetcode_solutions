// 238. Product of Array Except Self
/*
 * Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]

Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    const int len = nums.size();
    vector<int> ans(len, 0);
    vector<int> left(len, 1);
    vector<int> right(len, 1);

    for (int i = 1; i < len; i++) {
      left[i] = nums[i - 1] * left[i - 1];
    }

    for (int j = len - 2; j >= 0; j--) {
      right[j] = nums[j + 1] * right[j + 1];
    }

    for (int i = 0; i < len; i++) {
      ans.push_back(left[i] * right[i]);
    }

    return ans;
  }
};


