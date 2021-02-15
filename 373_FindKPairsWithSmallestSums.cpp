// 373. Find K Pairs with smallest Sums
/*
 * You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence:
             [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [1,1],[1,1]
Explanation: The first 2 pairs are returned from the sequence:
             [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

Example 3:

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [1,3],[2,3]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
*/

// 扩展时有可能出现重复, 需要引入查重机制
class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> ans;

    auto cmp = [&](pair<int, int>& p1, pair<int, int>& p2) {
      return nums1[p1.first] + nums2[p1.second] >= nums1[p2.first] + nums2[p2.second];
    };
    std::priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
    vector<vector<int>> visited(nums1.size(), vector<int>(nums2.size(), 0));

    if (nums1.empty()|| nums2.empty())
      return ans;

    q.push({0, 0});
    visited[0][0] = 1;

    while (k > 0 && !q.empty()) {
      auto p = q.top();
      q.pop();
      int i = p.first;
      int j = p.second;
      ans.push_back({nums1[i], nums2[j]});

      if (j + 1 < nums2.size() && i < nums1.size()) {
        if (visited[i][j+1] == 0) {
          q.push({i, j + 1});
          visited[i][j+1] = 1;
        }
      }
      if (i + 1 < nums1.size() && j < nums2.size()) {
        if (visited[i+1][j] == 0) {
          q.push({i + 1, j});
          visited[i+1][j] = 1;
        }
      }
      k--;
    }
    return ans;
  }
};

