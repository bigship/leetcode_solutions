// 169. Majority Element
/*
 * Given an array of size n, find the majority element.
 * The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3

Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

*/

class Solution {
public:
  // Boyer-Moore Voting Algorithm
  int majorityElement(vector<int>& nums) {
    int ans = 0;
    int count = 0;
    for (auto& val : nums) {
      if (count == 0) {
        ans = val;
        count++;
      } else {
        if (ans != val) {
          count--;
        } else {
          count++;
        }
      }
    }
    return ans;
  }
};



