// 56. Merge Intervals
/*
 * Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
 * and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Constraints:

    1 <= intervals.length <= 104
    intervals[i].length == 2
    0 <= starti <= endi <= 104
*/
// 写一个helper function 两两合并区间
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    std::sort(intervals.begin(), intervals.end(), [&](vector<int>& inter1, vector<int>& inter2) {
     return inter1[0] < inter2[0];
    });

    if (intervals.size() == 1) {
      res.push_back(intervals[0]);
      return res;
    }

    vector<int> cur = intervals[0];
    for (int i = 1; i < intervals.size(); i++) {
      pair<vector<int>, bool> ret = mergeTwoIntervals(cur, intervals[i]);
      if (ret.second) {
        cur = ret.first;
      } else {
        res.push_back(cur);
        cur = intervals[i];
      }
      if (i == intervals.size() - 1) {
        res.push_back(cur);
      }
    }
    return res;
  }
private:
  std::pair<vector<int>, bool> mergeTwoIntervals(const vector<int>& inter1, const vector<int>& inter2) {
    vector<int> res;
    if (inter1[1] >= inter2[0] && inter1[1] < inter2[1]) {
      return {{inter1[0], inter2[1]}, true};
    }
    if (inter1[1] >= inter2[1]) {
      return {{inter1[0], inter1[1]}, true};
    }
    return {{inter1[0], inter2[0]}, false};
  }
};

