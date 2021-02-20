// 253. Meeting Rooms II
/*
 * Given an array of meeting time intervals intervals where intervals[i] = [starti, endi],
 * return the minimum number of conference rooms required.

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2

Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1

Constraints:
    1 <= intervals.length <= 10^4
    0 <= starti < endi <= 10^6
*/

// 先按会议的开始时间升序排序
// 构建小顶堆, 先保存第一场会议结束时的时间
// 从第二个会议开始看, 检查会议的开始时间是否比堆顶的元素大
// 如果是, 表示可以复用这个会议室, 于是pop出堆顶. 再将当前会议的结束时间加入堆中(表示当前占用这间会议室)
// 遍历结束后, 堆的size就是答案
class Solution {
public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(), [&](vector<int>& inter1, vector<int>& inter2) {
      return inter1[0] < inter2[0];
    });

    priority_queue<int, vector<int>, std::greater<int>> minHeap;
    minHeap.push(intervals[0][1]);

    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] >= minHeap.top()) {
        minHeap.pop();
      }
      minHeap.push(intervals[i][1]);
    }
    return minHeap.size();
  }
};



