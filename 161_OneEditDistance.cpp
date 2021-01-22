// 161. One Edit Distance
/*
 * Given two strings s and t, return true if they are both one edit distance apart, otherwise return false.
   A string s is said to be one distance apart from a string t if you can:

    Insert exactly one character into s to get t.
    Delete exactly one character from s to get t.
    Replace exactly one character of s with a different character to get t.

Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.

Example 2:

Input: s = "", t = ""
Output: false
Explanation: We cannot get t from s by only one step.

Example 3:

Input: s = "a", t = ""
Output: true

Example 4:

Input: s = "", t = "A"
Output: true

Constraints:
    0 <= s.length <= 104
    0 <= t.length <= 104
    s and t consist of lower-case letters, upper-case letters and/or digits.
*/

class Solution {
public:
  bool isOneEditDistance(string s, string t) {
    int len1 = s.length();
    int len2 = t.length();
    if (len1 > len2)
      return isOneEditDistance(t, s);

    // 长度差太多, 无法只编辑一次
    if (len2 - len1 > 1)
      return false;

    for (int i = 0; i < len1; i++) {
      // 首次出现不同的字符
      if (s[i] != t[i]) {
        if (len1 == len2) {
          // 如果长度相同, 则剩下的所有字符都必须相同
          return s.substr(i + 1) == t.substr(i + 1);
        } else {
          // 长度不相同, 则t从i+1开始到结尾的字符必须和s中从i开始的字符一致
          return s.substr(i) == t.substr(i + 1);
        }
      }
    }

    // 没有出现过不同的字符, 则只能是s比t少一个字符
    return len1 + 1 == len2;
  }
};

