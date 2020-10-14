// 496. Next Greater Element I
/*
 *  You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2.
 *  Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2.
If it does not exist, output -1 for this number.

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.

Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.

Note:

    All elements in nums1 and nums2 are unique.
    The length of both nums1 and nums2 would not exceed 1000.
*/
class Solution {
public:
  // Worst case: O(m * n)
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_map<int, int> map;
    for (int i = 0; i < nums2.size(); i++)
      map[nums2[i]] = i;
    for (int i = 0; i < nums1.size(); i++) {
      bool found = false;
      for (int j = map[nums1[i]]; j < nums2.size(); j++) {
        if (nums2[j] > nums1[i]) {
          ans.push_back(nums2[j]);
          found = true;
        }
      }
      if (!found)
        ans.push_back(-1);
    }
    return ans;
  }

  // Monotonous stack 单调栈
  // Time: O(n + m)
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    std::stack<int> sk;
    unordered_map<int, int> map;
    for (int i = 0; i < nums2.size(); i++) {
      while (!sk.empty() && sk.top() < nums2[i]) {
        int val = sk.top();
        sk.pop();
        map[val] = nums2[i];
      }
      sk.push(nums2[i]);
    }

    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++) {
      if (map.find(nums1[i]) != map.end()) {
        ans.push_back(map[nums1[i]]);
      } else {
        ans.push_back(-1);
      }
    }
    return ans;
  }
};
