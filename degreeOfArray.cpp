// 697. Degree of an Array

/*
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:

Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.

Example 2:

Input: [1,2,2,3,1,4,2]
Output: 6

Note:
nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.
*/

class Solution {
public:
  int findShortestSubArray(vector<int>& nums) {
    unordered_map<int, tuple<int, int, int>> hash;
    for (int i = 0; i < nums.size(); i++) {
      if (hash.find(nums[i]) != hash.end()) {
        std::get<0>(hash[nums[i]]) += 1;
        std::get<2>(hash[nums[i]]) = i;
      } else {
        hash[nums[i]] = make_tuple(1, i, i);
      }
    }

    int max_degree = 0;
    for (const auto& hashItem : hash) {
      int degree = std::get<0>(hashItem.second);
      if (degree> max_degree) max_degree = degree;
    }

    int min_length = nums.size();
    for (const auto& hashItem : hash) {
      int degree = std::get<0>(hashItem.second);
      if (degree == max_degree) {
        int diff = std::get<2>(hashItem.second) - std::get<1>(hashItem.second) + 1;
        if (diff < min_length) min_length = diff;
      }
    }
  
    return min_length;
  }
}