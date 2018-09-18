// 367. Valid Perfect Square

/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true

Example 2:

Input: 14
Output: false

*/

// Binary search
// Note: should use long type, otherwise may overflow

class Solution {
public:
  bool isPerfectSquare(int num) {
    int low = 0, high = num;
    long mid;
    while (low <= high) {
      mid = high - (high - low) / 2;
      if (mid * mid == num) {
        return true;
      } else if (mid * mid > num) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return false;
  }
};
