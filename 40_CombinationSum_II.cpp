// 40. Combination Sum II
/*
 * Given a collection of candidate numbers (candidates) and a target number (target),
 * find all unique combinations in candidates where the candidate numbers sums to target.
Each number in candidates may only be used once in the combination.

Note:
    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*
*/

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> cur;

    std::function<void(int, int)> dfs = [&](int start, int left) {
      if (left == 0) {
        ans.push_back(cur);
        return ;
      }

      for (int i = start; i < candidates.size(); i++) {
        if (left < candidates[i]) break;
        if (i > start && candidates[i-1] == candidates[i])
          continue;
        cur.push_back(candidates[i]);
        dfs(i+1, left - candidates[i]);
        cur.pop_back();
      }
    }

    dfs(0, target);
    return ans;
  }
};



