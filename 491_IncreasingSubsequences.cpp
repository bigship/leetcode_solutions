// 491. Increasing Subsequences
/*
 * Given an integer array, your task is to find all the different possible increasing
 * subsequences of the given array, and the length of an increasing subsequence should be at least 2.

Example:

Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]

Constraints:

    The length of the given array will not exceed 15.
    The range of integer in the given array is [-100,100].
    The given array may contain duplicates, and two equal integers should also be
    considered as a special case of increasing sequence.
*/

class Solution {
public:
  // 和combination很相似
  // 条件变成当前组合的元素个数必须大于1, 且组合要保持升序(非严格递增, 可以相等)
  // 可以套用backtrack类型题目的模板
  // 1. 定义一个helper function, 参数有一个索引, 从0开始枚举
  // 2. 先写结束条件
  // 3. 循环遍历中递归调用 做出选择
  // 4. 撤销选择
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    set<vector<int>> ans;  // remove duplicate
    vector<int> cur;
    function<void(int, vector<int>&)> dfs = [&](int start, vector<int>& cur) {
      if (cur.size() > 1) ans.insert(cur);
      for (int i = start; i < nums.size(); i++) {
        if (cur.size() == 0 || cur.back() <= nums[i]) {
          cur.push_back();
          dfs(i+1, cur);
          cur.pop_back();
        }
      }
    };

    dfs(0, cur);
    return vector<vector<int>>(ans.begin(), ans.end());
  }
};


