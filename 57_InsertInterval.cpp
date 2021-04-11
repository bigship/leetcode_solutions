// 57. Insert Interval
/*
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
   You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
Example 3:

Input: intervals = [], newInterval = [5,7]
Output: [[5,7]]
Example 4:

Input: intervals = [[1,5]], newInterval = [2,3]
Output: [[1,5]]
Example 5:

Input: intervals = [[1,5]], newInterval = [2,7]
Output: [[1,7]]

Constraints:

0 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= intervals[i][0] <= intervals[i][1] <= 10^5
intervals is sorted by intervals[i][0] in ascending order.
newInterval.length == 2
0 <= newInterval[0] <= newInterval[1] <= 10^5
*/

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    vector<int> cur = newInterval;
    if (intervals.empty()) {
      ans.push_back(newInterval);
      return ans;
    }

    for (int i = 0; i < intervals.size(); i++) {
      vector<int> res = mergeTwoIntervals(cur, intervals[i]);
      if (res[0] == -1 || res[1] == -1) {
        if (i == intervals.size() - 1) {
          if (cur[0] < intervals[i][0]) {
            ans.push_back(cur);
            ans.push_back(intervals[i]);
          } else {
            ans.push_back(intervals[i]);
            ans.push_back(cur);
          }
        } else {
          if (cur[0] > intervals[i][0]) {
            ans.push_back(intervals[i]);
          } else {
            ans.push_back(cur);
            cur = intervals[i];
          }
        }
      } else {
        cur = res;
        if (i == intervals.size() - 1) {
          ans.push_back(cur);
        }
      }
    }
    return ans;
  }
private:
  // 判断是否overlap. 如果有overlap就merge, merge结果是取并集min(inter1[0], inter2[0]), max(inter1[1], inter2[1])
  vector<int> mergeTwoIntervals(const vector<int>& inter1, const vector<int>& inter2) {
    int s1 = max(inter1[0], inter2[0]);
    int e1 = min(inter1[1], inter2[1]);
    if (s1 > e1) return {-1, -1};
    return {min(inter1[0], inter2[0]), max(inter1[1], inter2[1])};
  }
};
