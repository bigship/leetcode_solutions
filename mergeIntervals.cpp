// 56. Merge Intervals

/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considerred overlapping.

*/

class Solution {
public:
  vector<Interval> merge(vector<Interval>& intervals) {
    if (intervals.empty()) return {}

    std::sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
      return a.start < b.start;
    });

    vector<Interval> ans;
    for (const auto& interval : intervals) {
      if (ans.empty() || interval.start > ans.back().end) {
        ans.push_back(interval);
      } else {
        ans.back().end = max(ans.back().end, interval.end);
      }
    }
    return ans;
  }
};
