// 1784. Check If Binary String Has At Most One Segment of Ones
/*
 *

Given a binary string s without leading zeros, return true if s contains at most one contiguous segment of ones.
Otherwise, return false.

Example 1:

Input: s = "1001"
Output: false
Explanation: The ones do not form a contiguous segment.

Example 2:

Input: s = "110"
Output: true

Constraints:

    1 <= s.length <= 100
    s[i] is either '0' or '1'.
    s[0] is '1'.
*/

class Solution {
public:
  bool checkOnesSegment(string s) {
    bool contiguous = true;
    int i = 0;
    while (i < s.length()) {
      if (s[i] == '1') {
        if (!contiguous) {
          return false;
        } else {
          contiguous = true;
        }
        i++;
      } else {
        contiguous = false;   // we can not meet any more 1s, otherwise it is false
        i++;
      }
    }
    return true;
  }
};


