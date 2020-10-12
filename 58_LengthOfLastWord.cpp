// 58. Length of Last Word
/*
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
 * return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/

class Solution {
public:
  int lengthOfLastWord(string s) {
    if (s.length() == 0) return 0;
    int idx = s.length() - 1;
    int ans = -1;
    while (idx >= 0 && s[idx] == ' ')
      idx--;
    while (idx >= 0 && isalpha(s[idx])) {
      idx--;
      ans++;
    }
    if (ans != -1)
      return ans + 1;   // ans 从-1开始计算的, 最后要加1
    return 0;           // ans == -1, 表示根本没有字符统计过, 返回0
  }
};

