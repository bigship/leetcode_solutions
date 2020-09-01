// 1550. Three Consecutive Odds
/*
 * Given an integer array arr, return true if there are three consecutive odd numbers in the array.
 * Otherwise, return false.

Example 1:

Input: arr = [2,6,4,1]
Output: false
Explanation: There are no three consecutive odds.

Example 2:

Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true
Explanation: [5,7,23] are three consecutive odds.

Constraints:

    1 <= arr.length <= 1000
    1 <= arr[i] <= 1000
*/

class Solution {
public:
  // Solution: 利用stack
  bool threeConsecutiveOdds(vector<int>& arr) {
    std::stack<int> sk;
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] % 2 == 1) {
        sk.push(arr[i]);
        if (sk.size() == 3)
          return true;
      } else {
        if (!sk.empty()) {
          sk.pop();
        }
      }
    }
    return false;
  }

  // Solution: 直接扫一遍, 看有没有连续出现3个odd
  bool threeConsecutiveOdds(vector<int>& arr) {
    if (arr.size() < 3) return false;
    for (int i = 0; i < arr.size() - 2; i++) {
      if (arr[i]%2 == 1 && arr[i+1]%2 == 1 && arr[i+2]%2 == 1)
        return true;
    }
    return false;
  }
};
