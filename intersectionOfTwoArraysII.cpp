// 350. Intersection of Two Arrays II

/*
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]

Note:

    Each element in the result should appear as many times as it shows in both arrays.
    The result can be in any order.

Follow up:

    What if the given array is already sorted? How would you optimize your algorithm?
    What if nums1's size is small compared to nums2's size? Which algorithm is better?
    What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

*/
class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() == 0 || nums2.size() == 0) return {};
    for (auto& n : nums1) {
      m1[n] += 1;
    }
    for (auto& n : nums2) {
      m2[n] += 1;
    }
    
    vector<int> ans;
    for (auto m : m1.size() < m2.size() ? m1 : m2) {
      int key = m.first;
      for (int i = 0; i < std::min(m1[key], m2[key]); i++) {
        ans.push_back(key);
      }
    }
    return ans;
  }
private:
  unordered_map<int, int> m1;
  unordered_map<int, int> m2;
};
