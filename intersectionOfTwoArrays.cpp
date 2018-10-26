// 349. Intersection of Two Arrays

/*
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]

Note:

    Each element in the result must be unique.
    The result can be in any order.
*/

class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, bool> m1;
    unordered_map<int, bool> m2;
    for (auto& n : nums1) {
      if (m1.find(n) == m1.end()) m1[n] = true;
    }
    for (auto& n : nums2) {
      if (m2.find(n) == m2.end()) m2[n] = true;
    }
    
    vector<int> ans;
    for (auto& item : m1) {
      if (m2.find(item.first) != m2.end()) ans.push_back(item.first);
    }
    return ans;
  }
};