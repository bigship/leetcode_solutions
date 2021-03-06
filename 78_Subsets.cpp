// 78. Subsets
/*
 * Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
// m个数中取n个的组合
// dfs + backtracking
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> cur;
    // 全部不取, 到全部取
    for (int i = 0; i <= nums.size(); ++i) {
      dfs(nums, i, 0, cur, ans);
    }
    return ans;
  }

private:
  void dfs(const vector<int>& nums, int n, int s, vector<int>& cur, vector<vector<int>>& ans) {
    // 取满了, 添加答案返回
    if (n == cur.size()) {
      ans.push_back(cur);
      return ;
    }
    // 从s开始取
    // 回溯的标准模式
    for (int i = s; i < nums.size(); ++i) {
      cur.push_back(nums[i]);  // 做出选择
      dfs(nums, n, i+1, cur, ans);  // 递归
      cur.pop_back();  // 撤销选择
    }
  }
};

class Solution {
public:
  // 递归做法
  // subset([1,2,3]) = subset([1, 2]) + [A[i].add(3) for i = 1 .. len(A)]
  vector<vector<int>> subsets(vector<int>& nums) {
    if (nums.empty()) return {{}};

    // 取出最后一个元素
    int n = nums.back();
    nums.pop_back();

    // 先递归算出前面元素的所有子集
    vector<vector<int>> res = subsets(nums);

    int size = res.size();
    for (int i = 0; i < size; i++) {
      res.push_back(res[i]);
      res.back().push_back(n);
    }
    return res;
  }
};
