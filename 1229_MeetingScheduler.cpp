// 1229. Meeting Scheduler
/*
 * Given the availability time slots arrays slots1 and slots2 of two people and a meeting duration duration,
 * return the earliest time slot that works for both of them and is of duration duration.

If there is no common time slot that satisfies the requirements, return an empty array.
The format of a time slot is an array of two elements [start, end] representing an inclusive time range from start to end.

It is guaranteed that no two availability slots of the same person intersect with each other.
That is, for any two time slots [start1, end1] and [start2, end2] of the same person, either start1 > end2 or start2 > end1.

Example 1:

Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 8
Output: [60,68]

Example 2:

Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 12
Output: []
*/

// 求区间交集
// max(a[0], b[0]), min(a[1], b[1])

class Solution {
public:
  vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
    sort(slots1.begin(), slots1.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[0] < b[0];
    });
    sort(slots2.begin(), slots2.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[0] < b[0];
    });

    int i = 0, j = 0;
    while (i < slots1.size() && j < slots2.size()) {
      vector<int> inter = intersectionOf(slots1[i], slots2[j]);
      if (inter[1] - inter[0] >= duration) {
        return {inter[0], inter[0] + duration};
      } else {
        if (inter[1] == slots1[i][1]) {
          i++;
        }
        if (inter[1] == slots2[j][1]) {
          j++;
        }
      }
    }
    return {};
  }
private:
    vector<int> intersectionOf(vector<int>& a, vector<int>& b) {
      return {max(a[0], b[0]), min(a[1], b[1])};
    }
};
