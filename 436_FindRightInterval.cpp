// 436. Find Right Interval
/*
 * You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.
   The right interval for an interval i is an interval j such that startj >= endi and startj is minimized.

Return an array of right interval indices for each interval i.
If no right interval exists for interval i, then put -1 at index i.

Example 1:

Input: intervals = [[1,2]]
Output: [-1]
Explanation: There is only one interval in the collection, so it outputs -1.
*/

// 使用平衡二叉树保存开始区间所属的下标. (每个区间的开始值是唯一的, 没有重复)
// 在平衡二叉树上对区间的结束值做二分查找, 找到最小的不小于区间结束值的位置即可
// Time: O(n), Space: O(n)
class Solution {
public:
  vector<int> findRightInterval(vector<vector<int>>& intervals) {
    vector<int> ans(intervals.size(), -1);
    std::map<int, int> idxmap;

    for (int i = 0; i < intervals.size(); i++) {
      idxmap[intervals[i][0]] = i;
    }

    for (int i = 0; i < intervals.size(); i++) {
      int target = intervals[i][1];
      auto it = idxmap.lower_bound(target);
      if (it == idxmap.end()) {
        ans[i] = -1;
      } else {
        ans[i] = it->second;
      }
    }
    return ans;
  }
};
