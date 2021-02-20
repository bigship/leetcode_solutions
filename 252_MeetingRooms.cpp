// 252. Meeting Rooms
/*
 * Given an array of meeting time intervals where intervals[i] = [starti, endi],
 * determine if a person could attend all meetings.

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: false

Example 2:

Input: intervals = [[7,10],[2,4]]
Output: true

Constraints:

    0 <= intervals.length <= 104
    intervals[i].length == 2
    0 <= starti < endi <= 106
*/

// Brute force. O(n^2)
class Solution {
public:
  bool canAttendMeetings(vector<vector<int>>& intervals) {
    if (intervals.empty())
      return true;
    for (int i = 0; i < intervals.size(); i++) {
      for (int j = i + 1; j < intervals.size(); j++) {
        if (hasOverlap(intervals[i], intervals[j])) {
          return false;
        }
      }
    }
    return true;
  }
private:
  bool hasOverlap(vector<int>& inter1, vector<int>& inter2) {
    if (inter1[1] <= inter2[0] || inter2[1] <= inter1[0])
      return false;
    return true;
  }
};

// 先根据会议的开始时间进行升序排序
// 然后遍历一次数组, 如果发现前面会议的结束时间 > 后面会议的开始时间
// 则返回false
// 如果全部遍历完了, 表示可以全部参加, 返回true
// Time: O(nlogn)
class Solution2 {
public:
  bool canAttendMeetnigs(vector<vector<int>>& intervals) {
    if (intervals.empty() || intervals.size() == 1)
      return true;

    std::sort(intervals.begin(), intervals.end(), [&](vector<int>& inter1, vector<int>& inter2){
      return inter1[0] <= inter2[0];
    });

    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i - 1][1] > intervals[i][0])
        return false;
    }
    return true;
  }
};



