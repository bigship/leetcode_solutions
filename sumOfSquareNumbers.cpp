// 633. Sum of Square Numbers

/*
 Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:

Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:

Input: 3
Output: False
*/

class Solution {
public:
  bool judgeSquareSum(int c) {
    bool found = false;
    vector<int> vec(c/2, 0);
    for (int i = 0; i < vec.size(); i++) {
      vec[i] = i+1;
    }

    for (int i = 0; i < vec.size(); i++) {
      int target = c - (vec[i] * vec[i]);
      found = findValue(vec, 0, vec.size() - 1, target);
      if (found) {
        break;
      } else {
        continue;
      }
    }
    return found;
  }
private:
  bool findValue(vector<int>& vec, int l, int h, int target) {
    int left = l, right = h;
    int mid;
    while (left <= right) {
      mid = right - (right - left) / 2;
      if (vec[mid] * vec[mid] == target) {
        return true;
      } else if (vec[mid] * vec[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return false;
  }
};
