// 90. Subsets II
/*
 * Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:

Input: nums = [0]
Output: [[],[0]]

Constraints:
    1 <= nums.length <= 10
    -10 <= nums[i] <= 10
*/
// 求所有解, 一般就是用DFS + 回溯
// 由于要去重复, 考虑先将数组排序
class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    std::sort(nums.begin(), nums.end());
    vector<int> cur;
    dfs(nums, 0, cur, ans);
    return ans;
  }
private:
  void dfs(vector<int>& nums, int start, vector<int>& cur, vector<vector<int>>& ans) {
    ans.push_back(cur);
    for (int i = start; i < nums.size(); i++) {
      // 去重条件
      if (i > start && nums[i] == nums[i - 1])
        continue;
      cur.push_back(nums[i]);
      dfs(nums, i + 1, cur, ans);
      cur.pop_back();
    }
  }
};

